#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListnode {
    element data;
    struct DListnode* llink;
    struct DListnode* rlink;
}DListnode;

void init(DListnode* phead)
{
    phead->llink=phead;
    phead->rlink=phead;
}

void print_dlist(DListnode* phead)
{
    DListnode* p;
    for (p=phead->rlink; p!=phead; p=p->rlink){
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

void dinsert(DListnode *before, element data)
{
    DListnode *newnode=(DListnode *)malloc(sizeof(DListnode));
    newnode ->data = data;
    newnode-> llink=before;
    newnode -> rlink=before->rlink;
    before -> rlink-> llink =newnode;
    before->rlink=newnode;
}

void ddelete(DListnode* head, DListnode* removed)
{
    if(removed==head) 
    return;
    removed->llink->rlink=removed->rlink;
    removed->rlink->llink=removed->llink;
    free(removed);
}

int main(void)
{
    DListnode* head = (DListnode *)malloc(sizeof(DListnode));
    init(head);
    printf("추가단계\n");
    for (int i=0; i<5; i++){
        dinsert(head, i);
        print_dlist(head);
    }
    printf("\n삭제단계\n");
    for(int i=0; i<5;i++){
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}
