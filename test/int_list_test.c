#include "../src/int_list.h"

int main()
{
	printf("15 added.\n");
	printf("List: ");
	int_node_t *root = list_new(15);
	list_print(root);
	printf("7 added.\n");
	printf("List: ");
	list_push(root, 7);
	list_print(root);
	printf("14 added.\n");
	printf("List: ");
	list_push(root, 14);
	list_print(root);
	printf("2 added.\n");
	printf("List: ");
	list_push(root, 2);
	list_print(root);
	printf("19 added.\n");
	printf("List: ");
	list_push(root, 19);
	list_print(root);
	printf("3 added.\n");
	printf("List: ");
	root = list_add(root, 2, 3);
	list_print(root);
	printf("96 added.\n");
	printf("List: ");
	root = list_add(root, 2, 96);
	list_print(root);
	int data = list_get(root, 5);
	printf("List_get: %d\n", data);
	printf("3 removed.\n");
	printf("List: ");
	root = list_remove(root, 3);
	list_print(root);
	printf("First value removed.\n");
	printf("List: ");
	root = list_remove(root, 0);
	list_print(root);
	printf("Last value removed.\n");
	printf("List: ");
	list_pop(root);
	list_print(root);
	printf("Last value removed.\n");
	printf("List: ");
	list_pop(root);
	list_print(root);
	printf("55 added.\n");
	printf("List: ");
	list_push(root, 55);
	list_print(root);
	printf("49 added.\n");
	printf("List: ");
	list_push(root, 49);
	list_print(root);
	printf("List is empty now\n");
	root = list_free(root);
	list_print(root);

	return 0;
}
