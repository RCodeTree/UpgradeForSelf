#include <stdio.h>

int main() {
    static int n = 1;
    int a[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = n++;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    return 0;
}
