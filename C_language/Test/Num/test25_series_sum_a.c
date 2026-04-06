#include <stdio.h>
/**
 * @brief 输入a和n，计算a+aa+aaa+...+aa...a(n个a)的值
 *
 * @return int 0
 */
int main() {
    int a, n, num = 0;
    printf("请输入a的值：");
    scanf("%d", &a);
    printf("请输入n的值：");
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        num = num * 10 + a;
        s += num;
    }
    printf("s的值为：%d\n", s);
    return 0;
}
