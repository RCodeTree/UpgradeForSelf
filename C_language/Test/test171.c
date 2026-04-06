#include <stdio.h>

int main()
{
	for (int i = 1; i <= 1000; i++)
	{
		int a[100], k = 0, s = 0;
		for ( int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				s += j;
				a[k++] = j;
			}
		}
		if (s == i)
		{
			printf("完数：%d\n", i);
			printf("其因子：\n");
			for (int q = 0; q < k; q++)
			{
				printf("%d ", a[q]);
			}
			printf("\n");
		}

	}
	return 0;
}
