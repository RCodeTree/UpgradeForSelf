#include <stdio.h>

/**
 * 二分查找数组中的数字
 * @return 0
 */
int main() {
    int a[] = {2, 4, 9, 11, 13, 40, 51, 60, 90, 100};
    int len = sizeof(a) / sizeof(a[0]);
    int low = 0, high = len - 1, mid;
    int num;
    printf("输入要查找的数字：");
    scanf("%d", &num);
    while (low <= high) {
        mid = (low + high) / 2;
        if (num == a[mid]) {
            break; // 找到目标，跳出循环
        } else if (num > a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (low > high)
        printf("未找到数字 %d\n", num);
    else
        printf("找到数字 %d，下标为 %d\n", num, mid);
    return 0;
}
