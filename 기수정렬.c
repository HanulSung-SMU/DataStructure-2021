#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("\n");
}

int main(void) {

	ListNode* head[10];

	int list[10];
	int i, j;
	int c = 0;

	//랜덤 10개 생성
	srand(time(NULL));
	for (i = 0; i < 10; i++)
		list[i] = rand() % 10;

	printf("정렬 전 ");
	for (i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n");

	//기수 정렬할 리스트 만들기
	for (i = 0; i < 10; i++)
		head[i] = NULL;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (list[i] == j)
				head[j] = insert_first(head[j], list[i]);
		}

	//리스트 잘 만들어졌는지 확인
	for (i = 0; i < 10; i++)
	{
		printf("haed[%d] = ", i);
		print_list(head[i]);
	}

	//정렬
	for(i=0;i<10;i++)
		for (j = 0; j < 10; j++) {
			if (head[i] == NULL)
				;
			else if (head[i]->data == j) {
				list[c] = head[i]->data;
				c++;
				head[i] = head[i]->link;
				j--;
			}
		}
	
	printf("\n");
	printf("정렬 후 ");
	for (i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

