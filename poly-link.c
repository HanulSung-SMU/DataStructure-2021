#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
  int coef;
  int expon;
  struct ListNode *link;
} ListNode;

typedef struct ListType
{
  int size;
  ListNode *head;
  ListNode *tail;
} ListType;

void error(char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(1);
}

ListType* create()
{
  ListType *plist = (ListType *)malloc(sizeof(ListType));
  plist->size = 0;
  plist->head = plist->tail = NULL;
  return plist;
}

void add(ListType* plist, int coef, int expon)
{
  ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
  if(temp == NULL)
  {
    error("memmory allocation error");
  }
  temp->coef = coef;
  temp->expon = expon;
  temp->link = NULL;
  if(plist->tail == NULL)
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

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
  ListNode* a = plist1->head;
  ListNode* b = plist2->head;
  int sum;
  
  while(a && b)
  {
    if(a->expon == b->expon)
    {
      sum = a->coef + b->coef;
      if(sum != 0)
      {
        add(plist3, sum, a->expon);
      }
      a = a->link;
      b = b->link;
    }
    else if(a->expon > b->expon)
    {
      add(plist3, a->coef, a->expon);
      a = a->link;
    }
    else
    {
      add(plist3, b->coef, b->expon);
      b = b->link;
    }
  }

  for(; a != NULL; a = a->link)
  {
    add(plist3, a->coef, a->expon);
  }
  for(; b != NULL; b = b->link)
  {
    add(plist3, b->coef, b->expon);
  }
}

void print_poly(ListType* plist)
{
  ListNode* p = plist->head;
  for(; p; p = p->link)
  {
    printf("%dx^%d + ", p->coef, p->expon);
  }
  printf("\n");
}

int main(void)
{
  ListType *list1, *list2, *list3;

  list1 = create();
  list2 = create();
  list3 = create();

  add(list1, 3, 12);
  add(list1, 2, 8);
  add(list1, 1, 0);
  
  add(list2, 8, 12);
  add(list2, -3, 10);
  add(list2, 10, 6);

  print_poly(list1);
  print_poly(list2);
  
  poly_add(list1, list2, list3);
  print_poly(list3);

  free(list1);
  free(list2);
  free(list3);
}