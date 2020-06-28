#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rem.h"
#include "options.h"
#include "int_list.h"

int match_in_file(char *filepath, char *regex, unsigned char flags)
{
    FILE *f = fopen(filepath, "r");
    int_n *list = NULL;
    unsigned int count = 0;
    unsigned int where = 0;
    size_t regex_len = strlen(regex);
    char next_char;
    if (isflag(flags, ENABLE_WORD))
    {
        char *temp = malloc(regex_len + 3);
        temp[0] = ' ';
        int i;
        for (i = 0; i < regex_len; i++)
            temp[i + 1] = regex[i];
        temp[regex_len + 1] = ' ';
        temp[regex_len + 2] = 0;
        regex = temp;
        regex_len += 2;
    }
    int temp_char = 0;
    unsigned int automata_failed = 0;
    unsigned int state = 0;
    unsigned int i = 0;
    int temp = 0;
    int temp_line_number = 0;
    unsigned int line_number = 0;
    unsigned int iter = 0;
    unsigned int sum = 0;
    unsigned char flag;
    unsigned int state_line_number = 1;

    while (!feof(f)) //Dosya bitene kadar.
    {
        if (automata_failed) //Yeni karakter okumuyoruz.
            automata_failed = 0;
        else
        {
            next_char = fgetc(f); //Karakter okunuyor.
            where++;
            temp++;
            if (next_char == '\n')
            {
                temp = 0;
                line_number++;
            }
        }
        for (i = 0; i < regex_len; i++)
        {
            if (state == i) //En son kaldığımız harfe geliyoruz.
            {
                if (!isflag(flags, ENABLE_CASE_SENSITIVE))
                {
                    if (regex[i] <= 90 && regex[i] >= 65)
                        temp_char = regex[i] + 32;
                    else if (regex[i] <= 122 && regex[i] >= 97)
                        temp_char = regex[i] - 32;
                    if (next_char == regex[i] || temp_char == next_char) //Okunan karakter duruma bağlı harfe eşitse.
                    {
                        state = i + 1; //Bir sonraki harfe geçiyoruz.
                    }
                    else
                    {
                        if (state != 0) //Arka arkaya gelen aynı harfler için automata'nın patlamasına karşı bunu yapıyoruz.
                            automata_failed = 1;
                        state = 0;
                    }
                }
                else
                {
                    if (next_char == regex[i]) //Okunan karakter duruma bağlı harfe eşitse.
                    {
                        state = i + 1; //Bir sonraki harfe geçiyoruz.
                    }
                    else
                    {
                        if (state != 0) //Arka arkaya gelen aynı harfler için automata'nın patlamasına karşı bunu yapıyoruz.
                            automata_failed = 1;
                        state = 0;
                    }
                }
                break;
            }
        }
        if (state == regex_len) //Kelime bulunduysa.
        {
            if (line_number == 0)
            {
                if (state_line_number)
                {
                    list = list_push(list, -1);
                    list = list_push(list, line_number);
                    state_line_number = 0;
                }
            }
            if (temp_line_number != line_number)
            {
                list = list_push(list, -1);
                list = list_push(list, line_number);
                temp_line_number = line_number;
            }
            list = list_push(list, (temp)-regex_len);
            list = list_push(list, temp);
            count++;
            state = 0;
        }
    }
    list = list_push(list, -1);
    list_print(list);
    printf("\n");
    print_matches(f, list, "/home/ahmet/projects/rem/ahmet.txt");
    list_free(list);
    fclose(f);
    return count;
}

void print_line_number(unsigned int line_number)
{
    printf("%d: ", line_number);
}

void print_file_name(char *fname)
{
    printf("%s: ", fname);
}

void print_between(FILE *f, int line_number, int char_begin, int char_end)
{
    fseek(f, 0, SEEK_SET);
    char next_char;
    while (line_number != 0)
    {
        next_char = fgetc(f);
        while (next_char != '\n')
            next_char = fgetc(f);
        line_number--;
    }
    next_char = 0;
    fseek(f, char_begin, SEEK_CUR);
    while ((char_end == -1 && next_char != '\n') || (char_begin + 1 <= char_end))
    {
        next_char = fgetc(f);
        printf("%c", next_char);
        char_begin++;
    }
}

void print_matches(FILE *f, int_n *root, char *filepath)
{
    if (root == NULL)
        return;
    int i = 0;
    unsigned int line_number = 0;
    unsigned int char_begin = 0;
    int size = list_size(root);
    for (i; i < size; i++)
    {
        if (list_get(root, i) == -1)
        {
            if (i != 0)
                print_between(f, line_number, char_begin, -1);
            printf("\n");
            if (i == size - 1)
                return;
            char_begin = 0;
            i = i + 1;
            line_number = list_get(root, i);
            print_file_name(filepath);
            print_line_number(line_number);
            continue;
        }
        print_between(f, line_number, char_begin, list_get(root, i));
        char_begin = list_get(root, i);
        printf("\e[32;1m");
        print_between(f, line_number, char_begin, list_get(root, i + 1));
        printf("\e[0m");
        char_begin = list_get(root, i + 1);
        i = i + 1;
    }
}
