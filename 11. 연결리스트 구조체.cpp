#include <stdio.h>
#include <stdlib.h>

typedef struct listnode		// 노드 타입을 구조체로 정의  
{
	int data;
	struct listnode *link;
} listnode;

void error (char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listnode *insert_first(listnode *head, int value)	// 처음 위치에 삽입  
{
	listnode *p = (listnode *)malloc(sizeof(listnode));		// 새로운 노드 생성  
	p->data = value;
	p->link = head;		// 헤드 포인터 복사  
	head = p;			// 헤드 포인터를 p값으로 변경  
	return head;		
}

listnode *insert(listnode *head, listnode *pre, int value)	// pre가 가리키는 노드 뒤에 삽입  
{
	listnode *p = (listnode *)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

listnode *delete_first(listnode *head)	// 첫번째것 삭제  
{
	listnode *removed;
	if (head == NULL) return NULL;
	removed = head;			// 헤드 포인터 값을 removed에 복사  
	head = removed->link;	// 헤드 포인터 값을head->link로 변경  
	free(removed);			// 동적 메모리 반환  
	return head;
}

listnode *Delete(listnode *head, listnode *pre)	// pre가 가리키는 노드 뒤의것 삭제  
{
	listnode *removed;
	removed = pre->link;
	pre->link = removed->link;	//pre가 삭제한것의 뒤의것을 가리키게 함  
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
