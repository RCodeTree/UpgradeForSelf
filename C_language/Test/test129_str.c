#include <stdio.h>
#include <string.h>

int main() {
    char a[100] = {0}, b[100] = {0}, tmp[100] = {0};
    printf("输入a串：");
    scanf("%s", a);
    printf("输入b串：");
    scanf("%s", b);
    char max = a[0];
    int index = 0;
    for (int i = 1; i < strlen(a); i++) {
        if (max < a[i])
            index = i;
    }
    int j = index;
    int k = 0;
    for (int i = index + 1; i < strlen(a); i++) {
        tmp[k++] = a[i];
    }
    printf("tmp: %s\n", tmp);
    for (int i = 0; i < strlen(b); i++) {
        a[++j] = b[i];
    }
    for (int i = 0; i < strlen(tmp); i++)
        a[++j] = tmp[i];
    printf("a: %s\n", a);
    return 0;
}
