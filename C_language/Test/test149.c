#include <stdio.h>

/*
 * 程序功能：根据输入的a、b、c，计算s、w、t的值。
 * 其中，s表示a+b，w表示a-b，t表示c。
 * 输入：三个整数a、b、c。
 * 输出：三个整数s、w、t。
 */
int main() {
    int a, b, c;
    int s, w, t;
    s = w = t = 0;
    a = -1;
    b = 3;
    c = 3;
    if (c > 0) s = a + b;
    if (a <= 0) {
        if (b > 0)
            if (c <= 0) w = a - b;
    } else if (c > 0) w = a - b;
    else t = c;
    printf("%d %d %d\n", s, w, t);
    return 0;
}
