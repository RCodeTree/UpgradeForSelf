// 求爬 n 个台阶共有几种爬法(一次可以爬 1 个或者一次可以爬 2 个) ----> 分解：如果为 3 个台阶，其实也就是 ----> total = 1 个台阶的爬法 + 2 个台阶的爬法
// 实质上就是求第 3 个斐波那契数列的值 ----> 但是还有有些区别的
#include <stdio.h>

int fib(int n)
{
	if(n <= 2)
	{
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;

	printf("请输入台阶的个数> ");
	scanf("%d", &n);

	int total = fib(n);

	printf(" %d 个台阶有 %d 种爬法\n", n, total);

	return 0;
}

