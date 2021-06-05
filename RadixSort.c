#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

ListNode* insert(ListNode* head, int data)
{
	ListNode * node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;

	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

int main(void)
{
	// 하나 하나 버킷의 헤드 
	ListNode* head0 = NULL;
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	ListNode* head4 = NULL;
	ListNode* head5 = NULL;
	ListNode* head6 = NULL;
	ListNode* head7 = NULL;
	ListNode* head8 = NULL;
	ListNode* head9 = NULL;

	int i, j;
	int val = 0;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 10;

		for (j = 0; j < i; j++)
		{
			if (list[i] == list[j])
			{
				i--;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		switch (list[i]%10)
		{
		case 0:
			head0 = insert(head0, list[i]);
			break;
		case 1:
			head1 = insert(head1, list[i]);
			break;
		case 2:
			head2 = insert(head2, list[i]);
			break;
		case 3:
			head3 = insert(head3, list[i]);
			break;
		case 4:
			head4 = insert(head4, list[i]);
			break;
		case 5:
			head5 = insert(head5, list[i]);
			break;
		case 6:
			head6 = insert(head6, list[i]);
			break;
		case 7:
			head7 = insert(head7, list[i]);
			break;
		case 8:
			head8 = insert(head8, list[i]);
			break;
		case 9:
			head9 = insert(head9, list[i]);
			break;
		}
	}

	print_list(head0);
	printf("\n");
	print_list(head1);
	printf("\n");
	print_list(head2);
	printf("\n");
	print_list(head3);
	printf("\n");
	print_list(head4);
	printf("\n");
	print_list(head5);
	printf("\n");
	print_list(head6);
	printf("\n");
	print_list(head7);
	printf("\n");
	print_list(head8);
	printf("\n");
	print_list(head9);
	printf("\n");
	return 0;

}