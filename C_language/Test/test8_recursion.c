// 交换数组：将数组A的内容和数组B的内容进行交换(数组一样大)
#include <stdio.h>

void swapArr(int *arr1, int *arr2)
{
	int temp[3];

	for(int i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
	{
		temp[i] = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp[i];
	}
}

int main()
{
	int arr1[] = {1, 2, 3};
	int arr2[] = {4, 5, 6};

	for(int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("交换前 arr1[%d] 的值为：%d\n", i, arr1[i]);
		printf("交换前 arr2[%d] 的值为：%d\n", i, arr2[i]);
	}

	printf("-----------------------------------------------\n");

	swapArr(arr1, arr2);

	for(int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("交换后 arr1[%d] 的值为：%d\n", i, arr1[i]);
		printf("交换后 arr2[%d] 的值为：%d\n", i, arr2[i]);
	}

	return 0;
}


