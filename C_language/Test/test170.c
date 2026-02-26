#include <stdio.h>

int main()
{
	int n, a[100], b[100], i = 0; int tmp;
	printf("输入一个数：");
	scanf("%d", &n); tmp = n;
	while (n)
	{
		a[i] = n % 8;
		n /= 8;
		i++;
	}
	int q = 0;
	while (tmp)
	{
		b[q] = tmp % 16;
		tmp /= 16;
		q++;
	}
	printf("八进制：\n");
	for (int k = i - 1; k >= 0; k--) printf("%d", a[k]);
	printf("\n");
	printf("十六进制：\n");
	for (int j = q - 1; j >= 0; j--) 
	{
		if (b[j] < 10) printf("%d", b[j]);
		else printf("%c", 'a' + b[j] - 10);
	}
	printf("\n");

	return 0;
}
