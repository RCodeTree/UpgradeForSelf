#include <stdio.h>

int main() {
    int i;
    for (i = 1; i <= 5; i++)
        switch (i % 2) {
            case 0:
                i++;
                printf("#");
                break;
            case 1:
                i += 2;
                printf("*");
            default:
                printf("\n");
        }
    return 0;
}
