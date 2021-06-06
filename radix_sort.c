#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct ListNode {
    int data;
    struct ListNode* link;
}ListNode;

ListNode* insert(ListNode* head, int data) {
    ListNode * node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
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

void print_list(ListNode* head) {
    ListNode* p;
    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->", p->data);
}

int main(void) {
    ListNode* head_0 = NULL;
    ListNode* head_1 = NULL;
    ListNode* head_2 = NULL;
    ListNode* head_3 = NULL;
    ListNode* head_4 = NULL;
    ListNode* head_5 = NULL;
    ListNode* head_6 = NULL;
    ListNode* head_7 = NULL;
    ListNode* head_8 = NULL;
    ListNode* head_9 = NULL;

    int i, j;
    int n = MAX_SIZE;
    int list[MAX_SIZE];

    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 10;

        for (j = 0; j < i; j++)
        {
            if (list[i] == list[j])
            {
                i--;
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        switch (list[i] % 10)
        {
        case 0:
            head_0 = insert(head_0, list[i]);
            break;
        case 1:
            head_1 = insert(head_1, list[i]);
            break;
        case 2:
            head_2 = insert(head_2, list[i]);
            break;
        case 3:
            head_3 = insert(head_3, list[i]);
            break;
        case 4:
            head_4 = insert(head_4, list[i]);
            break;
        case 5:
            head_5 = insert(head_5, list[i]);
            break;
        case 6:
            head_6 = insert(head_6, list[i]);
            break;
        case 7:
            head_7 = insert(head_7, list[i]);
            break;
        case 8:
            head_8 = insert(head_8, list[i]);
            break;
        case 9:
            head_9 = insert(head_9, list[i]);
            break;
        }
    }

    print_list(head_0); printf("\n");
    print_list(head_1); printf("\n");
    print_list(head_2); printf("\n");
    print_list(head_3); printf("\n");
    print_list(head_4); printf("\n");
    print_list(head_5); printf("\n");
    print_list(head_6); printf("\n");
    print_list(head_7); printf("\n");
    print_list(head_8); printf("\n");
    print_list(head_9); printf("\n");
    
    return 0;
}
