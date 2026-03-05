#include <stdio.h>

int main()
{
    FILE* fp = fopen("test.txt", "r");
    // char ch = fgetc(fp);
    // printf("%c", ch);

    char a[100];
    char* str = fgets(a, sizeof(a), fp);
    printf("%s", str);
    return 0;
}
