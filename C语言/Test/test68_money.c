#include <stdio.h>
#include <math.h>

int main() {
    double d = 300000.0; // 贷款金额
    double p = 6000.0;   // 每月还款额
    double r = 0.01;     // 月利率
    double m;

    // 根据公式 m = log(p / (p - d * r)) / log(1 + r)
    // 题目提示使用 log10，数学上 log10(A)/log10(B) 等价于 ln(A)/ln(B)
    m = log10(p / (p - d * r)) / log10(1 + r);

    // 对求得的月份取小数点后一位，对第 2 位按四舍五入处理
    // printf 的 %.1f 会自动进行四舍五入
    printf("需要 %.1f 个月能还清\n", m);

    return 0;
}
