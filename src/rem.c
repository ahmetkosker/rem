#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rem.h"
#include "options.h"
#include "int_list.h"

int match_in_file(char *filepath, char *regex, unsigned char flags, options_t option)
{
    FILE *f = fopen(filepath, "r");
    if (f == NULL)
    {
        fprintf(stderr, "File cannot be open.\n");
        return -1;
    }
    int_node_t *list = NULL;
    unsigned int count = 0;
    unsigned int where = 0;
    size_t regex_len = strlen(regex);
    char *temp_p = NULL; //It needs for ENABLE_WORD.
    char next_char;
    if (isflag(flags, ENABLE_WORD)) //We finds only real word.
    {
        temp_p = malloc(regex_len + 3);
        temp_p[0] = ' ';
        int i;
        for (i = 0; i < regex_len; i++)
            temp_p[i + 1] = regex[i];
        temp_p[regex_len + 1] = ' ';
        temp_p[regex_len + 2] = 0;
        regex = temp_p;
        regex_len += 2;
    }
    int temp_char = 0; //It needs for ENABLE_CASE_SENSITIVE.
    unsigned int automata_failed = 0;
    unsigned int state = 0;
    unsigned int i = 0;
    int temp = 0;
    int temp_line_number = 0; //It needs for print_matches.
    int line_number = 0;
    unsigned char flag;
    int state_line_number = 1; //It needs for print_matches.

    while (!feof(f)) //Until the file is over.
    {
        if (automata_failed) // We does not read a new characters.
            automata_failed = 0;
        else
        {
            next_char = fgetc(f); //We read a new character.
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
            if (state == i) //We comes to the last word we stayed.
            {
                if (!isflag(flags, ENABLE_CASE_SENSITIVE))
                {
                    if (regex[i] <= 90 && regex[i] >= 65) //For uppercase and lowercase.
                        temp_char = regex[i] + 32;
                    else if (regex[i] <= 122 && regex[i] >= 97)
                        temp_char = regex[i] - 32;
                    if (next_char == regex[i] || temp_char == next_char) //Okunan karakter duruma bağlı harfe eşitse.
                    {
                        state = i + 1; //We move on to the next word.
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
                        state = i + 1; //We move on to the next word.
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
        if (state == regex_len) //If the word found.
        {                       //List fills.
            if (line_number == 0)
            {
                if (state_line_number)
                {
                    list = list_push(list, -1); // -1 = new line.
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
    print_matches(f, list, filepath, option, flags, line_number);
    list_free(list);
    if (temp_p != NULL)
        free(temp_p);
    fclose(f);
    return count;
}

void print_line_number(unsigned int line_number)
{
}

void print_file_name(char *fname)
{
    printf("\e[33m%s\e[0;m:", fname);
}

void print_between(FILE *f, int line_number, int char_begin, int char_end)
{
    fseek(f, 0, SEEK_SET);
    char next_char;
    while (line_number != 0) //If we are not in first line.
    {
        next_char = fgetc(f);
        while (next_char != '\n')
            next_char = fgetc(f);
        line_number--;
    }
    next_char = 0;
    fseek(f, char_begin, SEEK_CUR);
    while (char_end == -1 && next_char != '\n' || (char_begin + 1 <= char_end))
    {
        next_char = fgetc(f);
        if (feof(f))
            return;
        if (next_char != '\n')
            printf("%c", next_char);
        char_begin++;
    }
}

void print_matches(FILE *f, int_node_t *root, char *filepath, options_t options, unsigned char flags, unsigned int total_line_number)
{
    if (root == NULL)
        return;
    int bomb = 0;
    int is_print_line_numbers = isflag(flags, ENABLE_LINE_NUMBER);
    int is_print_colorful = isflag(flags, ENABLE_COLOR);
    int is_print_file_name = isflag(flags, ENABLE_FILE_NAME);
    int i = 0;
    int j;
    int line_number = 0;
    unsigned int char_begin = 0;
    int size = list_size(root);
    for (i; i < size; i++)
    {
        if (list_get(root, i) == -1)
        {
            if (i != 0)
            {
                print_between(f, line_number, char_begin, -1);
                printf("\n");

                for (j = 0; j < options.after && total_line_number >= line_number + j + 1; j++)
                {
                    if (is_print_file_name)
                        printf("%s%s%s:", is_print_colorful ? "\e[33m" : "", filepath, is_print_colorful ? "\e[0;m" : "");
                    if (is_print_line_numbers)
                        printf("%s%d%s:", is_print_colorful ? "\e[35m" : "", line_number + j + 2, is_print_colorful ? "\e[0;m" : "");
                    print_between(f, line_number + j + 1, 0, -1);
                    printf("\n");
                }
                if (options.before != 0 || options.after != 0)
                    printf("--\n");
            }
            if (i == size - 1)
                return;
            char_begin = 0;
            i = i + 1;
            line_number = list_get(root, i);
            bomb = 1;
            continue;
        }
        if (bomb == 1)
        {

            for (j = options.before; j > 0; j--)
            {
                if (line_number - j < 0)
                    continue;
                if (is_print_file_name)
                    printf("%s%s%s:", is_print_colorful ? "\e[33m" : "", filepath, is_print_colorful ? "\e[0;m" : "");
                if (is_print_line_numbers)
                    printf("%s%d%s:", is_print_colorful ? "\e[35m" : "", line_number - j + 1, is_print_colorful ? "\e[0;m" : "");
                print_between(f, line_number - j, 0, -1);
                printf("\n");
            }
            bomb = 0;
        }
        if (char_begin == 0)
        {
            if (is_print_file_name)
                printf("%s%s%s:", is_print_colorful ? "\e[33m" : "", filepath, is_print_colorful ? "\e[0;m" : "");
            if (is_print_line_numbers)
                printf("%s%d%s:", is_print_colorful ? "\e[35m" : "", line_number + 1, is_print_colorful ? "\e[0;m" : "");
        }
        print_between(f, line_number, char_begin, list_get(root, i));
        char_begin = list_get(root, i);
        if (is_print_colorful)
            printf("\e[31;1m");
        print_between(f, line_number, char_begin, list_get(root, i + 1));
        if (is_print_colorful)
            printf("\e[0m");
        char_begin = list_get(root, i + 1);
        i = i + 1;
    }
}
