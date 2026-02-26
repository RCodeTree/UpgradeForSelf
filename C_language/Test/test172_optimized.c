#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("请输入一个正整数: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("请输入正整数！\n");
        return 1;
    }
    
    printf("%d的质数因子为: ", n);
    
    // 处理2这个特殊的质数
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    
    // 处理奇数因子（更高效的算法）
    int i = 3;
    while (i * i <= n) {
        if (n % i == 0) {
            printf("%d ", i);
            n /= i;
        } else {
            i += 2;  // 只检查奇数
        }
    }
    
    // 如果剩下的n大于1，那么它本身就是一个质数
    if (n > 1) {
        printf("%d", n);
    }
    
    printf("\n");
    return 0;
}