#include <stdio.h>
void main()
{
	/* 
		%2d 表示读取 2 个整数，%*2d 表示读取 2 个整数但不存储，%2d 表示读取 2 个整数，%f 表示读取一个浮点数。
	*/
	int a, b;
	float f;
	scanf("%2d%*2d%2d%f", &a, &b, &f);
	printf("%d, %d, %f\n", a, b, f);
}
