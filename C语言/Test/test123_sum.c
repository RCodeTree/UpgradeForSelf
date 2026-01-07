#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            sum += a[i][j];
        }
    }
    printf("三阶矩阵上三角之和: %d\n", sum);
    return 0;
}
