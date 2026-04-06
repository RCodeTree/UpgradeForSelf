#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char str[10], temp[10] = "Control";
    for (i = 0; i < 4; i++) {
        gets(str);
        if (strcmp(temp, str) < 0) strcpy(temp, str);
    }
    puts(temp);
    return 0;
}
