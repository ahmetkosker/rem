#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rem.h"
#include "options.h"

int match_in_file(char *filepath, char *regex, unsigned char flags)
{
    FILE *f = fopen(filepath, "r");
    unsigned int count = 0;
    unsigned int where = 0;
    size_t regex_len = strlen(regex);
    char next_char;
    if (isflag(flags, ENABLE_WORD))
    {
				char *temp = malloc(regex_len + 3);
				temp[0] = ' ';
				int i;
				for(i = 0; i < regex_len; i++)
					temp[i+1] = regex[i];
				temp[regex_len + 1] = ' ';
				temp[regex_len + 2] = 0;
				regex = temp;
				regex_len += 2;
    }
    int temp_char = 0;
    unsigned int automata_failed = 0;
    unsigned int state = 0;
    unsigned int i = 0;
    int temp = 0 ;
    unsigned int line_number = 1;
    unsigned int iter = 0;
    unsigned int sum = 0;
    unsigned char flag;

    while (!feof(f)) //Dosya bitene kadar.
    {
        if (automata_failed) //Yeni karakter okumuyoruz.
            automata_failed = 0;
        else
        {
            next_char = fgetc(f); //Karakter okunuyor.
            where++;
            temp++;
            if (next_char == '\n')
            {
                temp = 0;
                line_number++;
            }
        }
        for (i = 0; i < regex_len; i++)
        {
            if (state == i) //En son kaldığımız harfe geliyoruz.
            {
                if (!isflag(flags, ENABLE_CASE_SENSITIVE))
                {
                    if (regex[i] <= 90 && regex[i] >= 65)
                        temp_char = regex[i] + 32;
                    else if (regex[i] <= 122 && regex[i] >= 97)
                        temp_char = regex[i] - 32;
                    if (next_char == regex[i] || temp_char == next_char) //Okunan karakter duruma bağlı harfe eşitse.
                    {
                        state = i + 1; //Bir sonraki harfe geçiyoruz.
                    }
                    else
                    {
                        if (state != 0) //Arka arkaya gelen aynı harfler için automata'nın patlamasına karşı bunu yapıyoruz.
                            automata_failed = 1;
                        state = 0;
                    }
                }
                else
                {
                    if (next_char == regex[i]) //Okunan karakter duruma bağlı harfe eşitse.
                    {
                        state = i + 1; //Bir sonraki harfe geçiyoruz.
                    }
                    else
                    {
                        if (state != 0) //Arka arkaya gelen aynı harfler için automata'nın patlamasına karşı bunu yapıyoruz.
                            automata_failed = 1;
                        state = 0;
                    }
                }
                break;
            }
        }
        if (state == regex_len) //Kelime bulunduysa.
        {
            i = 0;
            if (isflag(flags, ENABLE_LINE_NUMBER))
            {
                if (isflag(flags, ENABLE_COLOR))
                    printf("\e[94;1m%d\e[0m\t", line_number);
                else
                    printf("%d  ", line_number);
            }
            fseek(f, -temp, SEEK_CUR);
            while (next_char != '\n')
            {
                if (i == (temp - regex_len))
                {
                    if (isflag(flags, ENABLE_COLOR))
                        printf("\e[32;1m");
                }
                if (i == temp)
                {
                    if (isflag(flags, ENABLE_COLOR))
                        printf("\e[0m");
                }
                next_char = fgetc(f);
                if (feof(f))
                {
                    printf("\n");
                    break;
                }
                printf("%c", next_char);
                i++;
            }
            fseek(f, where, SEEK_SET);
            count++;
            state = 0;
        }
    }
		free(regex);
    fclose(f);
    return count;
}
