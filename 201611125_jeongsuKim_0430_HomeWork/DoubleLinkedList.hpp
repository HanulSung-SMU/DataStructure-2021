//
//  DoubleLinkedList.hpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/06.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

typedef int element_DL;
typedef struct DoubleListNode {
    element_DL data {};
    struct DoubleListNode * left_link;
    struct DoubleListNode * right_link;
} DoubleListNode;

void InsertDoubleList(DoubleListNode* before, int item);
void DeleteDoubleListe(DoubleListNode * head, DoubleListNode * removed);

void PrintDList(DoubleListNode * head);
void InitDList(DoubleListNode * head);
#endif /* DoubleLinkedList_hpp */
