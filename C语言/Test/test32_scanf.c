#include <stdio.h>
int main()
{
    /* 
    scanf() 格式化输入

    */
    int x, y;
    double z;
    scanf("%d%lx,%le",&x,&y,&z);
    scanf("%2d * %d%lf",&x,&y,&z);
    scanf("%x%*d%o",&x,&y); // %*d 表示跳过一个十进制整数
    scanf("%x%o%6.2f",&x,&y,&z); // scanf() 输入时不允许指定浮点数的精度


    return 0;

}