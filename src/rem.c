#include <stdio.h>
#include <string.h>

int search(FILE *f, char *word)
{
    int state = 0;
    int length = strlen(word);
    int i = 0;
    char character;
    while (!feof(f))
    {
        character = fgetc(f);

        if (word[0] == character)
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
            break;
    }
    return state == length;
}
