//
//  PrioritizedQueue.hpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/14.
//

#ifndef PrioritizedQueue_hpp
#define PrioritizedQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
#define MAX_ELEMENT 200

typedef struct PriQue {
    int key;
    PriQue * left;
    PriQue * right;
} PriQue;

typedef struct element {
    int key;
} element;

typedef struct HeapType {
    int heap_size;
    element heap[MAX_ELEMENT];
} HeapType;

HeapType * create();
void init(HeapType * h);
void insert_max_heap(HeapType * h, element item);

bool isFull(HeapType * h);
bool isEmpty(HeapType * h);

element delete_max_heap(HeapType * h);


#endif /* PrioritizedQueue_hpp */
