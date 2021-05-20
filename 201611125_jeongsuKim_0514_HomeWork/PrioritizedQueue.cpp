//
//  PrioritizedQueue.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/14.
//

#include "PrioritizedQueue.hpp"


HeapType * create() {
    return new HeapType;
}

void init(HeapType * h) {
    h -> heap_size = 0;
}

void insert_max_heap(HeapType * h, element item) {
    int i;
    i = ++(h -> heap_size);
    
    while ((i != 1) && (item.key > h -> heap[i / 2].key)) {
        h -> heap[i] = h -> heap[i / 2];
        i /= 2;
    }
    h -> heap[i] = item;
}

element delete_max_heap(HeapType * h) {
    int parent, child;
    element item, temp;
    
    item = h -> heap[1];
    temp = h -> heap[(h -> heap_size)--];
    parent = 1;
    child = 2;
    
    while (child <= h -> heap_size) {
        if ((child < h -> heap_size) && (h -> heap[child].key) < h -> heap[child + 1].key) {
            child++;
        }
        
        if (temp.key >= h -> heap[child].key) {
            break;
        }
        
        h -> heap[parent] = h -> heap[child];
        parent = child;
        child *= 2;
    }
    h -> heap[parent] = temp;
    return item;
}

bool isFull(HeapType * h);
bool isEmpty(HeapType * h);


