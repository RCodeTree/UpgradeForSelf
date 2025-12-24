#include <stdio.h>
#include <math.h>

/*
 * @brief 回文数是指正读和反读都一样的数。
 * 例如：12321是回文数，123不是回文数。
 */
int backNum(int num) {
    if (num < 10) return 0;
    int back = 0;
    int tmp = num;
    while (tmp) {
        back = back * 10 + tmp % 10;
        tmp /= 10;
    }
    if (back != num) return 0;
    return 1;
}

/*
 * @brief 素数是指只能被1和本身整除的数。
 * 例如：2、3、5、7、11、13、17、19、23、29等都是素数。
 */
int suNum(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

/**
 * @brief 回文数和素数的组合数 是指既是回文数又是素数的数。
 * 例如：131是回文数又是素数。
 *
 * @return int 0
 */
int main() {
    int num = 0;
    for (num = 1; num < 1000; num++)
        if (backNum(num) && suNum(num))
            printf("%d\n", num);
    return 0;
}
