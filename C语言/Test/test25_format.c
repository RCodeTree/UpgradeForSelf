#include <stdio.h>
int main()
{
    /* 
    printf() 格式化输出
    */


    int y = 2456; // 八进制：4630
    printf("y=%3o\n", y); // 4630
    printf("y=%8o\n", y); // 空格空格空格空格4630
    printf("y=%#8o\n", y); // 空格空格空格04630


    return 0;

}