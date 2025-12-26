#include <stdio.h>

/*
 * @brief 判断一个整数是否是素数
 *
 * @return int 0
 */
int main() {
    int n = 0;
    printf("请输入一个整数:");
    scanf("%d", &n);
    int flag = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            flag = 0;
        }
    }
    if (flag) printf("%d是素数\n", n);
    else printf("%d不是素数\n", n);
    return 0;
}
