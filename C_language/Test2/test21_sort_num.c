#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100 // 给数组元素分配连续编号的函数

void assignNumber(int A[], int result[], int n)
{
    // 用于标记元素是否已经处理过
    int processed[MAX_N] = {0};
    int currentRank = 1; // 按从小到大的顺序依次分配编号

    for (int rank = 0; rank < n; rank++)
    {
        // 找到当前未处理的最小元素
        int minVal = 0;
        /* 
        found 变量的关键作用：(起标记作用)
        1. 初始化最小值
        - !found ：当第一次找到未处理的元素时，直接将其设为最小值
        - found = 1 ：标记已经找到第一个元素，后续需要比较大小 
        2. 避免初始值干扰
        - minVal = 0 ：初始值设为 0，但如果数组中没有负数，直接比较 A[i] < minVal 会出错
        - !found ：确保第一个未处理的元素被正确设为最小值，无论其值是多少
        - found = 0 ：表示还未找到任何未处理的元素
        */
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (!processed[i])
            {
                if (!found || A[i] < minVal)
                {
                    minVal = A[i];
                    found = 1;
                }
            }
        }

        // 给所有等于当前最小值的元素分配编号
        for (int i = 0; i < n; i++)
        {
            if (A[i] == minVal && !processed[i])
            {
                result[i] = currentRank;
                processed[i] = 1;
            }
        }
        currentRank++;
    }
}

int main()
{
    int A[MAX_N], result[MAX_N];
    int n;
    printf("请输入数组元素个数N(0<N<100): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 100)
    {
        printf("输入的N不合法，请输入0到100之间的整数n");
        return 1;
    }
    printf("请输入%d个整数元素: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    } // 调用编号分配函数
    assignNumber(A, result, n);
    printf("编号结果为: (");
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf("，");
        }
        printf("%d", result[i]);
    }
    printf(")\n");
    return 0;
}
