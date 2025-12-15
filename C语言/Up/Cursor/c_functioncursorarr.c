#include <stdio.h>

int func1(int a) {
    printf("func1: %d\n", a);
}

int func2(int a) {
    printf("func2: %d\n", a);
}

int main() {
    int (*pf)(int) = func1;
    int (*pfarr[])(int) = {func1, func2};
    for (int i = 0; i < 2; i++) {
        pfarr[i](i);
        /* 
        result:
        func1: 0
        func2: 1
        */
    }

    return 0;
}
