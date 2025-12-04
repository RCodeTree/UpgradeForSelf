/*
猴子吃桃问题：有一堆桃子，猴子每天吃前一天的一半多一个。到第10天早上只剩1个。
求最初有多少个桃子。

设第 n 天的桃子数为 f(n)。根据题意，第 n+1 天桃子数等于第 n 天的桃子数减去猴子当天吃掉的桃子数：
f(n+1) = f(n) - ( f(n)/2 + 1 ) = f(n)/2 - 1
由此可解出逆推公式：
f(n) = ( f(n+1) + 1 ) * 2
边界：f(10) = 1。
*/
#include <stdio.h>
int f(int day)
{
    if(day==10) 
    {
        return 1;
    }
    else 
    {
        return (f(day+1)+1)*2;
    }
}

int main()
{
    int day=9;

    printf("第%d天有%d个桃子。\n",day,f(day)); 

    return 0;
}
