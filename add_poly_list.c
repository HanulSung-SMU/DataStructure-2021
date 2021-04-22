#include <stdio.h>
#include <stdlib.h>

//노드
typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;
//연결 리스트
typedef struct {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;
//오류
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//리스트 헤더 생성
ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    
    if (temp == NULL)
        error("Memory Error");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    
    if (plist->tail == NULL)
        plist->head = plist->tail = temp;
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void polyAdd(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;
    
    while(a && b) {
        if(a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) 
                insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
            else if (a->expon > b->expon) {
                insert_last(plist3, a->coef, a->expon);
                a = a->link;
            }
            else {
                insert_last(plist3, b->coef, b->expon);
                b = b->link;
            }
    }
        for (; a != NULL; a = a->link){
            insert_last(plist3, a->coef, a->expon);
        }
        for (; b != NULL; b = b->link) {
            insert_last(plist3, b->coef, b->expon);
        }
    }
}
//
void polyPrint(ListType* plist) {
    ListNode* p = plist->head;
    
    printf("polynomial = ");
    for (; p; p = p->link) { // while(p != NULL)
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int main(void) {
    ListType *list1, *list2, *list3;
    
    list1 = create();
    list2 = create();
    list3 = create();
    
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);
    
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);
    
    polyPrint(list1);
    polyPrint(list2);
    
    polyAdd(list1, list2, list3);
    polyPrint(list3);
    
    free(list1);
    free(list2);
    free(list3);
    
    return 0;
}

