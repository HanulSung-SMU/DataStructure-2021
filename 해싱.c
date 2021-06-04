#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

ListNode* insert_last(ListNode* head, int data) {
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
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) {
		printf("\n");
		return;
	}
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);
	printf("\n");
}
//해쉬 테이블에서 값 찾는 함수
void hash_find(ListNode* head, int value)
{
	ListNode* p;
	int i = 0;
	
	if (head == NULL)	
		return;
	p = head->link;
	//탐색
	do {
		if (p->data == value)
		{
			printf("%d ",value);
			return ;
		}
		p = p->link;
	} while (p != head);
	//마지막 요소 탐색
	if (p->data == value)
	{
		printf("%d ", value);
		return;
	}

	return;
}
int main(void) {

	ListNode* head[10];

	int list[10];
	int i, j;
	int value = 0;
	//랜덤 값 10개
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++)
			while (list[i] == list[j])
				list[i] = rand() % 100;
	}
	for (i = 0; i < 10; i++)
		head[i] = NULL;
	//랜덤값 10개 출력
	for (i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n");
	printf("\n");

	//해시 테이블에 삽입
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (list[i]%10 == j)
				head[j] = insert_last(head[j], list[i]);
		}


	//해쉬 테이블 출력
	for (i = 0; i < 10; i++)
	{
		printf("head[%d] = ", i);
		print_list(head[i]);
	}
	printf("\n");
	printf("1~50까지 숫자 탐색");
	printf("찾은 숫자 : ");
	//탐색
	for (i = 0; i < 50; i++) {
		value = i % 10;
		hash_find(head[value],i);
	}
	printf("\n");
	return 0;

}