#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *Link;
}ListNode;

ListNode *insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->Link = head;
    head = p;
    return head;
}
ListNode *delete_first(ListNode *head)
{
    ListNode * removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->Link;
    free(removed);
    return head;
}
void print_list(ListNode *head)
{
    for(ListNode *p = head; p!= NULL; p = p->Link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main()
{
    ListNode *head = NULL;
    
    for(int i = 0; i<5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    for(int i = 0; i<5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}