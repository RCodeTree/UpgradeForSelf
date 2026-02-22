// 递归实现：求阶乘
// !3 = 3 * 2 * 1
#include <stdio.h>

int calculate(int num)
{
	if(num == 0)
	{
		return 1;
	}

	return num * calculate(num - 1);
}

int main()
{
	int num;

	printf("请输入一个整数> ");
	scanf("%d", &num);

	int result = calculate(num);

	printf(" %d 的阶乘为> %d\n", num, result);

	return 0;
}

