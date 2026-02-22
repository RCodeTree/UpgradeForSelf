#include <stdio.h>

int main() {
    int a, i;
    for (a = 1, i = -1; -1 <= i < 1; i++)
    {
        a++;
        printf("%d,", a);
    }
    printf("%2d\n", i);
    return 0;
}