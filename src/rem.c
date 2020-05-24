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
    FILE *f1;
    f1 = fopen("/home/ahmet/grep.txt", "r");
    while (!feof(f1))
    {
        character1 = fgetc(f1);
        z++;
    }
    fclose(f1);
    int sum = 0;
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
            temp = j - (length + 11);
            if (temp >= 10 && z - j >= 10)
            {
                FILE *fp;
                fp = fopen("/home/ahmet/grep.txt", "r");
                char charr;
                for (sum; sum < temp; sum++)
                    charr = fgetc(fp);
                for (sum; sum < j + 9; sum++)
                {
                    charr = fgetc(fp);
                    printf("%c", charr);
                }
                fclose(fp);
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
