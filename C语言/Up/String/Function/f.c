#include <stdio.h>
#include <string.h>

int main() {
    char str[20] = "1234";
    char *s = "5678";

    printf("%d\n", strlen(str)); // 4
    strcat(str, s);
    printf("%s\n", str); // 12345678

    return 0;
}
