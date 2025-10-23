// 使用循环实现斐波那契数列
#include <stdio.h>

int getFib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;

	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;

		n--;
	}

	return c;

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
