#include "../src/rem.h"

int main()
{
	FILE *f = fopen("./LICENSE", "r");
	print_between(f, 0, 2, 4);
	print_between(f, 2, 3, 7);
	print_between(f, 2, 8, 11);
	print_between(f, 3, 0, 3);
	print_between(f, 3, 6, 11);

	return 0;
}
