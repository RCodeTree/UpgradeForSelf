#include <stdio.h>
int main()
{
	/*
	 %02d ---> "2" 表示要有两位整数  "0" 表示如果为个位数，前面则以"0"补齐输入的值
	 %.2f ---> ".2" 表示保留两位小数
	 */

	int id;
	float c;
	float math;
	float english;

	printf("请输入学生的相关信息：");
	scanf("%d;%f,%f,%f", &id, &c, &math, &english); // 输入时要根据输入格式输入

	printf("id=%d, c=%.2f, math=%.2f, english=%.2f\n", id, c, math, english);

	return 0;
}
