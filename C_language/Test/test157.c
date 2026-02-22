#include  <stdio.h>

void main() {
    int i = 1;
    while (i <= 15)
        if (++i % 3 != 2)
            continue;
        else
            printf("%d\t", i);
    printf("\n");
}
