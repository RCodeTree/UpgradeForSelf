// 求一个整数的二进制位有多少个 1
#include <stdio.h>

/*
 * 通过十进制数，每次 %10 /10 ----> 便可得出十进制数的每一位
 * 因此，要得到十进制数的二进制的每一位，就每次 %2 /2
 */
int getOne1(unsigned int num) // 使用 unsigned int 是为了将负数转为正数，从而能正确计算负数的二进制位的 1 的个数
{
	int count = 0;

	while(num)
	{
		if(num % 2 == 1)
		{
			count++;
		}

		num /= 2;
	}

	return count;
}

int getOne2(int num)
{
	int count = 0;
	
	for(int i = 0; i < 32; i++)
	{
		if(((num >> i) & 1) == 1)
		{
			count++;
		}
	}

	return count;
}

/* 
方法三：
- 每次将 num 与 num - 1 进行按位与操作，即可将 num 二进制位的最右边的 1 变为 0
- 循环次数就是 num 二进制位的 1 的个数
*/
int getOne3(int num)
{
	int count = 0;
	while(num)
	{
		// num &= num - 1;
		num = num & (num - 1);
		count++;
	}

	return count;
}


int main()
{
	int num;
	printf("请输入一个整数> ");
	scanf("%d", &num);

	int count1 = getOne1(num);
	int count2 = getOne2(num);
	int count3 = getOne3(num);

	printf("%d 的二进制位的 1 的个数为: %d\n", num, count1);
	printf("%d 的二进制位的 1 的个数为: %d\n", num, count2);
	printf("%d 的二进制位的 1 的个数为: %d\n", num, count3);

	return 0;
}








