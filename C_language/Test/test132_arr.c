#include <stdio.h>

/**
 * 数组元素的差分数组 --- 差分数组的第i个元素为原数组的第i个元素与第i-1个元素的差
 * @return 0
 */
int main() {
    int a[] = {51, 62, 78, 21, 7, 5, 100, 201, 11, 20};
    int len = sizeof(a) / sizeof(a[0]);
    int b[10] = {0};
    for (int k = 1; k < len; k++) {
        b[k] = a[k] / a[k - 1];
    }
    for (int q = 1; q < len; q++) {
        printf("%d ", b[q]);
        if (q % 3 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}
