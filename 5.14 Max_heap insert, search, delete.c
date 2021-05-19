#define MAX 200
#include<stdio.h>
typedef struct {
	int heap[MAX];
	int size;
} HeapType;

void init_heap(HeapType* heap) {
	heap->size = 0;
}
void print_heap(HeapType* heap) {
	int layer = 2;
	for (int i = 1; i <= heap->size; i++) {
		printf("%d ", heap->heap[i]);
		if ((i + 1) % layer == 0) {
			layer *= 2;
			printf("\n");
		}
	}
	printf("\n");
}

void insert_Max_heap(HeapType* h, int key) {
	int i = ++h->size;
	while (i != 1 && key > h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void delete_Max_heap(HeapType* h) {
	int i = 1;
	int bigger_child;
	int tmp = h->heap[i] = h->heap[(h->size)--];
	while (1) {
		bigger_child = h->heap[i * 2] > h->heap[i * 2 + 1] ? i * 2 : i * 2 + 1;
		h->heap[i] = h->heap[bigger_child];
		if (i * 2 > h->size)
			break;
		if (bigger_child % 2 == 0)
			i *= 2;
		else
			i = i * 2 + 1;
	}
	h->heap[i] = tmp;
}

void search_heap(HeapType* h, int num) {
	printf("Is there 5?\n");
	for (int i = 1; i <= h->size; i++)
		if (h->heap[i] == num) {
			printf("Yes\n");
			return;
		}
	printf("No\n");
}

int main(void)
{
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	if (!heap) {
		printf("memory assignment error");
		exit(1);
	}
	init_heap(heap);
	int num = 0;
	for (int i = 0; i < 6; i++) {
		scanf_s("%d", &num);
		insert_Max_heap(heap, num);
	}
	printf("completed heap\n");
	print_heap(heap);

	search_heap(heap, 5);

	printf("first deleted heap\n");
	delete_Max_heap(heap);
	print_heap(heap);

	printf("second deleted heap\n");
	delete_upheap(heap);
	print_heap(heap);

	free(heap);
	return 0;
}