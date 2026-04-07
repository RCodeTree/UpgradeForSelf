#include <stdio.h>
#define SQR(x) x*x
#define MAX(a,b) (a)>(b)?(a):(b)

/*void main()
{
    int i = 3, j = 5, k;
    k = SQR(i+j);
    printf("%d ", k);
    k = MAX(i++, ++j);
    printf("%d %d %d\n", i, j, k); // 23 4 7 7
}*/

/*int x = 10, y = 20;

void test()
{
    int x = 5;
    {
        extern int x; // 全局变量x
        x += y;
        y *= 2;
    }
    printf("%d ", x);
}

int main()
{
    test();
    printf("%d %d", x, y);
    return 0;
}*/

/*#include <stdio.h>

struct Goods
{
    char name[30];
    float price;
    int num;
};

int main()
{
    struct Goods g;
    scanf("%s%f%d", g.name, &g.price, &g.num);
    struct Goods g2 = {"apple", 5.5, 10};
    return 0;
}*/

// 编程题
/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

int main()
{
    Node *h = NULL, *p1, *p2;
    int n;
    scanf("%d", &n);
    printf("正在生成单链表，输入0结束:");
    int num;
    while (n--)
    {
        scanf("%d", &num);
        if (num == 0) break;
        if (num < 1 || num > 100)
        {
            printf("超过数据范围，跳过该值输入\n");
            continue;
        }
        p2 = (Node*)malloc(sizeof(Node));
        p2->val = num;
        if (h == NULL)
        {
            h = p1 = p2;
        }
        else
        {
            p1->next = p2;
            p1 = p1->next;
        }
    }
    p1->next = NULL;
    printf("单链表值为：\n");
    Node* t = h;
    while (t)
    {
        printf("%d ", t->val);
        t = t->next;
    }
    return 0;
}*/

#include <stdio.h>

void f(int (*a)[3], float* avg, int* max)
{
    int s = 0, c = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] > *max) *max = a[i][j];
            s += a[i][j];
            c++;
        }
    }
    *avg = s / (c * 1.0);
}

int main()
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++) scanf("%d ", &a[i][j]);
    // }
    float avg;
    int max = a[0][0];
    f(a, &avg, &max);
    printf("%.1f %d", avg, max);
    return 0;
}
