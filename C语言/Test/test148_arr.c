#include <stdio.h>
#define row 2
#define column 3

int main()
{
	int arr[row][column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < column; i++)
	{

		for (int j = 0; j < row; j++)
			printf("%d ", arr[j][i]);
		printf("\n");
	}
	return 0;
}

