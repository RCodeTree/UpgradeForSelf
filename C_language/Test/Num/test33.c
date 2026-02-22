#include <stdio.h>

/*
 * 从键盘输入5个整数，统计其中负数的个数
 */
int main() {
    int f = 0, n;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        if (n < 0) f++;
    }
    printf("%d\n", f);
    return 0;
}
