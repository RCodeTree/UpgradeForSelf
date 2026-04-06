#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("输入一个整数: ");
    scanf("%d", &n); // 123
    int result = 0;
    int i = 0;
    while (n) {
        /*
        // 存在bug
        if ((n % 10) % 2 == 0) {
            result = result * 10 + 0;
        } else {
            result = result * 10 + 1;
        }
        n /= 10;
        */
        if ((n % 10) % 2 == 1) {
            result += 1 * pow(10, i);
            i++;
        } else {
            result += 0 * pow(10, i);
            i++;
        }
        n /= 10;
    }
    printf("%d\n", result);
    return 0;
}
