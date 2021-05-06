//
//  CircularLinkedList.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/06.
//

#include "CircularLinkedList.hpp"

CircularListNode* InsertFirst(CircularListNode * head, int item) {
    CircularListNode * next;
    next = new CircularListNode;
    next -> data = item;

    if (head == NULL) {
        head = next;
        next -> link = head;
    } else {
        next -> link = head -> link;
        head -> link = next;
    }
    
    return head;
}

CircularListNode* InsertLast(CircularListNode * head, int item) {
    CircularListNode * next;
    next = new CircularListNode;
    next -> data = item;
    
    if (head == NULL) {
        head = next;
        next -> link = head;
    } else {
        next -> link = head -> link;
        head -> link = next;
        head = next;
    }
    
    return head;
}

CircularListNode * DeleteFirst(CircularListNode* head) {
    CircularListNode * removed;
    
    if (head == NULL) {
        return NULL;
    } else {
        removed = head -> link;
        head -> link = removed -> link;
        delete removed;
    }
    
    return head;
}

bool traverse(CircularListNode * head, int check) {
    CircularListNode * temp = head;
    
    if (head == NULL) {
        return false;
    } else {
        do {
            if (temp -> data == check) {
                return true;
            }
            temp = temp -> link;
        } while (temp != head);
    }
    return false;
}


void PrintList(CircularListNode* head) {
    CircularListNode * temp;
    temp = head -> link;
    
    if (head == NULL) {
        return;
    }
    
    do {
        cout << temp -> data << " | ";
        temp = temp -> link;
    } while (temp != head);
    cout << temp -> data << "\n";
}
