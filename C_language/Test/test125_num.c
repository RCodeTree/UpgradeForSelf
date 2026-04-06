#include <stdio.h>

/**
 * @brief 计算 a + aa + aaa + ... + aaaa + ... + aaaa...aa
 * @param n 一个数
 * @param a 一个数
 * @return 0
 */
int main() {
    int n;
    int a;
    printf("分别输入n和a: ");
    scanf("%d %d", &n, &a);
    int s = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = r * 10 + a;
        s += r;
    }
    printf("1到n的a的n次方之和为: %d\n", s);
    return 0;
}