#include <stdio.h>
#include <string.h>

/**
 * 从字符串数组中提取所有的数字并组成一个数
 * @return 0
 */
int main() {
    char str[3][20] = {"abc12", "qwe5", "pio8"};
    int num = 0;
    for (int i = 0; i < 3; i++) {
        int len = strlen(str[i]);
        for (int j = 0; j < len; j++) {
            if (str[i][j] >= '0' && str[i][j] <= '9') {
                num = num * 10 + (str[i][j] - '0');
            }
        }
    }
    printf("含有数最终组成的数为：%d\n", num);
    return 0;
}
