#include <stdio.h>

/*
 2 * Fun(3) ----> 2 * 8 = 16
 2 * Fun(4) ----> 2 * 4 = 8
 2 * Fun(5) ----> 2 * 2 = 4
 */

int Fun(int n)
{
	if (n == 5)
	{
		return 2;
	}
	else
	{
		return 2 * Fun(n + 1);
	}

}

int main()
{
	int result = Fun(2);

	printf("结果为：%d\n", result);

	return 0;
}
