#include <stdio.h>

int main() {
    float a = 123.456;
    double b = 8765.4567;

    printf("(1) %f\n", a);
    printf("(2) %14.3f\n", a);
    printf("(3) %6.4f\n", a);
    printf("(4) %lf\n", b);
    printf("(5) %14.3lf\n", b);
    printf("(6) %8.4lf\n", b);
    printf("(7) %.4f\n", b);

    return 0;
}