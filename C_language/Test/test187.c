#include <stdio.h>

/**
 * 打印一个金字塔
12345654321
 123454321
  1234321
   12321
    121
     1
    121
   12321
  1234321
 123454321
12345654321
 * @return 0
 */
int main()
{
    int s = 6;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j < i; j++) printf(" ");
        for (int k = 1; k <= (s - i) + 1; k++) printf("%d", k);
        for (int q = s - i; q >= 1; q--) printf("%d", q);
        printf("\n");
    }
    int x = 5;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x - i; j++) printf(" ");
        for (int k = 1; k <= (s - x) + i; k++) printf("%d", k);
        for (int q = (s - x) + i - 1; q >= 1; q--) printf("%d", q);
        printf("\n");
    }
    return 0;
}
