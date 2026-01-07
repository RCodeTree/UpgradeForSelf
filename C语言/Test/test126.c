#include <stdio.h>
#define M 3
#define N 5

void fun(int (*a)[N], int k) {
    int i, j, p, temp;
    for (p = 1; p <= k; p++)
        for (i = 0; i < M; i++) {
            temp = a[i][0];
            for (j = 0; j < N - 1; j++)
                a[i][j] = a[i][j + 1];
            a[i][N - 1] = temp;
        }
}

int main() {
    int a[M][N] =
    {
        {5, 4, 3, 1, 2},
        {5, 4, 3, 1, 2},
        {5, 4, 3, 1, 2},
    };
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
    fun(a, 3);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
