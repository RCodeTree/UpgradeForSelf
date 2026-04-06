/* 
概念：插入排序把数组分为“已排序区”和“未排序区”，每次把未排序区的第一个元素插入到已排序区的正确位置；
思想：通过比较并右移元素为待插入元素腾位置，稳定，适合小规模或基本有序数据。
步骤：
    1) 视 arr[0] 为已排序；
    2) 从 i=1..n-1 取 key=arr[i]，令 j=i-1，自右向左比较：若升序则当 arr[j]>key 时右移 arr[j+1]=arr[j]，j--，直到 j<0 或 arr[j]≤key；
    3) 将 key 放到 arr[j+1] 完成本次插入，重复至 i 结束。复杂度：最坏/平均 O(n^2)，最好 O(n)，空间 O(1)。 
*/

// 以下是使用插入排序对数组进行降序排序
#include <stdio.h>
int main()
{
	int arr[15] = {
                3, 44,//有序
                38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48//无序
        };

	int len = sizeof(arr) / sizeof(arr[0]);

	for(int i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	// 首先找出无序部分开始的索引
	int startIndex = -1;
	for(int i = 0; i < len - 1; i++)
	{
		if(arr[i] < arr[i + 1])
		{
			startIndex = i;
			break;
		}
	}

	// 开始将无序的序列放到有序序列中，并做好序列的排序
	for(int i = startIndex; i < len; i++)
	{
		// 记录当前要插入的元素索引
		int j = i;
		while(j > 0 && arr[j] > arr[j - 1])
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}

	}

	for(int i = 0; i < len; i++) printf("%d ", arr[i]);
        printf("\n");

	return 0;

}
