
#include <stdio.h>
int main()
{ 
    int a=0,b=0,c=0;
    c=(a+=a-=5),(a=b,b+3); // 逗号优先级最低，语句分为两部分： c = (a += a -= 5) 和 (a = b, b + 3)
    printf("%d,%d,%d\n",a,b,c); // a=0,b=0,c=-10
}