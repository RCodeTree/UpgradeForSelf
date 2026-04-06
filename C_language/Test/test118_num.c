#include <stdio.h>

/**
 * 从键盘输入10个整数，统计其中大于0的数的个数和它们的和
 * @return 0
 */
int main() {
    int c = 0;
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        int n;
        printf("请输入第%d个整数:", i);
        scanf("%d", &n);
        if (n > 0) {
            c++;
            sum += n;
        }
    }
    printf("输入的%d个整数中，有%d个大于0的数，它们的和为：%d\n", c, c, sum);
    return 0;
}
