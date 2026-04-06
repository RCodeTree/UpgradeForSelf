#include <stdio.h>

int main() {
    int a[6], i, j, k, m;
    for (i = 0; i < 6; i++) scanf("%d", &a[i]);
    for (i = 5; i >= 0; i--) {
        k = a[5];
        for (j = 4; j >= 0; j--)
            a[j + 1] = a[j];
        a[j + 1] = k; // 或者 a[0] = k;
    }
    for (m = 0; m < 6; m++)
        printf("%d ", a[m]);
    printf("\n");
    return 0;
}
