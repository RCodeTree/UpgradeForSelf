#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10 // 简单模式下，布置10个雷

// 初始化数组的内容为指定的内容
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// 展示数组的内容
void ShowBoard(char board[ROWS][COLS], int row, int col);

// 布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
