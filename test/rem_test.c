#include <stdio.h>
#include "../src/rem.c"

int main()
{
    if (search(fopen("/home/ahmet/grep.txt", "r"), "ahmet") != 1)
    {
        printf("Test failed:Ahmet'i bulamadı.");
        return -1;
    }
    if (search(fopen("/home/ahmet/grep.txt", "r"), "mehmet") != 0)
    {
        printf("Test succesful:mehmet bulundu.");
        return 1;
    }
    if (search(fopen("/home/ahmet/grep.txt", "r"), "sagopa") != 1)
    {
        printf("Test failed:sagopayı bulamadı.");
        return -1;
    }
    if (search(fopen("/home/ahmet/grep.txt", "r"), "akman") != 1)
    {
        printf("Test failed:akmanı bulamadı.");
        return -1;
    }
    if (search(fopen("/home/ahmet/grep.txt", "r"), "tuvaletkagidi") != 0)
    {
        printf("Test succesful:tuvaletkagidi bulundu.");
        return 1;
    }
    if (search(fopen("/home/ahmet/grep.txt", "r"), "tarrak ") != 1)
    {
        printf("Test failed:tarrak  bulunmadı.");
        return -1;
    }
    printf("All tests succesful");
    return 0;
}
