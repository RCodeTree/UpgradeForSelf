#include <stdio.h>
#include <time.h>

#define N 100

/***
 * @brief 动态规划函数---爬楼梯 直接递归实现
 *
 * @param n
 * @return long long
 */
long long dpF(long long n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    return dpF(n - 1) + dpF(n - 2);
}

/***
 * @brief 动态规划函数---爬楼梯 记忆化搜索
 *
 * @param n
 * @return long long
 */
long long mem[N];

long long dpF2(long long n)
{
    if (mem[n]) return mem[n];

    long long sum = 0;
    if (n == 1) sum = 1;
    else if (n == 2) sum = 2;
    else sum = dpF2(n - 1) + dpF2(n - 2);

    mem[n] = sum;
    return sum;
}


/***
 * @brief 动态规划函数---爬楼梯 动态规划实现
 *
 * @param n
 * @return long long
 */
long long dp[N];

long long dpF3(long long n)
{
    dp[0] = 1, dp[1] = 2;
    if (n == 1 || n == 2) return dp[n];
    for (long long i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    clock_t start = clock();
    long long n = 5;
    printf("%lld\n", dpF(n));
    clock_t end = clock();
    printf("time = %ld\n", end - start);

    printf("---------------\n");

    clock_t start2 = clock();
    printf("%lld\n", dpF2(n));
    clock_t end2 = clock();
    printf("time = %ld\n", end2 - start2);

    printf("---------------\n");

    clock_t start3 = clock();
    printf("%lld\n", dpF3(n));
    clock_t end3 = clock();
    printf("time = %ld\n", end3 - start3);

    return 0;
}
