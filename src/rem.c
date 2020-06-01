#include <stdio.h>
#include <string.h>

int search(FILE *f, char *word)
{
    int state = 0;
    int length = strlen(word);
    int i = 0;
    char character;
    int count = 0;
    int x = 0;
    while (!feof(f)) //Dosya bitene kadar.
    {
        if (x) //Yeni karakter okumuyoruz.
            x = 0;
        else
        {
            character = fgetc(f); //Karakter okunuyor.
        }
        for (i = 0; i < length; i++)
        {
            if (state == i) //En son kaldığımız harfe geliyoruz.
            {
                if (word[i] == character) //Okunan karakter duruma bağlı harfe eşitse.
                {
                    state = i + 1; //Bir sonraki harfe geçiyoruz.
                }
                else
                {
                    if (state != 0) //Arka arkaya gelen aynı harfler için otomatının patlamasına karşı bunu yapıyoruz.
                        x = 1;
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
