#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	
}

ListNode* insert(ListNode* head, element value) {
	ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* head2 = head;
	ListNode* post = head2->link;
	p2->data = value;
	do {
		if (head2->data < p2->data && post->data > p2->data) {
			p2->link = head2->link;
			head2->link = p2;
		}
		else
			head2 = head2->link;
	} while (head2 != head);
	return head2;
}

void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}

void traverse(ListNode* head, element item) {
	ListNode* p;
	int nitem;
	if (head == NULL)	return;
	p = head->link;
	do {
		if (p->data == item) {
			printf("있습니다.\n");
			scanf_s("%d", &nitem);
			insert(p, nitem);
			break;
		}
		else {
			p = p->link;
		}
	} while (p != head);
}

int main(void) {
	ListNode* head = NULL;
	int item;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = insert_last(head, 50);
	head = insert_last(head, 60);
	head = insert_last(head, 70);
	
	scanf_s("%d", &item);
	traverse(head, item);
	print_list(head);
	

	return 0;
}