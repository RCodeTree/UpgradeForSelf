#include <stdio.h>
int f(int x, int y)
{
	return y - x * x;
}

int main()
{
	int a = 3, b = 4, c = 5, d;
	d = f(f(a, b), f(a, c));

	printf("%d\n", d);
	return 0;
}
