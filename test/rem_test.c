#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "test/resources/example.txt"

int main()
{

    if (match_in_file(fopen(TEST_FILE, "r"), "information", case_insensitive) != 8)
    {
        printf("Test failed:4 tane information bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "also", case_insensitive) != 7)
    {
        printf("Test failed:7 tane also bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "free", case_sensitive) != 16)
    {
        printf("Test failed:16 tane free bulunmadı.\n");
        return -1;
    }
    if (match_in_file(fopen(TEST_FILE, "r"), "the", case_insensitive) != 435)
    {
        printf("Test failed:435 tane the bulunmadı.\n");
        return -1;
    }

    printf("All tests succesful.\n");
    return 0;
}
