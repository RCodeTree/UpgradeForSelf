#include <stdio.h>
int main()
{

	/* 
	scanf() 函数：
		在输入时会接收空格、换行符
		如果要格式输入可以和下方第二种、第三种输入方式一样进行输入
	*/

	char ch1, ch2, ch3;

	//scanf("%c%c%c", &ch1, &ch2, &ch3);

	// scanf("%c %c %c", &ch1, &ch2, &ch3);

	scanf("%c,%c,%c", &ch1, &ch2, &ch3);
	
	printf("%c%c%c\n", ch1, ch2, ch3);

	return 0;
}
