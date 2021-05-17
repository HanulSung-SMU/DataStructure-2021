#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct
{
	int key;
}element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// ���� �ʱ�ȭ
void init(HeapType* h)
{
	h->heap_size = 0;
}

// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size); // ������ ��忡 �̾ �����ؾ��ϹǷ� ������ �ϳ� �߰� 

	while ((i != 1) && (item.key > h->heap[i / 2].key)) // ������ ���� ���� ����� �θ� ��� ������ ũ�� �ö󰡾���
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	} // �� ���ϸ鼭 Ʈ�� �Ž��� �ö󰡱� 

	h->heap[i] = item; // ���ο� ��� ����
}

// ���� �Լ� 
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; // ��Ʈ ��忡 �ִ� �� item�� �Ҵ�
	temp = h->heap[(h->heap_size)--]; // ������ ��忡 �ִ� ���� temp�� �Ҵ��ϰ� �� ũ�� �ϳ� ���� 
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{	
		// ���� ����� �ڽĳ�� �� �� ū �ڽ� ��� ã�� 
		// -> ��Ʈ ����� ���� �ڽ� ���(index:2)���� �� 
		if ((child < h->heap_size) &&
			((h->heap[child].key) < (h->heap[child + 1].key)))
		{
			child++;
		} 

		// �� ū �ڽ� ��� ã�� �� 
		// �� ��庸�� ������ ��尡 �� ũ�ٸ� while�� ��������
		if (temp.key >= h->heap[child].key)
		{
			break;
		} 
		// �� ū �ڽ� ��� ã�� �� 
		// �� ��庸�� ������ ��尡 �� �۴ٸ� �θ���� �� ��带 ��ȯ
		h->heap[parent] = h->heap[child]; 
		// �� �ܰ� �Ʒ��� �̵�
		parent = child;
		child *= 2;
	}
	// ������ ��带 �籸���� ��ġ�� ���� 
	h->heap[parent] = temp;
	// �ִ� ��ȯ
	return item;
}

int main(void)
{
	element e1 = { 10 };
	element e2 = { 5 };
	element e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create(); // ���� ����
	init(heap); // �ʱ�ȭ 

	// ����
	insert_max_heap(heap, e1); // 10
	insert_max_heap(heap, e2); // 5
	insert_max_heap(heap, e3); // 30

	// ����
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > ", e6.key);

	free(heap);
	return 0;
}