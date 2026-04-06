// 二分查找
#include <stdio.h>
#include <stdbool.h>
int main()
{
	int num;
	int arr[] = {1, 34, 43, 3, 53, 2, 5, 12, 4, 20};
	int length = sizeof(arr) / sizeof (arr[0]);
	int low = 0;
	int heigh = length - 1;
	int mid;
	int result = 0;

	printf("请输入一个整数: ");
	scanf("%d", &num);

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	

	while (low <= heigh)
	{
	
		mid = (low + heigh) / 2;	
        
		if (num > arr[mid])
		{
			low = mid + 1;
		}
	
		else if (num < arr[mid])
		{
			heigh = mid - 1;
		}
		else
		{
			printf("找到了\n");
			break;
		}
	}

	if (low > heigh)
	{
		printf("没找到\n");
	}

	return 0;
}


