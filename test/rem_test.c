#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "src/rem.c"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "automata_failed") != 4)
    {
        printf("Test failed:4 tane automata failed bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "state") != 7)
    {
        printf("Test failed:7 tane state bulunmadı.\n");
        return -1;
    }

    if (match_in_file(fopen(TEST_FILE, "r"), "regex_len") != 3)
    {
        printf("Test failed:3 tane regex_len bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "1") != 2)
    {
        printf("Test failed:2 tane 1 bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "+") != 5)
    {
        printf("Test failed:5 tane + bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
