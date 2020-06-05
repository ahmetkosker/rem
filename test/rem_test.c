#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "src/rem.c"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "count") != 3)
    {
        printf("Test failed:2 tane count bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "regex") != 6)
    {
        printf("Test failed:6 tane regex bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "while") != 3)
    {
        printf("Test failed:3 tane while bulunmadı.\n");
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
    if (match_in_file(fopen(TEST_FILE, "r"), "if") != 5)
    {
        printf("Test failed:5 tane if bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "else") != 2)
    {
        printf("Test failed:2 tane else bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
