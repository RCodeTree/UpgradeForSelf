// 数组排序：输入10个整数，按升序排列并输出
#include <stdio.h>
int main()
{
	int index = 0;
	int arr[10];

	// 将10个数添加到数组中
	while(index < 10)
	{
		printf("请输入第%d个数: ", index + 1);
		scanf("%d", &arr[index]);
		index++;
	}



	/*
	// 冒泡排序：相邻的两个元素比较，arr[i]和arr[i + 1]比较(外层循环控制要进行多少次轮数(轮数 = 数据总量 - 1)，内层循环是每次取的值)
	// 内层循环的 j < 9 是 数组长度 - 1 得到的，是为了防止索引越界
	// 内层循环每次 减i 是少一次循环次数，因为每一次排序后都会有一个确定的值在最后面，因此，只需排序剩下的值即可
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9 - i; j++) 
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	*/
	
	// 选择排序：拿着前面的一个数和后面的数字依次相比
	// 外层循环：控制前面数的值  内层循环：控制后面依次出现数的值
	for (int i = 0; i < 10; i++)
	{
		for(int j = i; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	

	printf("---------------------------------------------------\n");

	// 输出数组
	for (int j = 0; j < 10; j++) {
		printf("第%d个数组的值为：%d\n",  j + 1, arr[j]);
	}


	return 0;
}
