#include <stdio.h>
#include <stdlib.h>

typedef struct Dlistnode
{
	int data;
	struct Dlistnode *llink;
	struct Dlistnode *rlink;
} Dlistnode;

void init (Dlistnode *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist (Dlistnode *phead)
{
	Dlistnode *p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf ("<-| |%d| |-> ", p->data);
	}
	printf ("\n");
}

void dinsert (Dlistnode *before, int data)
{
	Dlistnode *newnode = (Dlistnode *)malloc(sizeof(Dlistnode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(Dlistnode *head, Dlistnode *removed)
{
	if (removed == head) 
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free (removed);
}

int main (void)
{
	Dlistnode *head = (Dlistnode *)malloc(sizeof(Dlistnode));
	init (head);
	printf ("추가단계\n");
	for (int i=0; i<5; ++i)
	{
		dinsert (head, i);
		print_dlist (head);
	}
	printf ("\n삭제단계\n");
	for (int i=0; i<5; ++i)
	{
		print_dlist(head);
		ddelete (head, head->rlink);
	}
	free (head);
	return 0;
}
