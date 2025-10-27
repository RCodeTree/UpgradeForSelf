// 输入3个整数，将这三个整数按从大到小输出
#include <stdio.h>


int main()
{
	int arr[3];

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("请输入第 %d 个数字> ", i + 1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
	{
		for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (i == sizeof(arr) / sizeof(arr[0]) - 1)
		{
			printf("%d\n", arr[i]);
			break;
		}
		printf("%d ", arr[i]);
	}
	
	return 0;
}	
