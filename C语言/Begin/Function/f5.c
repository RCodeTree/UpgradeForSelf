// 写一个函数，实现二分查找
#include <stdio.h>

void searchNum(int *arr, int len, int num)
{
	int low = 0;
	int heigh = len - 1;

	while (low <= heigh)
	{
		int mid = (low + heigh) / 2;

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
			printf("找到了相应的数字\n");
			break;
		}
	}

	if (low > heigh)
	{
		printf("没有找到相应的数字\n");
	}
}	

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int num;
	int len = sizeof(arr) / sizeof(arr[0]) - 1;

	printf("请输入一个数：");
	scanf("%d", &num);

	searchNum(arr, len, num);

	return 0;
}
