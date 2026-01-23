#include <stdio.h>

/** brief: 分解质因数
 * 功能：分解质因数
 * 输入：一个整数num
 * 输出：num的质因数分解结果
 */
int main() {
    int num, arr[20] = {0};
    printf("请输入一个数: ");
    scanf("%d", &num);
    if (num <= 0) return 1;
    int tmp = num;
    int flag = 1;
    int k = 0;
    for (int i = 2; i <= num; i++) {
        flag = 1;
        for (int j = 2; j < i; j++) {
            if (j == i) break;
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            while (1) { // 2是最小的质数，其实上面判断质数(素数)可以没有，因为在该while循环中已经将每个 i 的倍数都排除了，当 tmp 不能被 i 整除时，就要进行下一个 i ，即便遇到 i = 4 时，4 已经被排除了(前几次循环)，所以不会出现 4 整除 tmp 的情况
                if (tmp % i != 0) break;
                arr[k++] = i;
                tmp /= i;
            }
        }
    }
    printf("%d = ", num);
    for (int i = 0; i < k; i++) {
        if (i == (k - 1)) printf("%d\n", arr[i]);
        else printf("%d * ", arr[i]);
    }
    return 0;
}
