#include <stdio.h>

/* 
    枚举类型是一种用户自定义的类型，它可以定义一个枚举常量的集合。
    枚举类型的每个枚举常量都有一个整数值，默认从0开始递增。
    如果在定义枚举类型时指定了枚举常量的值，那么后续的枚举常量的值会依次递增。

    优点：
    1. 枚举类型可以使代码更加易读和维护。
    2. 枚举类型可以限制变量的取值范围，避免了无效的赋值。
*/
enum Day{
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};

int main()
{
    enum Day d = Mon;
    printf("%d\n", d); // 0
    printf("%d\n", Tue); // 1
    return 0;
}