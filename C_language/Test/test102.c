#include <stdio.h>

double f(double x);

void main() {
    double a = 0;
    for (int i = 0; i < 30; i += 10) {
        a += f((double) i);
    }
    printf("%3.0f\n", a); // 503
}

double f(double x) {
    return x * x + 1;
}
