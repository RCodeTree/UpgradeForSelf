#include <stdio.h>

int main()
{
    /* 
    二维数组在内存中是“拉直”存放的
    假设数组有 m 行 n 列（即每行有 n 个元素）。我们要找 x[i][j] ：
        i * n （跳过完整的行） ：
            在到达第 i 行之前，必须先跳过前面的 0 到 i-1 行。每行都有 n 个元素，所以一共跳过了 i × n 个元素。
        + j （当前行的偏移） ：
            到达第 i 行的开头后，目标元素是该行的第 j 个（从 0 开始），所以再往后数 j 步。
    */

    // 模拟图片中的 3行 4列 数组 (m=3, n=4)
    // 1  2  3  4
    // 5  6  7  8
    // 9 10 11 12
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int m = 3; // 总行数
    int n = 4; // 总列数 (公式中的关键参数)

    printf("二维数组内容 (3行4列):\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%-3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("验证公式: 位置索引 = i * n + j\n");
    printf("其中 n = %d (每行的列数)\n\n", n);
    printf("| 数值 | 行号(i) | 列号(j) | 计算索引 (i*%d+j) | 实际内存验证 |\n", n);
    printf("|-----|--------|--------|------------------|-------------|\n");

    // 使用一维指针指向数组首地址，验证线性存储
    int *p = &arr[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int calculated_index = i * n + j; // 套用图片公式
            int actual_value = arr[i][j];
            
            // 验证：通过首地址 + 计算出的索引，是否能取到同一个值
            int value_from_linear = *(p + calculated_index);
            
            printf("| %-3d | %-6d | %-6d | %-16d | %s (值:%d) |\n", 
                   actual_value, i, j, calculated_index, 
                   (actual_value == value_from_linear ? "通过" : "失败"),
                   value_from_linear);
        }
    }

    return 0;
}
