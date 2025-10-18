// 写一个函数，实现二分查找
#include <stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int low = 0;
	int heigh = sizeof(arr) / sizeof(arr[0]) - 1;

	printf("请输入一个数：");
	scanf("%d", &num);

	while (low < heigh)
	{
		mid = (low + heigh) / 2;



