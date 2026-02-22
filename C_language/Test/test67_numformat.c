#include <stdio.h>
#include <string.h>
int main()
{
    int a = 1, b = 2, c = 3;
    float d = 123.4567;
    printf("%d %d %d\n", a, b, c);
    printf("%.3f\n", d);
    printf("%3.3f\n", d);
    return 0;
}