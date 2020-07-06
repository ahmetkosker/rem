#ifndef _REM_REM_H
#define _REM_REM_H
#include <stdio.h>
#include "int_list.h"
#include "options.h"

int match_in_file(char *filepath, char *regex, unsigned char flags, options_t option);
void print_line_number(unsigned int line_number);
void print_file_name(char *fname);
void print_between(FILE *f, int line_number, int char_begin, int char_end);
void print_matches(FILE *f, int_node_t *root, char *fname, options_t option, unsigned int total_line_number);

#endif
