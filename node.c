#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

//오류
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//리스트 처음에 삽입
ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
//노드 pre 뒤에 삽입
ListNode* insert(ListNode *head, ListNode *pre, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}
//맨 앞 삭제
ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if(head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}
//삭제
ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
//출력
void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}
//메인
int main(void) {
    ListNode *head = NULL;
    int i;
    for (i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    for (i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}
