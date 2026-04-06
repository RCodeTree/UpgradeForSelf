/* 
- 题目描述：
	- 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
- 输入描述：
	- 输入一个整数数组，数组长度为 len，数组元素为 int 类型。
- 输出描述：
	- 输出调整后的数组，每个元素之间用空格隔开。
*/
#include <stdio.h>
void swap_odd_even(int* arr, int len)
{
	int left = 0;
	int right = len - 1;

	/* 
    // 自己想法加上错误修改版：直接使用外层的while循环判断
    while(left < right)
	{
        // 找到偶数的位置为止，然后停下来，等待奇数的位置
		if(arr[left] % 2 != 0)
		{
			left++;
            continue;
		}

        // 找到奇数的位置为止，然后停下来，等待偶数的位置
		if(arr[right] % 2 == 0)
		{
			right--;
            continue; 
		}


		if(left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
            // 交换后移动 left 和 right 指针，继续判断
            left++; 
            right--;
        }
	} 
    */

    // 标准解法：使用内层的while循环判断
    while(left < right)
	{
        // 找到偶数的位置为止，然后停下来，等待奇数的位置
		while(left < right && arr[left] % 2 != 0)
		{
			left++;
		}

        // 找到奇数的位置为止，然后停下来，等待偶数的位置
		while(left < right && arr[right] % 2 == 0)
		{
			right--;
		}


		if(left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
            // 交换后移动 left 和 right 指针，继续判断
            left++; 
            right--;
        }
	}
}

int main()
{
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    swap_odd_even(arr, len);

	for(int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}
