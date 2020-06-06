#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "test/resources/example.txt"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "information") != 4)
    {
        printf("Test failed:4 tane information bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "also") != 6)
    {
        printf("Test failed:6 tane also bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "free") != 16)
    {
        printf("Test failed:16 tane free bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
