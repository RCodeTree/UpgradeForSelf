/*
描述：
KiKi想知道已经给出的三条边 a、b、c 能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三角形或普通三角形）。

输入描述：
题目有多组输入数据，每一行输入三个 a、b、c（0 < a, b, c < 1000），作为三角形的三条边，之间用空格分隔。

输出描述：
针对每组输入数据，输出占一行：
- 如果能构成三角形，等边三角形输出 "Equilateral triangle!"
- 等腰三角形输出 "Isosceles triangle!"
- 其余三角形输出 "Ordinary triangle!"
- 不能构成三角形则输出 "Not a triangle!"
*/
// 三角形定义：3 条边，任意 2 条边相加大于第 3 边
#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;

	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if(a + b > c && a + c > b && b + c > a)
		{
			if(a == b && b == c)
			{
				printf("Equilateral triangle!\n");
			}
			else if((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
			{
				printf("Isosceles triangle!\n");
			}
			else
			{
				printf("Ordinary triangle!\n");
			}
		}
		else
		{
			printf("Not a triangle!\n");
		}
	}

	return 0;
}
