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
    int heap_size;
} HeapType;

//생성함수
HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

//초기화함수
void init(HeapType *h)
{
    h->heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입함수
void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key > h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; //새로운 노드를 삽입
}

//삭제함수
element delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        //현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key)
            break;
        //한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n)
{
    int i;
    HeapType *h;

    h = create();
    init(h);
    for (i = 0; i < n; i++)
    {
        insert_max_heap(h, a[i]);
    }
    for (i = (n - 1); i >= 0; i--)
    {
        a[i] = delete_max_heap(h);
    }
    free(h);
}

int main(void)
{
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType *heap;

    heap = create(); //히프 생성
    init(heap);      //초기화

    //삽입
    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    //삭제
    e4 = delete_max_heap(heap);
    printf("< %d >", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d >", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d >", e6.key);

    free(heap);

    return 0;
}