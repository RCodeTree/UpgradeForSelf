#include <stdio.h>
#include <string.h>
int main()
{
    char a[] = "\\t\12\123\1234\012";
    char b[] = "\xab\012\xA1\t";
    printf("%ld\n", strlen(a));
    printf("%ld\n", strlen(b));
    return 0;
}