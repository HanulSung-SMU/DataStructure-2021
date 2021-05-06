//
//  CircularLinkedList.hpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/06.
//

#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

typedef int element_CL;
typedef struct CircularListNode {
    element_CL data {};
    struct CircularListNode * link;
} CircularListNode;

CircularListNode * InsertFirst(CircularListNode* head, int item);
CircularListNode * InsertLast(CircularListNode* head, int item);
CircularListNode * DeleteFirst(CircularListNode* head);
CircularListNode * DeleteLast(CircularListNode* head);
bool traverse(CircularListNode * head, int check);
void PrintList(CircularListNode * head);

#endif /* CircularLinkedList_hpp */
