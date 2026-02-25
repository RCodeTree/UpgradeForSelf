#include <stdio.h>

int main()
{
	int a[5][5] = {0};
	// 杨辉三角
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0) a[i][j] = 1;
			if (j == 0) a[i][j] = 1;
			if (i == j) a[i][j] = 1;
			if (i > 1 && j >= 1) a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}

	// 正三角
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - (i + 1); j++)
		{
			printf("\t");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("\t%d\t", a[i][k]);
		}
		printf("\n");
	}

	// 倒三角
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < 5 - (i + 1); j++)
		{
			printf("\t");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("\t%d\t", a[i][k]);
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k <= i; k++)
		{
			printf("%d ", a[i][k]);
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - (i + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("%d ", a[i][k]);
		}
		printf("\n");
	}

	return 0;
}

