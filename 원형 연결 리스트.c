#include<stdio.h>
#include<stdlib.h>

typedef int element;

//��� Ÿ��
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
//����Ʈ ���
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
//data���� ����Ʈ�ȿ� �ִ��� �˻��ϴ� �Լ�
void traverse(ListNode* head, int data)
{
	ListNode* p;
	int cnt = 1;
	int x = 0;
	p = head->link;
	for (p = head->link;; p = p->link)
	{
		if (p->data == data) {
			printf("%d�� %d��°�� �ֽ��ϴ�\n", data,cnt);
			x = 1;
		}
		cnt++;
		if (x == 0 && p == head)
		{
			printf("%d�� �����ϴ�\n",data);
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

