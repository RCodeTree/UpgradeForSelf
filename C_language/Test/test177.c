#include <stdio.h>

int fun(int n)
{
	return (n > 0 ? 2 * fun(n - 1) + fun(n - 2) : -1);
}

int main()
{
	int r = fun(3);
	printf("%d\n", r);
	return 0;
}
