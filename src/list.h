#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *list_new(int first_value);
unsigned int list_size(node *start);
int list_get(node *start, unsigned int index);
node *list_add(node *start, unsigned int index, int value);
node *list_remove(node *start, unsigned int index);
void list_push(node *start, int value);
int list_pop(node *start);
void list_print(node *start);
node *list_free(node *start);
