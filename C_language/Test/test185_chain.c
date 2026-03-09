#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* creat()
{
	Node* h = NULL, *t = NULL; int nu = 0;
	printf("正在生成单链表，请输入整数，-1就退出：");
	while (1)
	{
		scanf("%d", &nu);
		if (nu == -1) break;
		Node* new = (Node*) malloc(sizeof(Node));
		new -> data = nu;
		new -> next = NULL;
		if (h == NULL)
		{
			h = new;
			t = new;
		}
		else
		{
			t -> next = new;
			t = new;
		}
	}
	printf("单链表的值为：\n"); Node* tmp = h;
	while (tmp != NULL)
	{
		printf("%d ", tmp -> data);
		tmp = tmp -> next;
	}
	printf("\n");
	return h;
}

Node* contracte(Node* n1, Node* n2)
{
	Node* h = n1; Node* t = NULL;
	while (1) 
	{
		if (n1 -> next == NULL)
		{
			t = n1;
			break;
		}
		n1 = n1 -> next;
	}
	t -> next = n2;	
	printf("合并后单链表的值为：\n");
	Node* tmp2 = h;
	while (tmp2 != NULL)
	{
		printf("%d ", tmp2 -> data);
		tmp2 = tmp2 -> next;
	}
	printf("\n");
	return h;
}


int main()
{
	Node* n1 = creat();
	Node* n2 = creat();
	contracte(n1, n2);
	return 0;
}
