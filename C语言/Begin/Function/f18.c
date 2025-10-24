// 递归实现 n 的 k 次方
#include <stdio.h>

int getNumPow(int num, int count)
{
	if (num == 0)
	{
		return 1;
	}





int main()
{
	int num, count;

	printf("请分别输入数字、和要求的次方：");
	scanf("%d %d", &num, &count);

	int pow = getNumPow(num, count);

	printf("数字 %d 的 %d 次方为：%d", num, count, pow);

	return 0;
}
