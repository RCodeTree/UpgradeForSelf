

#include <stdio.h>

int main(void)
{
    int x, y;

    scanf("%d%d", &x, &y); // 未指定输入格式，默认以空格或换行符分隔

    printf("x=%d, y=%d\n", x, y);

    return 0;
}