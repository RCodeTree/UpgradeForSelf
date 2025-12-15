#include <stdio.h>
#include <stdlib.h>


int main() {
    // int m;
    // for (m = 1; m <= 50; m++) {
    //     if (m % 12 != 0)
    //         continue;
    //     printf("%4d", m); // 空格空格12空格空格24空格空格36空格空格48
    // }
    // printf("\n");

    // int *a, *b, *c;
    // a = (int *) malloc(sizeof(int));
    // b = c = a;
    // *a = 3;
    // *b = 4;
    // *c = 5;
    // printf("%d %d %d\n", *a, *b, *c); // 5 5 5

    /*
    fun:
    void fun(int a[]) {
        a[2] = a[0] + a[1];
    }

    main:
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun(&a[2]);
    printf("%d\n", a[4]);
    */


    /*
    fun:
    void fun(int b[]) {
        int k;
        for (k = 2; k < 6; k++)
            b[k] = b[k] * 2;
    }

    main:
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    fun(a);
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    printf("\n");
    */

    /*
    fun:
    void fun(char *p, char t) {
        while (*p) {
            if (*p == t)
                *p = t - 'a' + 'A';
            p++;
        }
    }

    main:
    char s[20] = "abcdab", c = 'a';
    fun(s, c);
    printf("%s\n", s);
    */

    return 0;
}
