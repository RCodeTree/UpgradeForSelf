#include <stdio.h>

int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}

int main()
{
	int i;
	int a = 2;
	
	for ( i = 0; i < 5; i++)
	{
		if (i < 5)
		{
			printf("%d,", sum(a));
		}
		else 
		{
			printf("%d\n", sum(a));
		}
	}

	return 0;

	// 2+1+5  2+1+7 2+1+9 2+1+11 2+1+13
	// 8      10    12    14     16
}
