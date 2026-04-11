#include <stdio.h>

void f(unsigned int num)
{
	if (num == 0) return;
	f(num / 8);
	printf("%u", num % 8);
}

void f2(unsigned int num)
{
	if (num == 0) return;
        f(num / 16);
	if (num % 16 >= 10)
		printf("%c", 'A' + (num % 16 - 10));
	else
		printf("%u", num % 16);
}

int main()
{
	int num1;
	printf("请输入num1: ");
	scanf("%u", &num1);
	f(num1);

	int num2;
        printf("请输入num2: ");
        scanf("%u", &num2);
	f2(num2);
	return 0;
}
