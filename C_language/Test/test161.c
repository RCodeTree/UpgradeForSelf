#include <stdio.h>

void f(int a, int b, int c)
{
	printf("a=%d,b=%d,c=%d\n", a, b, c);
}

int main()
{
	int i = 2;
	f(i, i++, i--);
	return 0;
}
