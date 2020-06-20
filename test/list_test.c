#include "../src/list.h"

int main()
{
  node *root = list_new(15);
	printf("%d", root->data);

	return 0;
}
