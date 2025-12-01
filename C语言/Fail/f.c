#include <stdio.h>
int main()
{
    int m;
    for(m=1;m<=50;m++)
    {
        if(m%12!=0)
            continue;
        printf("%4d",m); // 空格空格12空格空格24空格空格36空格空格48
    }
    printf("\n");

    return 0;
}