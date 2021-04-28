#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
	int coef;
	int expon;
	struct listnode *link;
} listnode;

typedef struct listtype
{
	int size;
	listnode *head;
	listnode *tail;
} listtype;

void error (char *message)	// ���� �Լ�  
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listtype *create()	// ����Ʈ ��� ���� �Լ�  
{
	listtype *plist = (listtype *)malloc(sizeof(listtype));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last (listtype *plist, int coef, int expon)
{
	listnode *temp = (listnode *)malloc(sizeof(listnode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL)
	{
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(listtype *plist1, listtype *plist2, listtype *plist3)	// ��� �Լ�  
{
	listnode *a = plist1->head;
	listnode *b = plist2->head;
	int sum;
	
	while (a && b)
	{
		if (a->expon == b->expon)	  // a�� ���� = b�� ����
		{
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon)	  // a�� ���� > b�� ����
		{
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else 		// a�� ���� < b�� ����
		{
			insert_last(plist3, b->coef, b->expon);	  
			b = b->link;
		}
	}
	
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(listtype *plist)
{
	listnode *p = plist->head;
	
	printf("polynomial = ");
	for (; p; p = p->link)
	{
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

int main (void)
{
	listtype *list1, *list2, *list3;
	
	// ���� ����Ʈ ��� ����  
	list1 = create();
	list2 = create();
	list3 = create();
	
	// ���׽� 1 ����  
	insert_last(list1, 5, 12);
	insert_last(list1, 1, 10);
	insert_last(list1, 1, 0);
	
	// ���׽� 2 ����  
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 8, 3);
	
	poly_print(list1);
	poly_print(list2);
	
	poly_add(list1, list2, list3);
	poly_print(list3);
	
	free(list1); free(list2); free(list3);
}
	
	
