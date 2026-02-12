#include <stdio.h>

int main() {
    int a[5] = {
        4,
        7, 8, 2, 5
    };
    int i, j, m;
    for (i = 1; i < 5; i++) {
        m = a[i];
        j = i - 1;
        while (j >= 0 && m > a[j]) {
            a[j + 1] = a[j]; // error: a[i] = a[j]
            j--;
        }
        a[j + 1] = m;
    }
    for (i = 0; i < 5; i++)
        printf("%3d", a[i]);
    printf("\n");
    return 0;
}
