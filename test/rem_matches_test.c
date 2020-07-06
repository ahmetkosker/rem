#include <stdio.h>
#include <stdlib.h>
#include "../src/rem.h"
#include "../src/int_list.h"

int main()
{
	FILE *f;
	int_node_t *root = list_new(-1);
	list_push(root, 0);
	list_push(root, 2);
	list_push(root, 5);
	list_push(root, -1);
	list_push(root, 4);
	list_push(root, 3);
	list_push(root, 4);
	list_push(root, 7);
	list_push(root, 9);
	list_push(root, 15);
	list_push(root, 25);
	list_push(root, -1);
	list_push(root, 101);
	list_push(root, 20);
	list_push(root, 30);
	list_push(root, -1);
	list_print(root);
	f = fopen("./LICENSE", "r");
	print_matches(f, root, "./LICENSE", );
	return 0;
}
