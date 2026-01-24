#include <stdio.h>
#include <math.h>

int main() {
    /* 
    exp() 计算e的x次幂, 返回值类型：double
    fabs() 计算浮点数的绝对值, 返回值类型：double
    log10() 计算以10为底的对数, 返回值类型：double
    pow() 计算x的y次幂, 返回值类型：double
    sqrt() 计算平方根, 要求参数为非负数, 返回值类型：double
    atan2() 计算y/x的反正切（考虑象限）, 返回值类型：double
    */

    /* 
    A：完全正确，exp()计算e^0.5，fabs()计算|10|

    B：语法错误，\log10应为log10，且pow()缺少参数

    C：运行时问题，sqrt()参数为负数产生NaN

    D：语法正确，但atan2参数顺序非常规（第一个是y坐标，第二个是x坐标）
    */



    double y = 0.5, z = 1.5;
    int x = 10;
    double result;
    
    printf("初始值: y=%.1f, z=%.1f, x=%d\n\n", y, z, x);
    
    // A) z = exp(y) + fabs(x);
    printf("A) z = exp(y) + fabs(x)\n");
    z = exp(y) + fabs(x);
    printf("计算结果: z = exp(%.1f) + fabs(%d) = %.6f\n", y, x, z);
    printf("状态: 语法正确，数学上有效 ✓\n\n");
    
    // 恢复初始值
    y = 0.5; z = 1.5; x = 10;
    
    // B) y = log10(y) + pow(y);
    printf("B) y = log10(y) + pow(y)\n");
    y = log10(y) + pow(y);
    printf("问题2: pow(y) 参数不足，pow需要两个参数\n");
    // 正确写法应该是：y = log10(y) + pow(y, 2.0);
    // 但原语句有语法错误，无法编译
    printf("状态: 语法错误，无法编译 ✗\n\n");
    
    // 恢复初始值
    y = 0.5; z = 1.5; x = 10;
    
    // C) z = sqrt(y - z);
    printf("C) z = sqrt(y - z)\n");
    printf("计算: y - z = %.1f - %.1f = %.1f\n", y, z, y-z);
    printf("问题: sqrt(%.1f) 参数为负数\n", y-z);
    z = sqrt(y - z);
    printf("结果: z = %f (NaN)\n", z);
    printf("状态: 运行时产生NaN，数学上无效 ✗\n\n");
    
    // 恢复初始值
    y = 0.5; z = 1.5; x = 10;
    
    // D) x = (int)(atan2((double)x, y) + exp(y - 0.2));
    printf("D) x = (int)(atan2((double)x, y) + exp(y - 0.2))\n");
    double atan2_result = atan2((double)x, y);  // atan2(y坐标, x坐标)
    double exp_result = exp(y - 0.2);
    printf("atan2(%.1f, %.1f) = %.6f\n", (double)x, y, atan2_result);
    printf("exp(%.1f - 0.2) = exp(%.1f) = %.6f\n", y, y-0.2, exp_result);
    printf("总和 = %.6f\n", atan2_result + exp_result);
    x = (int)(atan2_result + exp_result);
    printf("转换为int: x = %d\n", x);
    printf("状态: 语法正确，数学上有效 ✓\n");
    
    return 0;
}