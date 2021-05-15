#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

void insertMaxHeap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);
    
    while((i != 1) && (item.key > h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element deleteMaxHeap(HeapType* h) {
    int parent, child;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size) {
        if((child < h->heap_size) && (h->heap[child].key < h->heap[child+1].key))
            child++;
        if(temp.key >= h->heap[child].key)
            break;
        
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void) {
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType* heap;
    
    heap = create();
    init(heap);
    
    insertMaxHeap(heap, e1);
    insertMaxHeap(heap, e2);
    insertMaxHeap(heap, e3);
    
    e4 = deleteMaxHeap(heap);
    printf("[ %d ] ", e4.key);
    e5 = deleteMaxHeap(heap);
    printf("[ %d ] ", e5.key);
    e6 = deleteMaxHeap(heap);
    printf("[ %d ] \n", e6.key);
    
    free(heap);
    return 0;
}

