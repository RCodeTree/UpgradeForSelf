#include <stdio.h>
int main()
{
	char ch1, ch2, ch3;
	ch1 = '\xff';
	// ch2 = '\08'; ----> 非法
	ch3 = '\010'; // 合法

	printf("%c\n", ch1); // 255
	// printf("%c", ch2);
	printf("%c\n", ch3); // 8


	return 0;
}
