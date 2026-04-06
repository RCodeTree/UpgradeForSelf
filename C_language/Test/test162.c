#include <stdio.h>

/*
 * 功能：输出一个5行5列的二维数组，数组元素从1开始递增
 * 输入：无
 * 输出：一个5行5列的二维数组，数组元素从1开始递增
 */
int main()
{
	int a[5][5], i, j, n = 1;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			a[i][j] = n++;
	printf("The result is: \n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	return 0;
}
