// goto 语句
#include <stdio.h>
#include <stdbool.h>
int main()
{
	int index = 0;


exit:
	printf("goto语句执行");

	while(index < 6)
	{

		printf("index的值：%d", index);

		if (index == 5)
		{
			goto exit;
		}
		index++;
	}

	return 0;
}
