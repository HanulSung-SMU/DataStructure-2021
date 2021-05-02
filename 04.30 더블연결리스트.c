#include <stdio.h>
typedef struct DListNode { 
	int data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
void dinsert(DListNode* pos, int _data) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	if (node == NULL) {
		printf("error");
		exit(1);
	}
	node->data = _data;
	node->llink = pos;
	node->rlink = pos->rlink;
	pos->rlink->llink = node;
	pos->rlink = node;
}
void ddelete(DListNode* head, DListNode* pos) {
	if (head == pos) return;
	pos->llink->rlink = pos->rlink;
	pos->rlink->llink = pos->llink;
	free(pos);
}
void print_dlist(DListNode* head) {
	for (DListNode* i = head->rlink; ;) {
		printf("<-%d", i->data);
		i = i->rlink;
		if (i == head)
			break;
		printf("->");
	}
	printf("\n");
}
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	if (head == NULL) {
		printf("error");
		exit(1);
	}
	init(head);
	for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}