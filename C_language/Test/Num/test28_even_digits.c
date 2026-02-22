#include <stdio.h>

unsigned long fun(unsigned long n) {
    unsigned long x = 0, s, i;
    int t;
    s = n;
    i = 1; //
    while (s) // 或者 while (s > 0)
    {
        t = s % 10;
        if (t % 2 == 0) {
            x = x + t * i;
            i = i * 10; //
        }
        s = s / 10;
    }
    return x;
}

int main() {
    unsigned long n = 1234567890;
    unsigned long x = fun(n);
    printf("%lu\n", x);
    return 0;
}
