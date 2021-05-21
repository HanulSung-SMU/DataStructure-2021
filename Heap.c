#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heapSize;
} HeapType;

HeapType* Create(void)
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void Init(HeapType* h)
{
	h->heapSize = 0;
}

void InsertMaxHeap(HeapType* h, element item)
{
	int i;
	i = ++(h->heapSize);

	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element DeleteMaxHeap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heapSize)--];
	parent = 1;
	child = 2;

	while (child <= h->heapSize)
	{
		if ((child < h->heapSize) && (h->heap[child].key) < (h->heap[child + 1].key))
		{
			child++;
		}
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = Create();
	Init(heap);

	InsertMaxHeap(heap, e1);
	InsertMaxHeap(heap, e2);
	InsertMaxHeap(heap, e3);

	e4 = DeleteMaxHeap(heap);
	printf("< %d > ", e4.key);
	e5 = DeleteMaxHeap(heap);
	printf("< %d > ", e5.key);
	e6 = DeleteMaxHeap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}