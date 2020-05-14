#include <stdio.h>

void search(char word[100])
{
    int state = 0;
    int length = 0;
    int i = 0;
    char character;
    FILE *f;
    while (word[i] != '\0')
        i++;
    length = i;
    i = 0;
    int j;
    f = fopen("/home/ahmet/grep.txt", "r");
    character = fgetc(f);
    if (word[0] == character)
    {
        state = 1;
        i++;
    }
    while (!feof(f))
    {
        character = fgetc(f);
        for (j = 0; j < length; j++)
        {
            if (state == j)
            {
                if (word[i] == character)
                {
                    state = j + 1;
                    if (state == length)
                    {
                        printf("Found");
                        break;
                    }
                }
                else
                {
                    state = 0;
                }
            }
        }
        i++;
    }
}

int main()
{
    char dizi[10];
    scanf("%s", dizi);
    search(dizi);
    return 0;
}