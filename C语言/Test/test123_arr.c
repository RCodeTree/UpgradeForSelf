#include <stdio.h>

/**
 * @brief 打印3*3矩阵
 * @param a 3*3矩阵
 * @param sum 非对角线上元素之和
 * @return 0
 */
int main() {
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("-------------------\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) printf("%d ", a[i][j]);
            else printf("  ");
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j)
                sum += a[i][j];
    printf("非对角线上元素之和: %d\n", sum);
    return 0;
}
