#include <stdio.h>

int main() {
    int a[3][2] = {{0, 1}, {2, 3}, {4, 5}}; // 初始化数组a
    int *p;
    p = a[0]; // 指向数组a的第一行，实际上也是指向数组a的第一个元素的地址
    printf("%d\n", p[0]); // 1
    return 0;
}
