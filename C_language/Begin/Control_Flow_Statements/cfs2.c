// 输出1-100之间的奇数
#include <stdio.h>
int main()
{
	int index = 0;
	while(index <= 100) 
	{
		if (index % 2 != 0) 
		{
			printf("该数 %d 为奇数\n", index);
		}
		index++;
	}
	return 0;
}
