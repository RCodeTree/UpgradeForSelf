#include <stdio.h>

/**
 *
 * @param x
 * @param y
 * @return
 */
double mypow(double x, int y) {
    double powFormy = 1.0;
    while (y--) powFormy *= x;
    return powFormy;
}

int main() {
    double r = mypow(0.2, 2);
    printf("%lf\n", r);
    return 0;
}
