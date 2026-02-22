#include <stdio.h>

int main() {
    static int n = 1;
    int a[2][3];
    for (int i = 0; i < 2; i++) // 按行遍历
        for (int j = 0; j < 3; j++)
            a[i][j] = 2 * n++;

    // 按行输出
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    printf("--------------\n");

    // 按列输出 --- 即转置输出
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d\t", a[j][i]);
        printf("\n");
    }
    return 0;
}
