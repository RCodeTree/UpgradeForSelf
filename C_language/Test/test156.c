#include <stdio.h>
void main()
{
	int a, b, c;
	a = b = 1;
	c = a++-1;
	printf("%d, %d,", a, c); // 2, 0,
	c += -a+++(++b || ++c);
	printf("%d, %d\n", a, c); // 3, -1
}

