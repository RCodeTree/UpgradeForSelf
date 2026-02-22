// 输入4个整数，输出最大值
#include <stdio.h>

/*
 * 冒泡排序
 */
int getMax(int *arr)
{
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
	{
		for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}	
	}

	return arr[sizeof(arr) / sizeof(arr[0]) - 1];
}



int main()
{
	int arr[4];
	int index = 0;
	int max;

	while (index < 4)
	{
		printf("请输入4个数字(使用空格分隔):");
		scanf("%d", &arr[index]);
		index++;
	}

	max = arr[0];

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	printf("最大值: %d\n", max);
	
	return 0;	
}
