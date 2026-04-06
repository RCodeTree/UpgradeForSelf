// 演示多个字符从两端移动，向中间汇聚
#include <stdio.h>
#include <string.h>
int main()
{
	/*
	 * strlen() 求的是 '\0' 前字符串的长度
	 * 如果使用：int heigh = sizeof(arr1) / sizeof(arr1[0]) - 2 ----> 计算的是整个数组的长度，包括 '\0'
	 */
	char arr1[] = "Hello World";
	char arr2[] = "###########";
	int low = 0;
	int heigh = strlen(arr1) - 1;


	while (low <= heigh)
	{
		arr2[low] = arr1[low];
		arr2[heigh] = arr1[heigh];
		
		low++;
		heigh--;

		printf("%s\n", arr2);
	}


	return 0;
}

