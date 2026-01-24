#include <stdio.h>

void fun(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if ((i + 1) % 5 == 0)
            printf("\n");
        printf("%d ", a[i]);
    }
}

int main() {
    int a[50] = {0};
    for (int i = 0; i < 50; i++)
        a[i] = i;
    fun(a, 50);
    return 0;
}
