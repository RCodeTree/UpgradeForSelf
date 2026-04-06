#include <stdio.h>

#define INF 0x3f3f3f3f      // 定义无穷大，0x3f3f3f3f 是一个足够大的整数
#define min(a,b) (a<b?a:b)  // 取最小值的宏，方便代码书写

int main()
{
    // ---------- 1. 定义变量 ----------
    int N; // 总楼层数
    int A, B; // 起点 A，终点 B
    int K[1005]; // 每层楼的数字，下标从1开始
    int dp[1005]; // dp[i]：从 A 到 i 的最少按钮次数

    // ---------- 2. 输入数据 ----------
    printf("请输入总楼层数N、起点A、终点B：");
    scanf("%d%d%d", &N, &A, &B);
    printf("请输入每层楼的数字K1~KN：");
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &K[i]);
    }

    // ---------- 3. 初始化 DP 数组 ----------
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INF; // 一开始所有楼层都不可达
    }
    dp[A] = 0; // 起点本身不需要按按钮

    // ---------- 4. 递推更新（核心部分） ----------
    // 外层循环 N 次：保证所有可能的最短路径都被找到
    for (int i = 1; i <= N; i++)
    {
        // 内层循环：遍历每一层，尝试用当前已知的最优步数去更新它的邻居
        for (int y = 1; y <= N; y++)
        {
            // 如果当前楼层 y 还到不了，跳过
            if (dp[y] == INF) continue;

            int up = y + K[y]; // 按“上”能到达的楼层
            int down = y - K[y]; // 按“下”能到达的楼层

            // 更新上层（如果合法）
            if (up >= 1 && up <= N)
            {
                dp[up] = min(dp[up], dp[y] + 1);
            }
            // 更新下层（如果合法）
            if (down >= 1 && down <= N)
            {
                dp[down] = min(dp[down], dp[y] + 1);
            }
        }
    }

    // ---------- 5. 输出结果 ----------
    if (dp[B] == INF)
    {
        printf("无法从%d楼到达%d楼\n", A, B);
    }
    else
    {
        printf("从%d楼到%d楼最少需要按 %d 次按钮\n", A, B, dp[B]);
    }

    return 0;
}
