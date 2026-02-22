// 输入3个整数，将这三个整数按从大到小输出
#include <stdio.h>

void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


int main()
{
	int a, b, c;

	printf("请输入3个整数> ");
	scanf("%d %d %d", &a, &b, &c);

	/*
	int temp;

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	if (a < c)
	{
		temp = a;
		a = c;
		c = temp;
	}

	if (b < c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	*/

	if (a < b)
        {
                swap(&a, &b);
        }

        if (a < c)
        {
                swap(&a, &c);
        }

        if (b < c)
        {
                swap(&b, &c);
        }

	printf("%d %d %d\n", a, b, c);

	return 0;
}

