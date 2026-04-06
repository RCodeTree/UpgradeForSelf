#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

void printList(Node* head);

int main()
{
    int n;
    scanf("%d", &n);
    Node *h, *p1, *p2;
    h = p1 = (Node*)malloc(sizeof(Node));
    scanf("%d", &(p1->val));
    for (int i = 1; i < n; i++)
    {
        p2 = (Node*)malloc(sizeof(Node));
        scanf("%d", &(p2->val));
        p2->next = p1;
        p1 = p2;
    }
    h->next = NULL;
    h = p1;
    printList(h);
    return 0;
}

void printList(Node* head)
{
    if (head == NULL) return;
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
