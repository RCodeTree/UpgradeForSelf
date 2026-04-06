#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ==================== 带头结点的链表逆置 ====================

// 带头结点的链表逆置函数
Node* reverseWithHead(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    Node* current = head->next; // 跳过头结点
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转指针
        prev = current; // 前移prev
        current = next; // 前移current
    }

    // 将头结点指向新的第一个节点
    head->next = prev;
    return head;
}

// ==================== 不带头结点的链表逆置 ====================

// 不带头结点的链表逆置函数
Node* reverseWithoutHead(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转指针
        prev = current; // 前移prev
        current = next; // 前移current
    }

    return prev; // prev成为新的头结点
}

// ==================== 测试函数 ====================

// 测试带头结点的链表逆置
void testWithHead()
{
    printf("=== 带头结点的链表逆置测试 ===\n");

    // 创建带头结点的链表: head -> 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = createNode(0); // 头结点
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("原链表: ");
    printList(head->next); // 跳过头结点打印

    head = reverseWithHead(head);

    printf("逆置后: ");
    printList(head->next); // 跳过头结点打印

    // 释放内存
    free(node4);
    free(node3);
    free(node2);
    free(node1);
    free(head);
}

// 测试不带头结点的链表逆置
void testWithoutHead()
{
    printf("\n=== 不带头结点的链表逆置测试 ===\n");

    // 创建不带头结点的链表: 1 -> 2 -> 3 -> 4 -> NULL
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("原链表: ");
    printList(node1);

    Node* newHead = reverseWithoutHead(node1);

    printf("逆置后: ");
    printList(newHead);

    // 释放内存
    free(node4);
    free(node3);
    free(node2);
    free(newHead); // 注意：newHead现在是node4
}

int main()
{
    testWithHead();
    testWithoutHead();
    return 0;
}
