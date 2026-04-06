#include "game.h"

// 初始化数组的内容为指定的内容
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

// 展示数组的内容
void ShowBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("----------------扫雷游戏-------------------\n");
    // 展示列号
    for (j = 0; j <= col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); // 展示行号
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("----------------扫雷游戏-------------------\n");
}

// 布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    int count = EASY_COUNT; // 布置10个雷
    while (count) // 当count为0时，跳出循环
    {
        i = rand() % row + 1;
        j = rand() % col + 1;
        if (mine[i][j] == '0')
        {
            mine[i][j] = '1';
            count--;
        }
    }
}

// 计算坐标(x,y)周围有多少个雷 --- 字符'1' - 字符'0' = 1 --- 将周围8个坐标上的字符'1' - 字符'0' = 1的结果累加起来
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return (
        mine[x-1][y-1] + 
        mine[x-1][y] + 
        mine[x-1][y+1] +
            mine[x][y-1] + 
            mine[x][y+1] +
            mine[x+1][y-1] + 
            mine[x+1][y] + 
            mine[x+1][y+1]
        ) - 8 * '0';
}



// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0; // 找到非雷的坐标的数量

    while (win < row * col - EASY_COUNT) // 当找到非雷的坐标的数量等于row * col - EASY_COUNT时，跳出循环
    {
        printf("请输入您要排查的坐标> ");
        scanf("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {

            if (show[x][y] != '*') // 玩家排查的坐标上已经被排查过了
            {
                printf("您已经排查过该坐标，请重新输入\n");
                continue;
            }
            else
            {

                if (mine[x][y] == '1') // 玩家排查的坐标上有雷
                {
                    printf("很遗憾，您被炸死了\n");
                    ShowBoard(mine, ROW, COL); // 当玩家被炸死时，展示布置好的雷的信息
                    break;
                }
                else // 玩家排查的坐标上没有雷
                {
                    win++; // 找到非雷的坐标的数量加1
                    int count = get_mine_count(mine, x, y); // 玩家排查的坐标上没有雷，计算该坐标周围有多少个雷
                    show[x][y] = count + '0'; // 将该坐标周围有多少个雷的信息展示在show数组中
                    ShowBoard(show, ROW, COL); // 展示排查出的雷的信息
                }
            }
        }
        else
        {
            printf("您输入的坐标有误，请重新输入\n");
        }
    }

        if (win == row * col - EASY_COUNT) // 当找到非雷的坐标的数量等于row * col - EASY_COUNT时，扫雷成功
        {
            printf("恭喜您，扫雷成功\n");
            ShowBoard(mine, ROW, COL); // 当扫雷成功时，展示布置好的雷的信息
        } 

}
 
