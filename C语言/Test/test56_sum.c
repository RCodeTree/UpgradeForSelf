/*
题目名称：
计算求和

题目内容：
求 Sn = a + aa + aaa + aaaa + aaaaa 的前 5 项之和，其中 a 是一个数字。

示例：
a = 2 → 2 + 22 + 222 + 2222 + 22222
2 = 0 * 10 + 2
22 = 2 * 10 + 2
222 = 22 * 10 + 2
.........
*/
#include <stdio.h>
int main()
{
	unsigned int num;
	unsigned int n = 0;
	int key = 0;
	int sum = 0;

	printf("请输入一个整数: ");
	scanf("%u%u", &num, &n);

	for(int i = 1; i <= n; i++)
	{
		key = key * 10 + num;

		sum += key;
	}

	printf("%u 的前 %u 项之和为: %d\n", num, n, sum);

	return 0;
}
