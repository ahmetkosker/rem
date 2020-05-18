#include <stdio.h>
#include <string.h>

int search(FILE *f, char *word)
{
    int state = 0;
    int length = strlen(word);
    int i = 0;
    char character;
    int count = 0;
    int temp;
    while (!feof(f))
    {
        character = fgetc(f);

        if (word[0] == character && (state == 0 || state == 1))
        {
            state = 1;
        }
        else
        {
            for (i = 1; i < length; i++)
            {
                if (state == i)
                {
                    if (word[i] == character)
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
            count++;
            temp = state;
            state = 0;
        }
    }
    if (temp == length)
    {
        if (count != 1)
            printf("There are %d\n", count);
        else
            printf("There is %d\n", count);
    }
    else
        printf("There is none\n");

    return temp == length;
}
