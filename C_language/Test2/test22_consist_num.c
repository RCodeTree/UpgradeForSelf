#include <stdio.h>

// 0-19 的单词
const char *ones[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
    "SIX", "SEVEN", "EIGHT", "NINE", "TEN",
    "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN",
    "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
};

// 20,30,...,90 的单词
const char *tens[] = {
    "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY",
    "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
};

// 输出数字 n (0-999) 的英文表示
void print_number(int n) {
    if (n >= 100) {
        int hundred = n / 100;
        printf("%s HUNDRED", ones[hundred]);
        n %= 100;
        if (n > 0) {
            printf(" ");
            if (n < 20) {
                printf("%s", ones[n]);
            } else {
                int ten = n / 10;
                int one = n % 10;
                printf("%s", tens[ten]);
                if (one > 0) {
                    printf(" %s", ones[one]);
                }
            }
        }
    } else { // n < 100
        if (n < 20) {
            printf("%s", ones[n]);
        } else {
            int ten = n / 10;
            int one = n % 10;
            printf("%s", tens[ten]);
            if (one > 0) {
                printf(" %s", ones[one]);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    // 题目保证 N 为正整数且 < 1000，无需额外错误处理
    print_number(N);
    printf("\n");
    return 0;
}
