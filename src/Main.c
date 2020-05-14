#include <stdio.h>

int main()
{
    int state = 0;
    int length = 0;
    int i = 0;
    char a[100];
    FILE *f;
    length = i;
    i = 0;
    f = fopen("/home/ahmet/grep.txt", "r");
    fscanf(f, "%s", a);
    printf("%s", a[0]);

    return 0;
}