// 使用递归实现斐波那契数列
#include <stdio.h>

int getFib(int n)
{
	if (n > 2)
	{
		return getFib(n - 1) + getFib(n - 2);
	}

	return 1;
}

int main()
{
	int n;

	printf("请输入要求第几个斐波那契数列> ");
	scanf("%d", &n);

	int fib = getFib(n);

	printf("第 %d 个斐波那契数列的值为> %d\n", n, fib);

	return 0;
}

