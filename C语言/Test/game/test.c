#include "game.h"

/*
    菜单函数
*/
void menu()
{
    printf("------------------\n");
    printf("1. 开始游戏\n");
    printf("0. 退出游戏\n");
    printf("------------------\n"); 
}

/*
    游戏函数
*/
void game()
{
    char mine[ROWS][COLS] = {0}; // 存放布置好的雷的信息
    char show[ROWS][COLS] = {0}; // 存放排查出的雷的信息

    // 初始化数组的内容为指定的内容
    // mine 数组在没有布置雷的情况下，内容为 '0'
    InitBoard(mine, ROWS, COLS, '0');
    // show 数组在没有排查出雷的情况下，内容为 '*'
    InitBoard(show, ROWS, COLS, '*');

    // 布置雷
    SetMine(mine, ROW, COL);

    // 展示数组的内容 --- 展示排查出的雷的信息
    ShowBoard(show, ROW, COL);
    // 展示数组的内容 --- 展示布置好的雷的信息
    // ShowBoard(mine, ROW, COL);

    // 排查雷
    FindMine(mine, show, ROW, COL);
}



int main()
{

    int input;
    srand((unsigned int)time(NULL)); // 随机数种子

    do
    {
        menu();
        printf("请输入您的选择> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("开始游戏\n");
            game();
            break;
        case 0: 
            printf("退出游戏\n");
            break;
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    } while (input);



    return 0;
}