#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *a = malloc(sizeof(int));
	int *b = a;
	*a = 10;
	free(a);
	a = 0;
	printf("%p %d\n", b, *b);
	return 0;
}
