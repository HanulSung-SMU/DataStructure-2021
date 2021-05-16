#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

//생성
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

//초기화
void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, int item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int delete_max_heap(HeapType* h)
{
	int parent, child;
	int item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child])break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	int e1 = 10, e2 = 5, e3 = 30;
	int e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5);
	e6 = delete_max_heap(heap);
	printf("< %d >\n ", e6);

	free(heap);
	return 0;
}


