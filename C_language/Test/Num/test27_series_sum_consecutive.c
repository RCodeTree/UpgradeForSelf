#include <stdio.h>
/*
 * @brief 计算n个连续数的累加和，例如输入3，计算1+12+123
 */
int main() {
    int num = 0;
    int sum = 0;
    int n;
    printf("输入数的个数: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        num = num * 10 + i;
        sum += num;
    }
    printf("累加和为：%d\n", sum);
    return 0;
}
