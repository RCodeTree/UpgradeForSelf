#include <stdio.h>

int fun(int x)
{
    int y = 0;
    static int z = 3;
    z++;
    ++y;
    return (x + y + z);
}

int main()
{
    int i, x = 2;
    for (i = 0; i < 2; i++)
    {
        printf("%5d", fun(x++));
    }
    return 0;
}
