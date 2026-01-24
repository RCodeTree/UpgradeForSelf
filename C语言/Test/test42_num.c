/*
输入描述：
多组输入
一个整数（2~20）
表示输出的行数，也表示组成"X"的反斜线和正斜线的长度

输出描述：
针对每行输入，输出用"*"组成的X形图案
    *   *
     * *
      *
     * *
    *   *
*/

/* 
解题思路：
想象一个num * num的矩阵，使用坐标(i, j)表示矩阵中的每个元素
当i == j时，输出"*"
当i + j == num - 1时，输出"*"
否则输出" "，用于填充其他位置
从而得到 X形图案 的结果

    0 1 2 3 4
  0 * * * * *
  1 * * * * *
  2 * * * * *
  3 * * * * *
  4 * * * * *

*/
#include <stdio.h>
int main()
{
	unsigned int num;

    while(scanf("%u", &num) != EOF)
    {
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num; j++)
            {
                if(i == j)
                {
                    printf("*");
                }
                else if(i + j == num - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }

            printf("\n");
        }
    }

	return 0;
}
