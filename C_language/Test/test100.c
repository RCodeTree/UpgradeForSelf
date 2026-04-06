#include <stdio.h>
int main()
{
	for (int i = 7; ;i+=7)
	{
		if (i % 2 == 1)
			if(i % 3 == 2)
				if(i % 5 == 4)
					if (i % 6 == 5)
					{
							printf("阶梯数为: %d\n", i);
							break;
					}
	}
	return 0;
}
