#include <stdio.h>
#include <string.h>

struct Book {
    char name[100];
    char author[100];
    int price;
} book[3];

/*
 * @brief 对图书按价格排序
 */
void sort() {
    for (int i = 0; i < 3 - 1; i++) {
        int k = i;
        for (int j = i + 1; j < 3; j++) {
            if (book[j].price > book[k].price)
                k = j;
        }
        if (k != i) {
            struct Book b = book[k];
            book[k] = book[i];
            book[i] = b;
        }
    }
}

/*
 * @brief 查询图书
 * @param name 要查询的书名
 */
void query(char *name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("书名: %s, 作者: %s, 价格: %d\n", book[i].name, book[i].author, book[i].price);
            return;
        }
    }
    printf("未找到该图书\n");
}

/*
 * @brief 主函数
 */
int main() {
    for (int i = 0; i < 3; i++) {
        printf("请输入第%d本图书的书名、作者、价格: ", i + 1);
        scanf("%s %s %d", book[i].name, book[i].author, &book[i].price);
    }

    printf("排序前:\n");
    for (int i = 0; i < 3; i++) {
        printf("书名: %s, 作者: %s, 价格: %d\n", book[i].name, book[i].author, book[i].price);
    }

    sort();

    printf("排序后:\n");
    for (int i = 0; i < 3; i++) {
        printf("书名: %s, 作者: %s, 价格: %d\n", book[i].name, book[i].author, book[i].price);
    }

    char name[100];
    printf("请输入要查询的书名: ");
    scanf("%s", name);
    query(name);
    return 0;
}
