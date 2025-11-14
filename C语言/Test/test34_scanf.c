#include <stdio.h>
int main()
{

    /* 
    scanf() 格式化输入
    %3d 读3个整数，跳过前导空白（空格、制表符、换行等）。

    %f 读浮点数，跳过前导空白(包括空格、制表符、换行等)。
    */
    int x;
    float y;

    scanf("%3d%f", &x, &y); // 输入：12345 678
    printf("%d\n%f\n", x, y); // 输出：123 45.000000
    return 0;
}