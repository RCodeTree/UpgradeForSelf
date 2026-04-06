#include <stdio.h>

/*
 * 指针数组的游标移动
 */
int main() {
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;
    printf("%s\n", **++cpp); // POINT
    printf("%s\n", *--*++cpp + 3); // ER
    printf("%s\n", *cpp[-2] + 3); // ST
    printf("%s\n", cpp[-1][-1] + 1); // EW
    return 0;
}
