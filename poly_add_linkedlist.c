#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode *Link;
} ListNode;

typedef struct ListType{
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

ListType* create()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->coef = coef;
    temp->expon = expon;
    temp->Link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }
    else{
        plist->tail->Link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3)
{
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    
    while(a && b){
        if(a->expon == b->expon){
            sum = a->coef + b->coef;
            if(sum != 0)
            insert_last(plist3, sum, a->expon);
            a = a->Link; b = b->Link;
        }
        else if(a->expon > b->expon){
            insert_last(plist3, a->coef, a->expon);
            a = a->Link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b = b->Link;
        }
    }
}

void poly_print(ListType *plist)
{
    ListNode *p = plist->head;
    printf("다항식 = ");
    for( ; p; p=p->Link){
        printf("%d ^ %d +", p->coef, p->expon);
    }
    printf("\n");
}

int main()
{
    ListType *list1, *list2, *list3;
    list1 = create();
    list2 = create();
    list3 = create();
    
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);
    
    insert_last(list2, 1, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);
    
    poly_print(list1);
    poly_print(list2);
    
    poly_add(list1, list2, list3);
    poly_print(list3);
    
    free(list1); free(list2); free(list3);
}