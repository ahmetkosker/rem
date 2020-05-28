#include <stdio.h>
#include <string.h>

int search(FILE *f, char *word)
{
    int state = 0;
    int length = strlen(word);
    int i = 0;
    int j = 0;
    int z = 0;
    char character;
    char character1;
    int count = 0;
    int x = 0;
    int temp = 0;
    while (!feof(f))
    {
        character1 = fgetc(f);
        z++;
    }
    int sum = 0;
    fseek(f, 0, SEEK_SET);
    while (!feof(f))
    {
        if (x)
            x = 0;
        else
        {
            character = fgetc(f);
            j++;
        }
        if (state == length)
        {
            count++;
            if (j - (length + 11) > 0 && z - j > 10)
            {
                fseek(f, j - (length + 11), SEEK_SET);
                for (sum; sum < (length + 20); sum++)
                {
                    character1 = fgetc(f);
                    printf("%c", character1);
                }
            }
            else
            {
                int a = 0;
                while ((word[a]) != '\0')
                {
                    printf("%c", word[a]);
                    a++;
                }
            }
            temp = state;
            state = 0;
        }

        for (i = 0; i < length; i++)
        {
            if (state == i)
            {
                if (word[i] == character)
                {
                    state = i + 1;
                }
                else
                {
                    if (state != 0)
                        x = 1;
                    state = 0;
                }
                break;
            }
        }
    }

    if (temp == length)
    {
        if (count != 1)
            printf(" There are %d\n", count);
        else
            printf(" There is %d\n", count);
    }
    else
        printf("There is none\n");

    return temp == length;
}
