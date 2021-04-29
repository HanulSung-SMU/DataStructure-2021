#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_first(ListNode* head, element n)
{
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다\n");
		exit(1);
	}
	p->data = n;
	p->link = head;
	head = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

void print_ListNode(ListNode* head)
{
	ListNode* i;
	for (i = head; i != NULL; i = i->link)
	{
		printf("%d->", i->data);
	}
	printf("NULL \n");
}

int main(void)
{
	ListNode* head = NULL;
	int i;

	for (i = 0; i < 4; i++)
	{
		head = insert_first(head, i);
		print_ListNode(head);
	}

	for (i = 0; i < 4; i++)
	{
		head = delete_first(head);
		print_ListNode(head);
	}

	return 0;
}