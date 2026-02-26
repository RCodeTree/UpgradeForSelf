#include <stdio.h>

int check(int n)
{
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (!check(i)) printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}


/*
// 改进的质数判断函数
int isPrime(int n)
{
    if (n <= 1) return 0;  // 1不是质数
    if (n == 2) return 1;   // 2是质数
    if (n % 2 == 0) return 0;  // 排除偶数

    // 只需要检查到sqrt(n)
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int n;
    printf("请输入一个正整数: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("请输入正整数！\n");
        return 1;
    }

    printf("%d的质数因子为: ", n);

    // 处理2这个特殊的质数
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    // 处理奇数因子
    for (int i = 3; i <= n; i += 2) {
        // 只有当i是质数时才检查
        if (isPrime(i)) {
            while (n % i == 0) {
                printf("%d ", i);
                n /= i;
            }
        }

        // 如果n已经变为1，提前结束
        if (n == 1) break;
    }

    printf("\n");
    return 0;
}
 */
