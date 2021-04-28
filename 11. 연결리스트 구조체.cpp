#include <stdio.h>
#include <stdlib.h>

typedef struct listnode		// ��� Ÿ���� ����ü�� ����  
{
	int data;
	struct listnode *link;
} listnode;

void error (char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listnode *insert_first(listnode *head, int value)	// ó�� ��ġ�� ����  
{
	listnode *p = (listnode *)malloc(sizeof(listnode));		// ���ο� ��� ����  
	p->data = value;
	p->link = head;		// ��� ������ ����  
	head = p;			// ��� �����͸� p������ ����  
	return head;		
}

listnode *insert(listnode *head, listnode *pre, int value)	// pre�� ����Ű�� ��� �ڿ� ����  
{
	listnode *p = (listnode *)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

listnode *delete_first(listnode *head)	// ù��°�� ����  
{
	listnode *removed;
	if (head == NULL) return NULL;
	removed = head;			// ��� ������ ���� removed�� ����  
	head = removed->link;	// ��� ������ ����head->link�� ����  
	free(removed);			// ���� �޸� ��ȯ  
	return head;
}

listnode *Delete(listnode *head, listnode *pre)	// pre�� ����Ű�� ��� ���ǰ� ����  
{
	listnode *removed;
	removed = pre->link;
	pre->link = removed->link;	//pre�� �����Ѱ��� ���ǰ��� ����Ű�� ��  
	free(removed);
	return head;
}

void print_list (listnode *head)
{
	for (listnode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void)
{
	listnode *head = NULL;
	
	for (int i=0; i<5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i=0; i<5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
