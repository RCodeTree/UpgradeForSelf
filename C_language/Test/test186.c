#include <stdio.h>

/**
 * 打印一个金字塔
***********
 *********
  *******
   *****
    ***
     *
    ***
   *****
  *******
 *********
***********
 * @return 0
 */
int main()
{
    int n = 11;
    int s = 6;
    int x = n - s;
    for (int i = 0; i < s; i++)
    {
        for (int k = 0; k < i; k++) printf(" ");
        for (int j = 0; j < (2 * s) - (2 * i + 1); j++) printf("*");
        printf("\n");
    }
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < x - (i + 1); k++) printf(" ");
        for (int j = 0; j < 2 * (i + 1) + 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
