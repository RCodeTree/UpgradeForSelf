#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 'a' - 'A' : ch; // 大写字母转换为小写字母 ('a' - 'A' = 32)
    ch = (ch >= 'a' && ch <= 'z') ? ch + 'A' - 'a' : ch; // 小写字母转换为大写字母 ('A' - 'a' = -32)
    printf("%c\n", ch);

    printf("------------------\n");

    int x = 1, y = 0;
    // printf("%d\n", x-- > (y + x) ? 5 : 25 > y++ ? '1' : '2'); // 5
    // printf("%d\n", x-- > (y + x) ? 10 : 12.5 > y++ ? 'A' : 'Z'); // 10
    printf("%d\n", x > (y + x) ? 10 : 12.5 > y++ ? 'a' : 'A'); // 97 --- a

    return 0;
}
