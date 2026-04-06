#include <stdio.h>

int main() {
    // 题目要求：使 a 的高 8 位翻转，低 8 位不变
    // 假设 a 是一个 16 位整数 (unsigned short)
    unsigned short a = 0x1234; // 二进制: 0001 0010 0011 0100
    
    // b 的八进制形式是 177400
    // 在 C 语言中，八进制常量以 0 开头
    // 177400 (8进制) = 1111 1111 0000 0000 (2进制) = FF00 (16进制)
    unsigned short b = 0177400; 

    // 进行异或运算
    unsigned short result = a ^ b;

    printf("验证第 11 题：\n");
    printf("原始 a (16进制): %04X\n", a);
    printf("掩码 b (8进制): %o\n", b);
    printf("掩码 b (16进制): %04X\n", b);
    printf("结果 (16进制): %04X\n", result);
    printf("------------------------------\n");
    printf("分析：\n");
    printf("高 8 位原始: %02X, 结果: %02X (翻转)\n", (a >> 8) & 0xFF, (result >> 8) & 0xFF);
    printf("低 8 位原始: %02X, 结果: %02X (不变)\n", a & 0xFF, result & 0xFF);

    return 0;
}
