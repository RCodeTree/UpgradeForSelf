#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* creat();

struct Node* contracte(struct Node* n1, struct Node* n2);

void printNodeData(struct Node* n);


struct Node* creat()
{
    int num_data = 0;
    printf("正在生成单链表，请输入整数，-1就退出> ");
    struct Node* head = NULL; // 记录头节点
    struct Node* tail = NULL; // 记录尾节点，用于连接新节点
    while (1)
    {
        scanf("%d", &num_data);
        if (num_data == -1) break;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num_data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("单链表的值是：\n");
    printNodeData(head);
    return head;
}

struct Node* contracte(struct Node* n1, struct Node* n2)
{
    struct Node* t1 = n1;
    while (t1->next != NULL) t1 = t1->next;
    t1->next = n2;
    return n1;
}


void printNodeData(struct Node* n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}

int main()
{
    struct Node* n1 = creat();
    struct Node* n2 = creat();
    struct Node* concatLink = contracte(n1, n2);
    printf("合并后的单链表的值是：\n");
    printNodeData(concatLink);
    return 0;
}
