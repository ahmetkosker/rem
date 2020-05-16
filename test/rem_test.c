#include <stdio.h>
#include "../src/rem.c"
#define TEST_FILE "/home/ahmet/grep.txt"

int main()
{
    if (search(fopen(TEST_FILE, "r"), "ahmet") != 1)
    {
        printf("Test failed:Ahmet'i bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "mehmet") != 0)
    {
        printf("Test succesful:mehmet bulundu.\n");
        return 1;
    }
    if (search(fopen(TEST_FILE, "r"), "sagopa") != 1)
    {
        printf("Test failed:sagopayı bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "man") != 1)
    {
        printf("Test failed:akmanı bulamadı.\n");
        return -1;
    }
    if (search(fopen(TEST_FILE, "r"), "tuvaletkagidi") != 0)
    {
        printf("Test succesful:tuvaletkagidi bulundu.\n");
        return 1;
    }
    if (search(fopen(TEST_FILE, "r"), "rak ") != 1)
    {
        printf("Test failed:rak  bulunmadı.\n");
        return -1;
    }
    printf("All tests succesful.\n");
    return 0;
}
