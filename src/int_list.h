#include <stdio.h>

struct int_n
{
	int data;
	struct int_n *next;
};
typedef struct int_n int_n;

int_n *list_new(int first_value);
unsigned int list_size(int_n *root);
int list_get(int_n *root, unsigned int index);
int_n *list_add(int_n *root, unsigned int index, int value);
int_n *list_remove(int_n *root, unsigned int index);
void list_push(int_n *root, int value);
int list_pop(int_n *root);
void list_print(int_n *root);
int_n *list_free(int_n *root);
