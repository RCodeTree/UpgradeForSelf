/*#include <stdio.h>

void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int a = 10, b = 20;
    int *p1 = &a, *p2 = &b;
    swap(p1, p2);
    printf("%d %d\n", a, b);
    swap(&a, &a);
    printf("%d\n", a);
    return 0;
}*/

/*
#include <stdio.h>

union U
{
    int a;
    char b;
};

int main()
{
    union U u;
    u.a = 0x41424344; // 假设 int 占 4 字节
    printf("%c\n", u.b);
    return 0;
}
*/

// 编程题
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}
int main()
{
	srand((unsigned int) time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = rand() % 101;
	sort(arr, 10);
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

























