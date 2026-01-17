#include <stdlib.h>
#include <stdio.h>
/*
 * 函数名：cp
 * 功能：将字符串b复制并替换到字符串a中
 * 参数：a - 目标字符串指针
 *      b - 源字符串指针
 * 返回值：void
 */
void cp(char **a, char *b) {
	int len = 0;
	char *p = b;
	while (*p) {
		len++;
		p++;
	}

    *a = (char *) malloc((len + 1) * sizeof(char));
	char *q = *a;
	p = b;
    while (*p) {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';
}

int main() {
    char *a = "Hello", b[] = "12345678";
    printf("a串的值为：%s\n", a);
    cp(&a, b);
    printf("复制后a串的值为：%s\n", a);
	free(a);
    return 0;
}
