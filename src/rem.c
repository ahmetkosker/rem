#include <stdio.h>
#include <string.h>
unsigned int match_in_file(FILE *f, char *regex, unsigned int case_sensitive)
{
    unsigned int count = 0;
    unsigned int where = 0;
    size_t regex_len = strlen(regex);
    char next_char;
    int temp_char = 0;
    unsigned int automata_failed = 0;
    unsigned int state = 0;
    unsigned int i = 0;
    unsigned int temp = 0;
    unsigned int line_number = 1;
    unsigned int iter = 0;
    unsigned int sum = 0;

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
                if (case_sensitive == 0)
                {
                    if (next_char <= 90 && next_char >= 65)
                        temp_char = next_char + 32;
                    else if (next_char <= 122 && next_char >= 97)
                        temp_char = next_char - 32;
                    if (regex[i] == next_char || regex[i] == temp_char) //Okunan karakter duruma bağlı harfe eşitse.
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
                    if (regex[i] == next_char) //Okunan karakter duruma bağlı harfe eşitse.
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
            int tempo = temp;
            printf("\e[94;1m%d\e[0m\t", line_number);
            fseek(f, -tempo, SEEK_CUR);
            iter = temp - regex_len;
            sum = iter;
            while (next_char != '\n' && next_char != '\0')
            {
                if (i < iter)
                {
                    next_char = fgetc(f);
                    printf("%c", next_char);
                    i++;
                }
                else if (sum < temp)
                {
                    if (sum == iter)
                    {
                        next_char = fgetc(f);
                        printf("\e[32;1m%c", next_char);
                        sum++;
                    }
                    else if (sum == (temp - 1))
                    {
                        next_char = fgetc(f);
                        printf("%c", next_char);
                        next_char = fgetc(f);
                        printf("\e[0m%c", next_char);
                        sum = sum + 2;
                    }
                    else
                    {
                        next_char = fgetc(f);
                        printf("%c", next_char);
                        sum++;
                    }
                }
                else
                {
                    next_char = fgetc(f);
                    printf("%c", next_char);
                }
            }
            fseek(f, where, SEEK_SET);
            count++;
            state = 0;
        }
    }
    return count;
}
