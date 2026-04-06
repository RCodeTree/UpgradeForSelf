#include <stdio.h>

/*
 * 功能：查找二维数组中的最小值及其所在的行号和列号
 * 输入：一个3行4列的二维数组a
 * 输出：最小值min，所在的行号row，所在的列号col
 */
int main()
{
    int i, j, row, col, min;
    int a[3][4] = {{1, 2, 3, 4}, {9, 8, 6, 7}, {-1, -2, 7, -5}};
    min = a[0][0];
    row = 0;
    col = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                row = i;
                col = j;
            }
        }
    }
    printf("min = %d, row = %d, col = %d\n", min, row, col); // min = -2, row = 2, col = 1
    return 0;
}
