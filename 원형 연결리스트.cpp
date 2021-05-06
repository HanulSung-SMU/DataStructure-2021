#include <stdio.h>
#include <stdlib.h>

typedef struct listnode		// ��� Ÿ���� ����ü�� ����  
{
	int data;
	struct listnode *link;
} listnode;


listnode *insert_first(listnode *head, int data)	// ó�� ��ġ�� ����  
{
	listnode *node = (listnode *)malloc(sizeof(listnode));		// ���ο� ��� ����  
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;	// ����� ��� �����͸� ��ȯ  
}

listnode *insert_last(listnode *head, int data)	
{
	listnode *node = (listnode *)malloc(sizeof(listnode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	// ����� ��� �����͸� ��ȯ  
}



void print_list (listnode *head)
{
	listnode *p;
	if (head == NULL)
		return;
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf ("%d->", p->data);
}


int main(void)
{
	listnode *head = NULL;
	
	head = insert_last (head, 20); 
	head = insert_last (head, 30); 
	head = insert_last (head, 40); 
	head = insert_first (head, 10); 
	print_list (head);
	return 0;
}
