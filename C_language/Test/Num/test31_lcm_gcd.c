#include <stdio.h>

int main() {
    int m, n;
    
    printf("请输入两个正整数 m 和 n (用空格隔开): ");
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
        printf("请输入有效的正整数！\n");
        return 1;
    }

    // --- 方法一：公式法（推荐，效率最高） ---  
    // 原理：最小公倍数 = (m * n) / 最大公约数
    
    // 1. 先求最大公约数 (GCD) - 使用辗转相除法
    int a = m, b = n, temp;
    while (b != 0) {
        temp = a % b;
        a = b;      // 把除数作为新的被除数
        b = temp;   // 把余数作为新的除数
    }
    int gcd_val = a; // 循环结束时，a 就是最大公约数
    
    // 2. 套用公式求最小公倍数 (LCM)
    // 提示：先除后乘可以防止 m*n 直接相乘导致数值溢出
    int lcm_method1 = (m / gcd_val) * n;
    
    printf("\n【方法一：公式法】\n");
    printf("%d 和 %d 的最大公约数是: %d\n", m, n, gcd_val);
    printf("%d 和 %d 的最小公倍数是: %d\n", m, n, lcm_method1);


    // --- 方法二：暴力枚举法（逻辑简单，但数字大时慢） ---
    // 原理：从两个数中较大的那个开始，每次加1，直到找到一个能同时整除 m 和 n 的数
    
    int max = (m > n) ? m : n; // 找出较大的数
    
    while (1) {
        if (max % m == 0 && max % n == 0) {
            break; // 找到了，跳出循环
        }
        max++;
    }
    
    printf("\n【方法二：枚举法】\n");
    printf("计算结果: %d\n", max);

    return 0;
}
