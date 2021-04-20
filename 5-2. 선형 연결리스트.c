#include<stdio.h>
typedef struct ListNode{
	int data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* list, int val) {
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	if (!new) {
		printf("error");
		exit(1);
	}
	new->data = val;
	new->link = list;
	list = new;
	return list;
}

ListNode* delete_first(ListNode* list) {
	ListNode* tmp = list;
	list = list->link;
	free(tmp);
	return list;
}

void print_list(ListNode* list) {
	for (ListNode* i = list; i != NULL; i = i->link)
		printf("%d-> ", i->data);
	printf("NULL\n");
}
int main(void)
{
	ListNode* head = NULL;
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