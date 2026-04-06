#include <stdio.h>

int fun(int x[], int n)
{
    static int sum = 0, i;
    for(i = 0; i < n; i++) 
        sum += x[i];
    return sum;
}

void main()
{
	int a[] = {1, 2, 3, 4, 5}, b[] = {6, 7, 8, 9}, s = 0;
	s = fun(a, 5 + fun(b, 4)); // a索引越界
	printf("%d\n", s);
}
