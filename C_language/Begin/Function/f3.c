// 写一个函数可以判断 1-100 哪些数是素数，并输出

#include <math.h>
#include <stdio.h>

int certifyNum(int num)
{
	for (int j = 2; j <= sqrt(num); j++)
	{
		if (num % j == 0)
		{
			return 0; // 不是素数
		}
	}

	return 1; // 是素数
}

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (certifyNum(i))
		{
			printf("该数为素数，该数为：%d\n", i);
		}
	}

	return 0;

}
