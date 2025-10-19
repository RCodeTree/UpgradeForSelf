// 写一个函数，每调用一次这个函数，就会将num的值加1
#include <stdio.h>

void add(int *num)
{
	*num = *num + 1;
}

int main()
{
	int num = 0;
	
	for (int i = 0; i <= 10; i++)
	{
		add(&num);
		printf("第 %d 次调用 num 的值为：%d\n", i + 1, num);
	}

	return 0;
}
