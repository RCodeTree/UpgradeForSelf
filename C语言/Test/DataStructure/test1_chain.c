#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* createNode()
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	printf("输入创建的节点数据: ");
	scanf("%d", &(node -> data));
	return node;
}

struct Node* createChain(struct Node* head)
{
	struct Node* h = head;
       	struct Node* tail = head;
	int n;
	printf("链表生成中，输入多个节点数据(-1结束数据输入): ");
	do
	{
		scanf("%d", &n);
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node -> data = n;
		node -> next = NULL;
		tail -> next = node;
		tail = node;
	}
	while (n != -1);
	return h;
}

struct Node* insertNode(struct Node* head, struct Node* node, int insertForData)
{
	struct Node* h = head;
	if (head == NULL || node == NULL) 
	{
		printf("头节点或节点不存在\n");
		return NULL;
	}
	while (head -> next != NULL)
	{
		if (head -> next -> data == insertForData)
		{
			struct Node* tmp = head -> next;
			node -> next = tmp;
			head -> next = node;
			break;
		}
		head = head -> next;
	}
	return h;
}

struct Node* removeNode(struct Node* head, int removeForData)
{
	struct Node* h = head;
	if (head == NULL)
	{
		printf("头节点或节点不存在\n");
                return NULL;
	}
	while (head -> next != NULL)
	{
		if (head -> next -> data == removeForData)
		{
			struct Node* tmp = head -> next -> next;
			head -> next = tmp;
			tmp = NULL;
			break;
		}
		head = head -> next;
	}
	return h;
}


void printChain(struct Node* head)
{
	if (head == NULL)
	{
		printf("头节点不存在\n");                    
		return;
	}
	while (head -> next != NULL)
	{
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}


int main()
{
	struct Node* head = createNode();
	struct Node* chain_head = createChain(head);
	printChain(chain_head);
	printf("输入链表中要插入位置节点的数据: ");
	int insertForData;
	scanf("%d", &insertForData);
	struct Node* chain_head_inserted = insertNode(chain_head, createNode(), insertForData);
	printChain(chain_head_inserted);
	printf("输入链表中要删除节点的数据: ");
        int removeForData;
        scanf("%d", &removeForData);
	struct Node* chain_head_removed = removeNode(chain_head_inserted, removeForData);
	printChain(chain_head_removed);
	// printf("%d\n", head -> data);
	return 0;
}
