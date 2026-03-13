#include <stdio.h>
#include <string.h>

char* fun(char (*a)[3], int num, char* max)
{
    int i = 0;
    max = a[0];
    for (i = 0; i < num; i++)
        if (strlen(a[i]) > strlen(max))
            max = a[i];
    return max;
}

int main()
{
    char a[3][4] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    char b[3][4] = {"abc", "def", "ghi"};
    char* c[3] = {"a31242fabc", "dfasdfef", "ghidafa"};

    char d[] = "1234567890";
    char e[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char* max;
    max = fun(b, 3, max);

    return 0;
}
