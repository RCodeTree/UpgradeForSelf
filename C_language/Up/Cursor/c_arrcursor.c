// #include <stdio.h>
// int main()
// {
// 	int arr[3] = {1, 2, 3};
// 	int(*parr)[3] = &arr; // 数组指针parr指向数组arr的地址

// 	printf("%d\n", *(*parr + 1)); // 2
// 	printf("%d\n", (*parr)[1]); // 2

// 	return 0;
// }

#include <stdio.h>
void printArray(int (*arrp)[4], int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%d\t", *(*(arrp + i) + j));
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	printArray(arr, 3, 4);

	return 0;
}