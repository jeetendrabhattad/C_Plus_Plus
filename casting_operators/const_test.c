#include <stdio.h>

int main()
{
	const int i = 10;
	int *ptr = &i;
	*ptr = 20;
	printf("i = %d *ptr = %d\n", i, *ptr);
}
