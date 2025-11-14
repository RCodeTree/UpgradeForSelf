#include <stdio.h>
int main( )
{
    int a = 325; 
    double x = 3.1415926;
    printf("a=%+06d x=%+e\n", a, x);
    printf("a=%06d x=%e\n", a, x);
    printf("a=%-06d x=%-e\n", a, x);
    return 0;
}