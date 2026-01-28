#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
}ns[10];

struct Node creat()
{
	int i = 0;
	printf("正在生成单链表，请输入整数，-1就退出> ");
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == -1) break;
		ns[i++].data = n;
	}
	for (int j = 0; j < i - 1; j++)
	{
		ns[j].next = &ns[j + 1];
	}
	printf("单链表的值是: \n");
	printNodeData(&ns[0]);
	return ns[0];
		
}

struct Node* contracte(struct Node* n1, struct Node* n2)
{
	struct Node* t1 = n1;
	struct Node* t2 = n2;
	while (t1 != NULL) t1 = t1 -> next;
	while (t2 != NULL) t1 -> next = t2;
	printNodeData(n1);
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
	struct Node n1 = creat();
	struct Node n2 = creat();
//	struct Node* concatLink = contracte(&n1, &n2);
//	printf("合并后的单链表结果为: ");
//	printNodeData(concatLink);
	return 0;
}
	
