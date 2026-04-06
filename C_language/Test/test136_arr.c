#include <stdio.h>

int main() {
    int a[9] = {11, 23, 41, 27, 42, 64, 82, 59};
    int i = 0, x;
    scanf("%d", &x);
    // int len = sizeof(a) / sizeof(a[0]); error
    a[8] = x;
    while (a[i] != x) i++;
    if (i < 8)
        printf("找到 %d ，下标为 %d\n", x, i);
    else
        printf("未找到 %d\n", x);
    return 0;
}
