#include <stdio.h>
#include <string.h>
unsigned int match_in_file(FILE *f, char *regex)
{
    unsigned int count = 0;
    unsigned int where = 0;
    size_t regex_len = strlen(regex);
    char next_char;
    unsigned int automata_failed = 0;
    unsigned int state = 0;
    unsigned int i = 0;
    int temp = 0;
    int line_number = 1;
    int iter = 0;
    int temp1 = 0;

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
                break;
            }
        }
        if (state == regex_len) //Kelime bulunduysa.
        {
            i = 0;
            printf("\e[94;1m%d\e[0m ", line_number);
            fseek(f, -temp, SEEK_CUR);
            iter = temp - regex_len;
            temp1 = iter;
            while (next_char != '\n' && next_char != '\0')
            {
                if (i < iter)
                {
                    next_char = fgetc(f);
                    printf("%c", next_char);
                    i++;
                }
                else if (temp1 < temp)
                {
                    next_char = fgetc(f);
                    printf("\e[32;1m%c\e[0m", next_char);
                    temp1++;
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
