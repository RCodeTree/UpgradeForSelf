#include <stdio.h>

int main()
{
	int a[3] = {1, 2, 3};
	for (int* p = a; p < &a[3]; p++)
		printf("%d", *p);
	printf("\n");
	return 0;
}
