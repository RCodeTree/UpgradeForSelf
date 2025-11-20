// 求两个数二进制位中有多少个不同的位数
#include <stdio.h>

/* 
容易理解的方法：
1. 分别将两个数的每一位提取出来
2. 比较这两位是否不同
3. 如果不同，count++
4. 循环结束，返回 count
*/
int getCountForBit1(int num1, int num2)
{
	int count = 0;
	
	for(int i = 0; i < 32; i++)
	{
		if(((num1 >> i) & 1) != ((num2 >> i) & 1))
		{
			count++;
		}

	}

	return count;
}

int getCountForBit2(int num1, int num2)
{
	int count = 0;
	int num = num1 ^ num2; // 使用按位异或操作，将不同的位设为 1

	while(num) // 再去统计 num 中 1 的个数
	{
		num  = num & (num - 1); // 见 test46_num.c
		count++;
	}

	return count; // 统计 num 中 1 的个数，就是不同的位数
}


int main()
{
	int num1;
	int num2;

	printf("请输入两个整数:");
	scanf("%d%d", &num1, &num2);

	int count1 = getCountForBit1(num1, num2);
	int count2 = getCountForBit2(num1, num2);

	printf("%d 和 %d 这两个数的二进制位不同的一共有 %d 位\n", num1, num2, count1);
	printf("%d 和 %d 这两个数的二进制位不同的一共有 %d 位\n", num1, num2, count2);

	return 0;
}




