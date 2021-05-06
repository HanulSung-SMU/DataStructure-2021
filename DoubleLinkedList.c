#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init_DListNode(DListNode* head)
{
	head->llink = head;
	head->rlink = head;
}

void dinsert(DListNode* before, element n)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}
	newNode->data = n;
	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_DListNode(DListNode* head)
{
	DListNode* i;
	for (i = head->rlink; i != head; i = i->rlink)
	{
		printf("<-|%d|->", i->data);
	}
	printf("\n");
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	if (head == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}
	int i;

	init_DListNode(head);
	printf("데이터 삽입\n");
	for (i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_DListNode(head);
	}

	printf("데이터 삭제\n");
	for (i = 0; i < 5; i++)
	{
		print_DListNode(head);
		ddelete(head, head->rlink);
	}

	free(head);

	return 0;
}