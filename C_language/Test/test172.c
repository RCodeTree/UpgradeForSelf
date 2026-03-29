#include <stdio.h>

/**
 * 判断一个数是否是质数
 * @param n
 * @return 1 不是质数 0 是质数
 */
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


/**
 * 分解一个数的质因子
 * @return 0
 */
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            /*if (!check(i))*/ // 实际上，这里可有可无，因为每一轮 i 时，都会将 n 除以 i 并重新赋值，已经将存在的倍数排除了
            printf("%d * ", i);
            n /= i;
        }
    }
    printf("\n");
    return 0;
}
