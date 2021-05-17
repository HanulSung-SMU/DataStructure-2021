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

// 히프 초기화
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size); // 마지막 노드에 이어서 삽입해야하므로 사이즈 하나 추가 

	while ((i != 1) && (item.key > h->heap[i / 2].key)) // 삽입할 값이 현재 노드의 부모 노드 값보다 크면 올라가야함
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	} // 값 비교하면서 트리 거슬러 올라가기 

	h->heap[i] = item; // 새로운 노드 삽입
}

// 삭제 함수 
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; // 루트 노드에 있는 값 item에 할당
	temp = h->heap[(h->heap_size)--]; // 마지막 노드에 있는 값을 temp에 할당하고 힙 크기 하나 감소 
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{	
		// 현재 노드의 자식노드 중 더 큰 자식 노드 찾기 
		// -> 루트 노드의 왼쪽 자식 노드(index:2)부터 비교 
		if ((child < h->heap_size) &&
			((h->heap[child].key) < (h->heap[child + 1].key)))
		{
			child++;
		} 

		// 더 큰 자식 노드 찾은 후 
		// 그 노드보다 마지막 노드가 더 크다면 while문 빠져나옴
		if (temp.key >= h->heap[child].key)
		{
			break;
		} 
		// 더 큰 자식 노드 찾은 후 
		// 그 노드보다 마지막 노드가 더 작다면 부모노드와 그 노드를 교환
		h->heap[parent] = h->heap[child]; 
		// 한 단계 아래로 이동
		parent = child;
		child *= 2;
	}
	// 마지막 노드를 재구성한 위치에 삽입 
	h->heap[parent] = temp;
	// 최댓값 반환
	return item;
}

int main(void)
{
	element e1 = { 10 };
	element e2 = { 5 };
	element e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create(); // 히프 생성
	init(heap); // 초기화 

	// 삽입
	insert_max_heap(heap, e1); // 10
	insert_max_heap(heap, e2); // 5
	insert_max_heap(heap, e3); // 30

	// 삭제
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > ", e6.key);

	free(heap);
	return 0;
}