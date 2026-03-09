#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int flip()
{
    int r = rand() % 2;
    return r;
}

int main()
{
    srand((unsigned)time(NULL));
    int z = 0, f = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 5 == 0) printf("\n");
        int r = flip();
        if (r == 1)
        {
            printf("正面 ");
            z++;
        }
        if (r == 0)
        {
            printf("反面 ");
            f++;
        }
    }
    printf("\n");
    printf("正、反面数次分别为：%d, %d\n", z, f);
    return 0;
}
