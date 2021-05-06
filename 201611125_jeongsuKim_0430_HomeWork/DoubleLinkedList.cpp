//
//  DoubleLinkedList.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/06.
//

#include "DoubleLinkedList.hpp"

void InsertDoubleList(DoubleListNode* before, int item) {
    DoubleListNode * add = new DoubleListNode;
    add -> data = item;
    add -> left_link = before;
    add -> right_link = before -> right_link;
    before -> right_link -> left_link = add;
    before -> right_link = add;
}
void DeleteDoubleListe(DoubleListNode * head, DoubleListNode * removed) {
    if (removed == head) {
        return;
    } else {
        removed -> left_link -> right_link = removed -> right_link;
        removed -> right_link -> left_link = removed -> left_link;
        delete removed;
    }
}

void PrintDList(DoubleListNode * head) {
    DoubleListNode * temp;
    
    if (head == NULL) {
        return;
    } else {
        temp = head -> right_link;
        while (temp != head) {
            cout << temp -> data << " | ";
            temp = temp -> right_link;
        }
        cout << "\n";
    }
}

void InitDList(DoubleListNode * head) {
    head -> right_link = head;
    head -> left_link = head;
}
