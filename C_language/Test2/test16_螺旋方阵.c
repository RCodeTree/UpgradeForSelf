#include <stdio.h>

#define N 6

void printA(int (*a)[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

int main()
{
	int num = 1;
	int a[N][N] = {0};
	
	int top = 0;
	int bottom = N - 1;
	int left = 0;	
	int right = N - 1;

	int i;

	while (num <= N * N)
	{
		// 从左到右 ----> 上边界
		for (i = left; i <= right; i++) a[top][i] = num++;
		top++; // 上边界收缩

		// 从上到下 ----> 右边界
		for (i = top; i <= bottom; i++) a[i][right] = num++;
		right--; // 右边界收缩

		// 从右到左 ----> 下边界
		for (i = right; i >= left; i--) a[bottom][i] = num++;
		bottom--; // 下边界收缩

		// 从下到上 ----> 左边界
		for (i = bottom; i >= top; i--) a[i][left] = num++;
		left++; // 左边界收缩
		

		
	}

	printA(a);
	return 0;
}
