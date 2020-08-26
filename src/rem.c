#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rem.h"
#include "options.h"
#include "int_list.h"
#include "../tiny-regex-c/re.h"

void match_in_file(char *filepath, char *regex, unsigned char flags, options_t option)
{
    re_t pattern = re_compile(regex);
    FILE *f = fopen(filepath, "r");
    int state_line_number = 1;
    int temp_line_number = 0;
    int_node_t *list = NULL;
    int line_number = 0;
    int match_idx = 0;
    int file_len = 0;
    int offset = 0;
    int where = 0;
    int match_len = strlen(regex);
    int i = 0;
    char next;
    int pure_word_len = match_len + 3;
    int is_pure_word = isflag(flags, ENABLE_WORD);
    if (is_pure_word)
    {
        char *pure_word;
        char temp_word[pure_word_len];
        temp_word[0] = ' ';
        for (i = 1; i < pure_word_len - 2; i++)
            temp_word[i] = regex[i - 1];
        temp_word[pure_word_len - 2] = ' ';
        temp_word[pure_word_len - 1] = 0;
        i = 0;
        pure_word = temp_word;
        pattern = re_compile(pure_word);
    }
    while (!feof(f))
    {
        fgetc(f);
        file_len++;
    }
    char array[file_len];
    fseek(f, 0, SEEK_SET);
    while (!feof(f))
    {
        array[i] = fgetc(f);
        i++;
    }
    fseek(f, 0, SEEK_SET);
    const char *str = array;
    i = 0;
    do
    {
        if (is_pure_word)
        {
            match_idx = re_matchp(pattern, str + offset, &pure_word_len);
            offset = offset + match_idx + pure_word_len;
        }
        else
        {
            match_idx = re_matchp(pattern, str + offset, &match_len);
            offset = offset + match_idx + match_len;
        }
        while (i < offset)
        {
            next = fgetc(f);
            if (next == '\n')
            {
                line_number++;
                where = 0;
            }
            i++;
            where++;
        }
        if (match_idx != -1)
        {
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
            if (is_pure_word)
                list = list_push(list, where - pure_word_len - 1);
            else
                list = list_push(list, where - match_len - 1);
            list = list_push(list, where - 1);
        }
    } while (match_idx != -1);
    list_push(list, -1);
    print_matches(f, list, filepath, option, flags, line_number);
    list_free(list);
    fclose(f);
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