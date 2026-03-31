#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* create(Node* head, int n)
{
    Node *p1 = head, *h = head, *p2;
    if (!p1) return NULL;
    printf("正在生成链表:\n");
    while (n--)
    {
        p2 = (Node*)malloc(sizeof(Node));
        if (!p2) return NULL;
        scanf("%d", &p2->data);
        p1->next = p2;
        p2->next = NULL;
        p1 = p1->next; // 或者：p1 = p2
    }
    return h;
}

Node* create2(Node* head, int n)
{
    Node *p1 = head, *h = head, *p2;
    if (!p1) return NULL;
    printf("正在生成链表:\n");
    while (n--)
    {
        p2 = (Node*)malloc(sizeof(Node));
        if (!p2) return NULL;
        scanf("%d", &p2->data);
        p2->next = p1;
        p1 = p2;
    }
    h = p1;
    return h;
}

Node* qeury(Node* head, int num)
{
    if (!head) return NULL;
    Node* p1 = head;
    while (p1 != NULL)
    {
        if (p1->data == num) return p1;
        else p1 = p1->next;
    }
    return NULL;
}

Node* update(Node* head, int dest, int num)
{
    Node *p1 = head, *h = head;
    if (!p1) return NULL;
    while (p1 != NULL)
    {
        if (p1->data == dest)
        {
            p1->data = num;
        }
        p1 = p1->next;
    }
    return h;
}

Node* delete(Node* head, int dest)
{
    if (!head) return NULL;
    Node *p1 = head, *h = head;
    if (p1->data == dest) // 或者：if (head -> data == dest)
    {
        h = p1->next;
        free(p1);
        return h;
    }
    while (p1->next != NULL)
    {
        if (p1->next->data == dest)
        {
            Node* t = p1->next;
            p1->next = p1->next->next;
            free(t);
        }
        else p1 = p1->next;
    }
    return h;
}

Node* insert(Node* head, int dest, int num)
{
    if (!head) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    Node *p1 = head, *h = head, *p2;
    printf("1为头插法，2为尾插法：\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        while (p1->next != NULL)
        {
            if (p1->data == dest)
            {
                n->data = num;
                n->next = p1;
                p1 = n;
                h = p1;
                return h;
            }
            if (p1->next->data == dest)
            {
                p2 = p1->next;
                n->data = num;
                n->next = p2;
                p1->next = n;
                return h; // 或者：使用break，后续再返回头地址
            }
            p1 = p1->next;
        }
        break;
    case 2:
        while (p1 != NULL)
        {
            if (p1->data == dest)
            {
                n->data = num;
                n->next = p1->next;
                p1->next = n;
                return h;
            }
            p1 = p1->next;
        }
    }
    free(n);
    return NULL;
}

Node* reverse(Node* head)
{
    if (!head) return NULL;
    Node *q, *p, *r, *h;
    p = head;
    q = p->next;
    p->next = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    h = p; // 或者可直接返回p，此时p为逆置后的头地址
    return h;
}

void print(Node* head)
{
    if (!head) return;
    Node* p1 = head;
    while (p1 != NULL)
    {
        printf("%d ", p1->data);
        p1 = p1->next;
    }
    printf("\n");
}

Node* sort(Node* head)
{
    Node *p1 = head, *h = head, *p2;
    p2 = p1->next;
    while (p1 != NULL)
    {
        p2 = p1->next;
        while (p2 != NULL)
        {
            if (p2->data < p1->data)
            {
                int t = p1->data;
                p1->data = p2->data;
                p2->data = t;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return h;
}

int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    printf("输入头节点data：\n");
    scanf("%d", &head->data);

    // 尾插法创建链表
    /*int n;
    printf("输入要插入几个节点：\n");
    scanf("%d", &n);
    create(head, n);
    print(head);*/

    // 头插法创建链表
    int n;
    printf("输入要插入几个节点：\n");
    scanf("%d", &n);
    Node* head2 = create2(head, n);
    print(head2);

    // 链表数据查询
    /*int num;
    printf("输入要查询的数据值:\n");
    scanf("%d", &num);
    Node* q_val = qeury(head2, num);
    if (q_val == NULL) printf("查询的数据不存在\n");
    else printf("查询的数据：%d\n", q_val->data);*/

    // 链表数据更新
    /*int dest, num2;
    printf("输入要更新的数据值:\n");
    scanf("%d", &dest);
    printf("输入新的数据值:\n");
    scanf("%d", &num2);
    head2 = update(head2, dest, num2);
    print(head2);*/

    // 链表数据删除
    /*int dest3;
    printf("输入要删除的数据值:\n");
    scanf("%d", &dest3);
    head2 = delete(head2, dest3);
    print(head2);*/

    // 链表数据插入
    int dest4, num4;
    printf("输入要插入的数据值:\n");
    scanf("%d", &dest4);
    printf("输入新的数据值:\n");
    scanf("%d", &num4);
    head2 = insert(head2, dest4, num4);
    print(head2);

    // 链表逆置
    head2 = reverse(head2);
    print(head2);

    // 链表排序
    head2 = sort(head2);
    print(head2);

    return 0;
}
