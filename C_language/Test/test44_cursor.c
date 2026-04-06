// 使用指针打印整数数组内容
#include <stdio.h>
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int *p = arr;

	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");

	return 0;
}
