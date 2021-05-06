#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	int data;
	struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode* head, element n)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = n;
	if (head == NULL)
	{
		head = newNode;
		newNode->link = head;
	}
	else
	{
		newNode->link = head->link;
		head->link = newNode;
	}

	return head;
}

ListNode* insert_last(ListNode* head, element n)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = n;
	if (head == NULL)
	{
		head = newNode;
		newNode->link = head;
	}
	else
	{
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}

	return head;
}

void print_ListNode(ListNode* head)
{
	ListNode* i;
	if (head == NULL) return;
	for (i = head->link; i != head; i = i->link)
	{
		printf("%d->", i->data);
	}
	printf("%d->\n", i->data);
}

int main(void)
{
	ListNode* head = NULL;

	head = insert_first(head, 10);
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	head = insert_first(head, 40);
	head = insert_last(head, 50);
	head = insert_last(head, 60);

	print_ListNode(head);

	return 0;
}