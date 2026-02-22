// 求一个整数存储在内存中的二进制中 1 的个数
#include <stdio.h>

int getOnes(unsigned int num)
{
	int count = 0;

	while(num) // 如果右移后，得到的十进制的数为 0 时，此时就退出循环
	{
		if(num & 1) // 如果 num 每次和 1 与运算都能得到 1，那么就说明 num 二进制数的最后一位是 1，此时就能通过每一次右移操作，将最后一位 1 给去掉，从而计算 1 的个数
		{
			count += 1;
		}

		num >>= 1; // 将 num 做右移操作（将数字与1进行与运算，可以得到最低位是否为1，然后右移一位，直到所有位都检查完）
	}

	return count;
}

int main()
{
	int num = 0;
	unsigned int finalNum = (unsigned int) num; // 我们可以通过位运算来避免符号位的问题，我们使用无符号整数来避免右移时的符号扩展问题。

	printf("请输入一个整数> ");
	scanf("%u", &finalNum);

	int count = getOnes(finalNum);

	printf(" %d 在内存中的二进制中 1 的个数为：%d\n", finalNum, count);

	return 0;
}
