/* 
主要作用：
- 可以将多个字符串存储在一个数组中
- 可以将多个指针存储在一个数组中
*/
// #include <stdio.h>
// int main()
// {
// 	char* ch[3];
// 	ch[0] = "hello";
// 	ch[1] = "world";
// 	ch[2] = "!";
// 	printf("%s\n", ch[0]); // hello
// 	printf("%s\n", ch[1]); // world
// 	printf("%s\n", ch[2]); // !

// 	return 0;
// }


// 可以模拟二维数组
#include <stdio.h>
int main()
{
	int arr1[3] = {1, 2, 3};
	int arr2[3] = {4, 5, 6};
	int arr3[3] = {7, 8, 9};

	int* parr[3] = {arr1, arr2, arr3};

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
            // *(arr + i) <----> arr[i]
			// printf("%d ", parr[i][j]);
            // printf("%d ", *(parr[i] + j));
			printf("%d ", *(*(parr + i) + j));
		}
		printf("\n");
	}

    /* 
    输出结果：
    1 2 3
    4 5 6
    7 8 9
    */
	
	return 0;
}