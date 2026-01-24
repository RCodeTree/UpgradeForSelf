// 运行以下程序，写出运行结果，注意静态局部变量和动态局部变量的特点。
#include <stdio.h>
int fun()
{
    auto a=0;
    int b=0;
    static c=0;
    extern d; /* 因为变量 d 定义在后，需对变量 d 进行声明 */
    a++;b++;c++;
    return a+b+c+d;
}
int d=10; /* 定义变量 d 为全局变量 */
void main()
{
    int i;
    int d=8;
    for(i=1;i<=3;i++)
    printf("第 %d 次调用 fun()函数的值：%d,变量 d 的值:%d\n",i,fun(),d);
    /* 
    第 1 次调用 fun()函数的值：13,变量 d 的值:8
    第 2 次调用 fun()函数的值：14,变量 d 的值:8
    第 3 次调用 fun()函数的值：15,变量 d 的值:8
    */
}