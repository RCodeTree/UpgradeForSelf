// 输出 1-100 之间 3 的倍数
#include <stdio.h>

void getNum(int num)
{
	if (num % 3 == 0)
	{
		printf("%d ", num);
	}
}

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		getNum(i);
	}

	return 0;
}

