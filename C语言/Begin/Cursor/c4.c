/* 
指针数组
存放指针(地址)的数组
*/
#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int* parr[3] = {&a, &b, &c}; // 指针数组，每个元素都是一个指针，指向一个整数

    for(int i = 0; i < 3; i++)
    {
        printf("%d ", *parr[i]);
    }
    printf("\n");
}


/*
#include <stdio.h>
int main()
{
	int arr1[4] = { 1, 2, 3, 4};
	int arr2[4] = { 2, 3, 4, 5};
	int arr3[4] = { 3, 4, 5, 6};

	int* parr[3] = {arr1, arr2, arr3};

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			// 解引用获取元素
			// printf("%d ", *(parr[i] + j));
			
			// 按照数组的索引获取元素 
			printf("%d ", parr[i][j]); // ----> parr[i] 获取的是每一个数组的元素的首地址，parr[i][j] 获取的是每一个数组中的每一个元素
		}

		printf("\n");
	}

	return 0;
}
 */

