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
    i = 1;
    int j;
    f = fopen("/home/ahmet/grep.txt", "r");

    while (!feof(f))
    {
        character = fgetc(f);
        i = 1;
        if (word[0] == character)
        {
            state = 1;
        }
        else
        {
            for (i; i < length; i++)
            {
                if (state == i)
                {
                    if (word[i] = character)
                    {
                        state = i + 1;
                    }
                    else
                    {
                        state = 0;
                    }
                    break;
                }
            }
        }
        if (state == length)
        {
            printf("Found");
            break;
        }
        /*character = fgetc(f);
        if (word[0] == character)
            state = 1;
        else if (state == 1)
        {
            if (word[1] == character)
                state = 2;
            else
                state = 0;
        }
        else if (state == 2)
        {
            if (word[2] == character)
                state = 3;
            else
                state = 0;
        }
        else if (state == 3)
        {
            if (word[3] == character)
                state = 4;
            else
                state = 0;
        }
        else if (state == 4)
        {
            if (word[4] == character)
                state = 5;
            else
                state = 0;
        }
        if (state == 5)
        {
            printf("Found");
            break;
        }
    }
    if (state == 0)
        printf("There is not");*/
    }
}

int main()
{
    char dizi[10];
    scanf("%s", dizi);
    search(dizi);
    return 0;
}