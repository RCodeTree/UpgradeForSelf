#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void fun(struct Node* n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}

void main()
{
    struct Node n1 = {1, NULL}, n2 = {2, NULL}, n3 = {3, NULL};
    n1.next = &n2;
    n2.next = &n3;
    fun(&n1);
}
