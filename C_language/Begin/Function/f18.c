// 递归实现 n 的 k 次方 ----> n * n的k-1次方 或者 n * n * n的k-2次方
#include <stdio.h>

int getNumPow(int num, int count)
{
	if (count == 0)
	{
		return 1;
	}
	else if(count < 0)
	{
		return num * getNumPow(num, -count);
	}
	else if(count > 0)
	{
		return num * getNumPow(num, count - 1);
	}
}





int main()
{
	int num, count;

	printf("请分别输入数字、和要求的次方：");
	scanf("%d %d", &num, &count);

	int pow = getNumPow(num, count);

	printf("数字 %d 的 %d 次方为：%d\n", num, count, pow);

	return 0;
}
