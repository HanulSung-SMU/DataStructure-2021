#include<stdio.h>
#include<stdlib.h>

typedef int element;

//노드 타입
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p =
		(ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	if (head == NULL) {
	head = p;
	p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	if(head == NULL) {
		head = p;
		p->link  = head;
	}
	else {
		p->link = head->link;
		head->link  = p;
		head = p;
	}
	return head;
}
//리스트 출력
void print_list(ListNode* head)
{
	ListNode* p;
	p = head->link;
	for (ListNode* p = head->link; ; p = p->link)
	{
		printf("%d->", p->data);
		if (p == head)
			break;
	}

}
//data값이 리스트안에 있는지 검사하는 함수
void traverse(ListNode* head, int data)
{
	ListNode* p;
	int cnt = 1;
	int x = 0;
	p = head->link;
	for (p = head->link;; p = p->link)
	{
		if (p->data == data) {
			printf("%d는 %d번째에 있습니다\n", data,cnt);
			x = 1;
		}
		cnt++;
		if (x == 0 && p == head)
		{
			printf("%d는 없습니다\n",data);
		}
		if (p == head) {
			break;
		}
	}
}
int main(void)
{
	ListNode* head = NULL;
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	for (int i = 0; i < 1; i++) {
		
		print_list(head);
	}
	printf("\n");
	traverse(head, 50);
	traverse(head, 20);
	return 0;
}

