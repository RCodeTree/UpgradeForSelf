#include <stdio.h>

/**
 * 从键盘输入5个整数，将它们逆序输出
 * @return 0
 */
int main() {
    int a[5] = {0};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) scanf("%d", &a[i]);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < 5 / 2; i++) {
        int t = a[i];
        a[i] = a[sizeof(a) / sizeof(a[0]) - 1 - i];
        a[sizeof(a) / sizeof(a[0]) - 1 - i] = t;
    }
    printf("逆序后：\n");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
