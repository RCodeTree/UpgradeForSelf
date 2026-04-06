#include <stdio.h>
#include <math.h>
// 递归计算阶乘的函数
double fac(int n)
{
    if (n == 0 || n == 1)
        return 1.0;
    return n * fac(n - 1);
}

int main()
{
    double e = 1.0; // 初始化 e 的值为第一项 1
    double term; // 当前项的值
    int n = 1; // 从 n=1 开始计算
    do
    {
        term = 1.0 / fac(n); // 计算当前项
        e += term; // 累加到 e 中
        n++;
    }
    while (fabs(term) >= 1e-7); // 当项的绝对值小于 1e-7 时停止
    printf("最终结果：e ≈ %.8f\n", e);
    printf("计算到 n=%d 时满足精度要求\n", n - 1);
    return 0;
}
