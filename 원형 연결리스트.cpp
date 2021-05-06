#include <stdio.h>
#include <stdlib.h>

typedef struct listnode		// 노드 타입을 구조체로 정의  
{
	int data;
	struct listnode *link;
} listnode;


listnode *insert_first(listnode *head, int data)	// 처음 위치에 삽입  
{
	listnode *node = (listnode *)malloc(sizeof(listnode));		// 새로운 노드 생성  
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
	return head;	// 변경된 헤드 포인터를 반환  
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
	return head;	// 변경된 헤드 포인터를 반환  
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
