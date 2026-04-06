#include <stdio.h>

int main()
{
    int n;
    printf("输入整数n：");
    scanf("%d", &n);
    int num1 = 1, num2 = 1;
    for (int i = 1; i <= n; i++)
    {
	    if (i <= 2) printf("%d ", num1);
	    else 
	    {
		    int fib = num1 + num2; 
		    num1 = num2;
		    num2 = fib;
		    printf("%d ", fib);
	    }
    }
    printf("\n");
    return 0;
}
