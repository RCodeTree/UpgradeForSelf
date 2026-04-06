#include <stdio.h>

void fun(int (*a)[3], int m) //void fun(int a[][M], int m)
{
    int j, k;
    for (j = 0; j < m; j++)
        for (k = 0; k < m; k++)
            a[j][k] = k * j; //a[j][k] = (k+1) * (j+1) ;
}

int main()
{
    int a[3][3] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};
    fun(a, 3);
    return 0;
}
