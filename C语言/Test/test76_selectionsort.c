/*
①从数组存放的 n 个数中找出最小数的下标，然后将最小数与第 1 个数交换位置；
②除第 1 个数以外，再从其余 n-1 个数中找出最小数（即 n 个数中的次小数）的下标，将此数与第 2 个数交换位置；
③重复步骤 1 共 n-1 趟，即可完成所求。
*/
#include <stdio.h>
int main()
{
	int arr[10] = { 3, 43, 2, 1, 7, 6, 8, 10, 13, 5};
	int len = sizeof(arr) / sizeof(arr[0]);
	int minIndex;

	for(int i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	for(int i = 0; i < len - 1; i++)
	{
        /*
        从当前位置开始，找到最小值的索引
        */ 
        minIndex = i; // 假设当前位置是最小值的索引
		for(int j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
        if(minIndex != i) // minIndex != i ----> 如果最小值的索引不是当前位置，交换它们
		{
			int temp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = temp;
		}
		
	}

	for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
	
	return 0;
}	
