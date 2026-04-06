// 计算 1-100 一共有多少个数字 9
#include <stdio.h>

int getCount(int num)
{
	int count;

	if (num < 10 && num == 9)
	{
		count += 1;
	}

	if (num > 10)
	{
		if (num / 10 == 9)
		{
			count += 1;
		}

		if (num % 10 == 9)
		{
			count += 1;
		}
	}

	return count;
}

int main()
{
	int count;

	for (int i = 1; i <= 100; i++)
	{
		count = getCount(i);
	}

	printf("1-100 中有 %d 个 9\n", count);

	return 0;
}

