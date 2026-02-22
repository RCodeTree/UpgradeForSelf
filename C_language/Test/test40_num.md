## 经典报错题
``` c
/* 
错误地方：
int ret = (++i) + (++i) + (++i);
对于不同的编译器，得出来的结果是不同的
因为对于不同的编译器，对++i的处理是不同的
不同的编译器对++i的计算顺序是不同的
所以该程序是会报错的
*/
#include <stdio.h>
int main()
{
    int i = 1;
    int ret = (++i) + (++i) + (++i);
    printf("%d\n", ret);
    return 0;
}
```