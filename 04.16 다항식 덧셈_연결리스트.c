#include<stdio.h>
typedef struct ListNode {
	int coef;
	int expo;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int count;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create() {
	ListType* t = (ListType*)malloc(sizeof(ListType));
	if (t == NULL) {
		printf("error\n");
		exit(1);
	}
	t->head = t->tail = NULL;
	t->count = 0;
}

void insert_last(ListType* t, int co, int ex) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL) {
		printf("error\n");
		exit(1);
	}
	p->coef = co; p->expo = ex;
	p->link = NULL;

	(t->count)++;
	if (t->tail == NULL)
		t->head = t->tail = p;
	else {
		t->tail->link = p;
		t->tail = p;
	}
}

void poly_add(ListType* list1, ListType* list2, ListType* result) {
	ListNode* l1 = list1->head, * l2 = list2->head;
	while (l1 != NULL && l2 != NULL) {
		if (l1->expo == l2->expo) {
			int sum = l1->coef + l2->coef;
			if (sum) insert_last(result, sum, l1->expo);
			l1 = l1->link; l2 = l2->link;
		}
		else if (l1->expo > l2->expo) {
			insert_last(result, l1->coef, l1->expo);
			l1 = l1->link;
		}
		else {
			insert_last(result, l2->coef, l2->expo);
			l2 = l2->link;
		}
	}
	for (ListNode* i = l1; l1 != NULL; l1 = l1->link)
		insert_last(result, l1->coef, l1->expo);
	for (ListNode* i = l2; l2 != NULL; l2 = l2->link)
		insert_last(result, l2->coef, l2->expo);
}

void poly_print(ListType* list) {
	for (ListNode* i = list->head; ;) {
		printf("%dx^%d", i->coef, i->expo);
		i = i->link;
		if (i == NULL)
			break;
		printf(" + ");
	}
	printf("\n");
}

int main(void)
{
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 1);

	insert_last(list2, 8, 12);
	insert_last(list2, -2, 8);
	insert_last(list2, 10, 1);
	insert_last(list2, 9999, 0);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	printf("------------------------------------------------------\n");
	poly_print(list3);
	free(list1); free(list2); free(list3);
}