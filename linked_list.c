#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

//오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode * insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    
    return head;
}

//노드 pre뒤에 새로운 노드 삽입
ListNode * insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    
    return head;
}

ListNode * delete_first(ListNode *head)
{
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    
    return head;
}

//pre가 가리키는 노드의 다음 노드를 삭제한다
ListNode * delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    
    return head;
}

void print_list(ListNode *head)
{
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
        printf("NULL \n");
}

//테스트 프로그램
int main(void)
{
    ListNode *head = NULL;
    
    for(int i = 0; i < 5; i++){
        head = insert_first(head, i);   //insert_first()가 반환된 헤드 포인터를 head에 대입한다.
        print_list(head);
    }
    for(int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}
