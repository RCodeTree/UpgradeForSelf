#include <stdio.h>
int main()
{
    /* 
    逗号操作符：
    exp1, exp2, exp3, ...  ---->  从左到右依次执行每个表达式，最后返回最后一个表达式的结果
    */
    
    // 示例
    int a = 10, b = 20, c = 0;
    c = (a++, b++, a + b);
    printf("%d\n", c); // 输出结果为 40
}