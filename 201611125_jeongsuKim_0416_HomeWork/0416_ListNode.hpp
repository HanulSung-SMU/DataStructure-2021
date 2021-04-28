#include <stdio.h>
#include <iostream>

using namespace std;

typedef int element_LN;
typedef struct ListNode {
    element_LN data {};
    struct ListNode * link;
} ListNode;

ListNode* InsertFirst(ListNode* head, int item);
ListNode* DeleteFirst(ListNode* head);

ListNode* Insert(ListNode* head, ListNode* pre, int item);
ListNode* Delete(ListNode* head, ListNode* pre, int item);

void PrintList(ListNode* head);
