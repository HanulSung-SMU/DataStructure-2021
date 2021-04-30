#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node* link;
}node;


node* insert_first(node* head, int value) {
	node* p = (node*)malloc(sizeof(node));		// 새로운 노드 생성  
	p->data = value;
	p->link = head;		// 포인터 복사  
	head = p;
	return head;
}


node* insert(node* head, node* pre, int value)	// 노드 pre 뒤에 삽입  
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

node* delete_first(node* head)	// 첫번째것 삭제  
{
	node* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

node* Delete(node* head, node* pre)	// pre 뒤 삭제  
{
	node* removed;
	removed = pre->link;
	pre->link = removed->link;  
	free(removed);
	return head;
}

void print_list(node* head)
{
	for (node* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main_1() {
	node* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);

	}
	return 0;
}