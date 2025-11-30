#include <stdio.h>
#include <string.h>
int main()
{
    if (strlen("abc") - strlen("abcdef") > 0)
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }

    return 0;
}