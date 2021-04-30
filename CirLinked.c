#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL) {
        head = node;
        node ->link;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

void print_list(ListNode *head)
{
    ListNode* p;
    
    if(head == NULL) return;
    p=head ->link;
    do{
        printf("%d->", p->data);
        p=p->link;
    } while(p != head);
    printf("%d", p->data);
    printf("\n");
}

int main(void)
{
    ListNode *head = NULL;
    
    head = insert_last(head, 20); print_list(head);
    head = insert_last(head, 30); print_list(head);
    head = insert_last(head, 40); print_list(head);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}
