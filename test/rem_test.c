#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "src/rem.c"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "count") != 3)
    {
        printf("Test failed:3 tane count bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "regex") != 6)
    {
        printf("Test failed:6 tane regex bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "while") != 2)
    {
        printf("Test failed:2 tane while bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "=") != 26)
    {
        printf("Test failed:26 tane = bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "automata") != 5)
    {
        printf("Test failed:5 tane automata bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "if") != 6)
    {
        printf("Test failed:6 tane if bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "else") != 2)
    {
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "include") != 2)
    {
        printf("Test failed:2 tane include bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
