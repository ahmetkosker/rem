#include <stdio.h>
#include <string.h>

unsigned int match_in_file(FILE *f, char *regex)
{
    unsigned int state = 0;
    size_t length = strlen(regex);
    unsigned int i = 0;
    char character;
    unsigned int count = 0;
    unsigned int automata_failed = 0;
    while (!feof(f)) //Dosya bitene kadar.
    {
        if (automata_failed) //Yeni karakter okumuyoruz.
            automata_failed = 0;
        else
        {
            character = fgetc(f); //Karakter okunuyor.
        }
        for (i = 0; i < length; i++)
        {
            if (state == i) //En son kaldığımız harfe geliyoruz.
            {
                if (regex[i] == character) //Okunan karakter duruma bağlı harfe eşitse.
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
        if (state == length) //Kelime bulunduysa.
        {
            count++;
            state = 0;
        }
    }
    return count;
}
