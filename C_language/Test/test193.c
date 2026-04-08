#include <stdio.h>

void f(unsigned int num)
{
    if (num == 0) return;
    f(num / 2);
    printf("%d", num % 2);
}

int f2(unsigned int num, unsigned int* arr)
{
    int t = num;
    int c = 0;
    while (t)
    {
        t /= 10;
        c++;
    }
    t = num;
    int i = 0;
    int t2 = c;
    while (t2--)
    {
        arr[i++] = t % 10;
        t /= 10;
    }
    return c;
}

int f3(int num, char* arr)
{
    int t = num;
    int i = 0;
    if (num < 0)
    {
        t = -num;
        arr[i] = '-';
        i++;
    }
    int c = 0;
    while (num)
    {
        num /= 10;
        c++;
    }
    int t2 = c;
    while (t2--)
    {
        arr[i++] = t % 10 + '0';
        t /= 10;
    }
    return c;
}

int main()
{
    unsigned int num;
    scanf("%u", &num);
    f(num);
    printf("\n-------------------\n");

    char arr[100] = {0};
    int len = f3(num, arr);
    for (int i = 0; i <= len; i++) printf("%c", arr[i]);
    printf("\n-------------------\n");

    long N = 1;
    for (; N <= 200; N++)
    {
        long t = N * N;
        long t2 = t;
        long r = 0;
        if (t < 10) continue;
        while (t2)
        {
            r = r * 10 + t2 % 10;
            t2 /= 10;
        }
        if (r == t) printf("%ld ", N);
    }
    printf("\n");


    return 0;
}
