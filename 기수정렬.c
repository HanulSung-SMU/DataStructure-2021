#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode* input(ListNode *head, int value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p -> link){
        printf("%d ", p -> data);
    }
}

int main(void) {
    ListNode *bc0 = NULL;
    ListNode *bc1 = NULL;
    ListNode *bc2 = NULL;
    ListNode *bc3 = NULL;
    ListNode *bc4 = NULL;
    ListNode *bc5 = NULL;
    ListNode *bc6 = NULL;
    ListNode *bc7 = NULL;
    ListNode *bc8 = NULL;
    ListNode *bc9 = NULL;
    
    int list[MAX_SIZE];
    int modnum_list[MAX_SIZE];
    int i, j;
    int val;
    
    srand(time(NULL));
    for(i=0 ; i<MAX_SIZE ; i++) {
        list[i] = rand() % 100;
        for(j=0 ; j<i ; j++) {
            if(list[j] == list[i])
                i--;
                break;
        }
        printf("%d ", list[i]);
    }
    printf("\n\n");
    
    for(i=0 ; i<MAX_SIZE ; i++) {
        modnum_list[i] = list[i]%10;
    }

    for(i=0 ; i<MAX_SIZE ; i++) {
        switch(modnum_list[i]) {
            case 0 :
                bc0 = input(bc0, list[i]);
                break;
            case 1 :
                bc1 = input(bc1, list[i]);
                break;
            case 2 :
                bc2 = input(bc2, list[i]);
                break;
            case 3 :
                bc3 = input(bc3, list[i]);
                break;
            case 4 :
                bc4 = input(bc4, list[i]);
                break;
            case 5 :
                bc5 = input(bc5, list[i]);
                break;
            case 6 :
                bc6 = input(bc6, list[i]);
                break;
            case 7 :
                bc7 = input(bc7, list[i]);
                break;
            case 8 :
                bc8 = input(bc8, list[i]);
                break;
            case 9 :
                bc9 = input(bc9, list[i]);
                break;
        }
    }
    printf("bc0 : "); print_list(bc0); printf("\n");
    printf("bc1 : "); print_list(bc1); printf("\n");
    printf("bc2 : "); print_list(bc2); printf("\n");
    printf("bc3 : "); print_list(bc3); printf("\n");
    printf("bc4 : "); print_list(bc4); printf("\n");
    printf("bc5 : "); print_list(bc5); printf("\n");
    printf("bc6 : "); print_list(bc6); printf("\n");
    printf("bc7 : "); print_list(bc7); printf("\n");
    printf("bc8 : "); print_list(bc8); printf("\n");
    printf("bc9 : "); print_list(bc9); printf("\n");
    
    return 0;
}
