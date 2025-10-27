// 输入一个数字，如：1234，然后输出每一个数字
#include <stdio.h>

/* 
该递归执行原理：
1、当num > 9时，递归调用printNum(num / 10)，直到num <= 9
2、当num <= 9时，打印num % 10，然后返回
3、当num = 0时，递归结束

该递归详细执行过程和返回过程：
1、当num = 1234时，printNum(1234)，num > 9，执行printNum(1234 / 10) = printNum(123)
2、当num = 123时，printNum(123)，num > 9，执行printNum(123 / 10) = printNum(12)
3、当num = 12时，printNum(12)，num > 9，执行printNum(12 / 10) = printNum(1)
4、当num = 1时，printNum(1)，num <= 9，打印num % 10 = 1，然后返回
5、返回printNum(12)，打印num % 10 = 2，然后返回
6、返回printNum(123)，打印num % 10 = 3，然后返回
7、返回printNum(1234)，打印num % 10 = 4，然后返回
8、递归结束
9、打印结果：4 3 2 1
*/
void printNum(unsigned int num)
{
    if (num > 9)
    {
        printNum(num / 10);
    }
    printf("%d\n", num % 10);
}

int main()
{
    /*
    num / 10 能获取到数的前几位，除了最后一位
    num % 10 能获取到数的最末一位
    num / 10 和 num % 10 结合使用，可以获取到数的每一位
    */



    unsigned int num;

    printf("请输入一个数字> ");
    scanf("%u", &num); // %d 是用于输入整数，%u 是用于输入无符号整数

    printNum(num);
    

    return 0;
}