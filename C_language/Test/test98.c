#include <stdio.h>

void fun(int (*a)[5]) {
    int i, j, k, m;
    if (5 % 2 == 0) m = 5 / 2;
    else m = 5 / 2 + 1;
    for (int i = 0; i < m; i++) {
        for (j = i; j < 5 - i; j++)
            a[i][j] = a[5 - 1 - i][j] = i + 1;
        for (k = i + 1; k < 5 - i; k++)
            a[k][i] = a[k][5 - i - 1] = 1 + i;
    }
}

int main() {
    int a[5][5] = {0};
    fun(a);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
