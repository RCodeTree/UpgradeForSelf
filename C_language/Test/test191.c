#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
        {
            a[i][j] = ' ';
            if (i == 0) a[i][j] = '*';
            if (j == 0) a[i][j] = '*';
            if (i == j) a[i][j] = '*';
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - (1 + i); j++) printf(" ");
        for (int k = 0; k <= i; k++) printf("%c ", a[i][k]);
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - (i + 1); j++) printf(" ");
        for (int k = 0; k <= i; k++) printf("%c ", a[i][k]);
        printf("\n");
    }
    printf("\n");
    return 0;
}
