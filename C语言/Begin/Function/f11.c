// 输入3个整数，将这三个整数按从大到小输出
#include <stdio.h>


int main()
{
	int arr[3];

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("请输入第 %d 个数字> ", i + 1);
		scanf("%d", arr[i]);
	}

	for (int i = 0; i < siz	
