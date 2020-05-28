#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "/home/ahmet/grep.txt"

int main()
{

    if (search(fopen(TEST_FILE, "r"), "ahmet") == 0)
    {
        printf("Test failed:Ahmet'i bulamadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
