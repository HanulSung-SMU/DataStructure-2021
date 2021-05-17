#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 200

typedef struct{
	int key;
}element;

typedef struct{
	element heap[MAX_QUEUE_SIZE];
	int heap_size;
}Heaptype;

Heaptype *create()
{
	return (Heaptype*)malloc(sizeof(Heaptype));
}

void init(Heaptype *h)
{
	h->heap_size = 0;
}

void insert_heap(Heaptype *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while((i != 1) && (item.key > h->heap[i / 2].key)){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(Heaptype *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while(child <= h->heap_size){
		if((child < h->heap_size) && (h->heap[child].key < h->heap[child +1].key))
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

int main(void)
{
	element e1 = {10}, e2 = {5}, e3 = {30};
	element e4, e5, e6;
	Heaptype *heap;

	heap = create();
	init(heap);

	insert_heap(heap, e1);
	insert_heap(heap, e2);
	insert_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("<%d> ", e4.key);
	e5 = delete_max_heap(heap);
	printf("<%d> ", e5.key);
	e6 = delete_max_heap(heap);
	printf("<%d> ", e6.key);
	printf("\n");
	free(heap);
	return 0;
}
