#include <stdio.h>
int main()
{
    /*
    算术运算符：
    + 加法
    - 减法
    * 乘法
    / 除法
    % 取余（取模） ----> 该操作符两端操作数必须为整数，结果为两个操作数相除的余数
    */ 

    /* 
     错误示例 ----> 编译时会报错

    float a = 10.0;
    float b = 3.0;
    float c = a % b; 
    printf("%f\n", c);

    o1.c: In function ‘main’:
    o1.c:16:17: error: invalid operands to binary % (have ‘float’ and ‘float’)
      |     float c = a % b;
      |                 ^
    */


    // 正确示例
    int a1 = 10;
    int b1 = 3;
    int c1 = a1 % b1;
    printf("%d\n", c1); // 输出结果为 1
    return 0;
}