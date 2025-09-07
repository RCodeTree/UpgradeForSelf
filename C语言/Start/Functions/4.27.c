#include <stdio.h>

int sum(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    // 求任意两个数之和
    int num1 = 0;
    int num2 = 0;
    printf("请输入两个数：");
    scanf("%d %d", &num1, &num2);
    int all = sum(num1, num2);
    printf("两数之和为：%d\n", all);
    return 0;
}
