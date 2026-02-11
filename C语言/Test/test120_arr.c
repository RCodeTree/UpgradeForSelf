#include <stdio.h>

int sum(int *a);

/**
 * 从键盘输入5个整数，计算它们的和
 * @return 0
 */
int main() {
    int a[5];
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个整数:", i + 1);
        scanf("%d", &a[i]);
    }
    int s = sum(a);
    printf("数组a中所有元素的和为：%d\n", s);
    return 0;
}

/*
 * 计算数组a中所有元素的和
 * @param a 数组a
 * @return 数组a中所有元素的和
 */
int sum(int *a) {
    int s = 0;
    for (int i = 0; i < 5; i++) {
        s += a[i];
    }
    return s;
}
