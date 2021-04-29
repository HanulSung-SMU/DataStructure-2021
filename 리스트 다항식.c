#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

//연결 리스트 헤더
typedef struct ListType {
	int size;
	ListNode * head;
	ListNode * tail;
}ListType;

void error(char* message)
{
	fprintf(stderr, "s\n", message);
	exit(1);
}

//리스트 헤더 생성 함수
ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//리스트 안에 계수와 지수를 넣어주는 함수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

//리스트 안의 다항식끼리 더하는 함수
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	
	while (a && b) {
		//같은 차수
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0)insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		//a차수가 큰경우
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		//b차수가 큰경우
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	//하나가 먼저 끝나면 남아있는 항들을 결과 다항식으로 복사 
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

//다항식 출력 함수
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("plynomial = ");
	for (;p!=NULL;p= p->link) {
		printf("%d^%d ", p->coef, p->expon);
		if (p->link != NULL)
			printf("+");
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
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);
}
