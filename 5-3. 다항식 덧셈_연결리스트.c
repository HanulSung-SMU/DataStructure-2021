#include<stdio.h>
typedef struct ListNode {								//다항식 요소를 저정할 자료구조
	int coef;
	int expo;
	struct ListNode* link;
}ListNode;

typedef struct ListType {								//다항식을 저장할 자료구조
	int count;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create() {
	ListType* t = (ListType*)malloc(sizeof(ListType));	// 자료구조 생성
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
	p->coef = co; p->expo = ex;							// 입력할 항의 계수와 차수 입력
	p->link = NULL;

	(t->count)++;										// 항의 수 추가
	if (t->tail == NULL)
		t->head = t->tail = p;							// 첫 항일경우 다항식의 처음과 끝은 새로 넣은 항
	else {		
		t->tail->link = p;								// 마지막 항의 링크가 새로 넣는 항을 가르키게하고 마지막 항이 새로 넣은 항으로 설정
		t->tail = p;
	}
}

void poly_add(ListType* list1, ListType* list2, ListType* result) {
	ListNode* l1 = list1->head, * l2 = list2->head;
	while (l1 != NULL && l2 != NULL) {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		if (p == NULL) {
			printf("error\n");
			exit(1);
		}
		if (l1->expo == l2->expo) {
			int sum = l1->coef + l2->coef;
			if (sum) insert_last(result, sum, l1->expo);	// 두개의 계수의 합이 0이 아닌 경우에 저장
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
	for (ListNode* i = l1; l1 != NULL; l1 = l1->link)		// 덧셈과정 후 list1, list2에 항이 남았다면 result 다항식에 더해주기
		insert_last(result, l1->coef, l1->expo);
	for (ListNode* i = l2; l2 != NULL; l2 = l2->link) 
		insert_last(result, l2->coef, l2->expo);
}

void poly_print(ListType* list) {
	for (ListNode* i = list->head; i != NULL;) {
		printf("%dx^%d ", i->coef, i->expo);
		i = i->link;
		if (i == NULL)
			break;
		printf(" + ");
	}
	printf("  count : %d\n", list->count);
}

int main(void)
{
	ListType* list1, * list2, * list3;
	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	// 다항식 1을 생성
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 1);
	// 다항식 2를 생성
	insert_last(list2, 8, 12);
	insert_last(list2, -2, 8);
	insert_last(list2, 10, 1);
	insert_last(list2, 9999, 0);
	poly_print(list1);
	poly_print(list2);
	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	free(list1); free(list2); free(list3);
}