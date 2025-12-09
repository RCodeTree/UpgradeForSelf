#include <stdio.h>
#include <stdbool.h>
int main()
{
	int num, max = 0; // max 起到两个作用，存储上一个最大值，同时取得最终那个最大的值
	
	/*
	do
	{
		scanf("%d", &num);
		if(num > max) max = num;
	} while(num != 0);
	*/

	while(true)
	{
		scanf("%d", &num);
		if(num)
		{
                	if(num > max) max = num;
		}
		else
		{
			break;
		}
	}

	printf("%d\n", max);
	
	return 0;
}
