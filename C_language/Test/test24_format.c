#include <stdio.h>
int main()
{
    /* 
    printf() 格式化输出
    */


    long y = -43456;
    printf("y=%-8ld\n", y); // -43456空格空格
    printf("y=%-08ld\n", y); // -43456空格空格
    printf("y=%08ld\n", y); // 00-43456
    printf("y=%+8ld\n", y); // 空格空格-43456


    return 0;
}