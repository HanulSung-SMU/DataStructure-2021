#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	if (head == NULL)
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNode* insert_last(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	if (head == NULL)
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

ListNode* traverse_insert(ListNode* head, int data)
{
	ListNode* temp= (ListNode*)malloc(sizeof(ListNode));
	ListNode* q;
	ListNode* s = NULL;

	temp->data = data;
	q = head->link;

	if (q->data > temp->data)
	{
		temp->link = q;
		head->link = temp;
		return head;
	}

	else if (q->data < temp->data)
	{
		do
		{
			if (q->data <= temp->data)
			{
				s = q;
				q = s->link;
			}
			else if (q->data > temp->data)
			{
				temp->link = q;
				s->link = temp;
				break;
			}
		} while (q != head);
		return head;
	}
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL)
	{
		return;
	}
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}

int main(void)
{
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("\n");
	traverse_insert(head, 15);
	print_list(head);


	return 0;
}