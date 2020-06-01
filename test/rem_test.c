#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "/home/ahmet/grep.txt"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "ahmet") != 3)
    {
        printf("Test failed:3 ahmet tane bulamadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "akman") != 1)
    {
        printf("Test failed:1 akman tane bulamadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "metallica") != 2)
    {
        printf("Test failed:2 metallica tane bulamadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "duvar") != 0)
    {
        printf("Test failed:duvar buldu.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
