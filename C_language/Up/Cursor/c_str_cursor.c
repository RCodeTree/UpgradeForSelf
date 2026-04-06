#include <stdio.h>

/*
 * 指针数组的游标移动
 */
int main() {
    char *a[] = {"work", "at", "alibaba"};
    char **pa = a;

    pa++;
    printf("%s\n", *pa); // at
    return 0;
}
