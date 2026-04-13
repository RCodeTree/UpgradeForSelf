#include <stdio.h>
#include <string.h>

#define MAX 105  // 最多100位，结果可能101位，多留一些空间
#define RES_MAX 205  // 乘积最大位数（100+100）

void addLargeNumbers(char a[], char b[]) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int numA[MAX] = {0}, numB[MAX] = {0}, result[MAX] = {0};

    // 将字符串逆序存入整型数组，低位在前
    for (int i = 0; i < lenA; i++)
        numA[i] = a[lenA - 1 - i] - '0';
    for (int i = 0; i < lenB; i++)
        numB[i] = b[lenB - 1 - i] - '0';

    int maxLen = (lenA > lenB) ? lenA : lenB;
    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int sum = numA[i] + numB[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        result[maxLen] = carry;
        maxLen++;
    }

    // 输出结果（逆序转回高位在前）
    printf("和为: ");
    for (int i = maxLen - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

void multiplyLargeNumbers(char a[], char b[]) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int numA[MAX] = {0}, numB[MAX] = {0}, result[RES_MAX] = {0};

    // 逆序存储，低位在前
    for (int i = 0; i < lenA; i++)
        numA[i] = a[lenA - 1 - i] - '0';
    for (int i = 0; i < lenB; i++)
        numB[i] = b[lenB - 1 - i] - '0';

    // 模拟竖式乘法
    for (int i = 0; i < lenA; i++) {
        int carry = 0;
        for (int j = 0; j < lenB; j++) {
            int product = numA[i] * numB[j] + result[i + j] + carry;
            result[i + j] = product % 10;
            carry = product / 10;
        }
        if (carry) {
            result[i + lenB] += carry;
        }
    }

    // 找到结果的最高非零位
    int resLen = RES_MAX - 1;
    while (resLen > 0 && result[resLen] == 0) {
        resLen--;
    }

    // 输出结果（逆序）
    printf("积为: ");
    for (int i = resLen; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    char a[MAX], b[MAX];
    printf("请输入第一个整数（不超过100位）: ");
    scanf("%s", a);
    printf("请输入第二个整数（不超过100位）: ");
    scanf("%s", b);

    if (strlen(a) > 100 || strlen(b) > 100) {
        printf("输入超过100位！\n");
        return 1;
    }
    addLargeNumbers(a, b);
    return 0;
}
