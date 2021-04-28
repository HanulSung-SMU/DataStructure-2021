#include "0416_ListNode.hpp"


ListNode* InsertFirst(ListNode* head, int item) {
    ListNode * next;
    next = new ListNode;
    next -> data = item;
    next -> link = head;
    head = next;
    return head;
}

ListNode* DeleteFirst(ListNode* head) {
    ListNode * removed;
    
    if (head == NULL) {
        return NULL;
    } else {
        removed = head;
        head = removed -> link;
        delete removed;
        return head;
    }
}


void PrintList(ListNode* head) {
    ListNode * temp;
    temp = head;
    while (temp != NULL) {
        cout << temp -> data << " | ";
        temp = temp -> link;
    }
    cout << "Null\n";
}


ListNode* Insert(ListNode* head, ListNode* pre, int item) {
    ListNode * next;
    next = new ListNode;
    next -> data = item;
    next -> link = pre -> link;
    pre -> link = next;
    return head;
}

ListNode* Delete(ListNode* head, ListNode* pre, int item) {
    ListNode * removed;
    removed = pre -> link;
    pre -> link = removed -> link;
    delete removed;
    return head;
}
