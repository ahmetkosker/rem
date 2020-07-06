#ifndef REM_INT_LIST_H
#define REM_INT_LIST_H

#include <stdio.h>

typedef struct int_node_t
{
	int data;
	struct int_node_t *next;
} int_node_t;

int_node_t *list_new(int first_value);
unsigned int list_size(int_node_t *root);
int list_get(int_node_t *root, unsigned int index);
int_node_t *list_add(int_node_t *root, unsigned int index, int value);
int_node_t *list_remove(int_node_t *root, unsigned int index);
int_node_t *list_push(int_node_t *root, int value);
int list_pop(int_node_t *root);
void list_print(int_node_t *root);
int_node_t *list_free(int_node_t *root);

#endif
