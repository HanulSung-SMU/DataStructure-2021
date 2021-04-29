#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

//구조체 선언
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayList;

//에러
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//리스트 초기화
void init(ArrayList* L)
{
	L->size = 0;
}
//공백 검사
int is_empty(ArrayList* L)
{
	return L->size == 0;
}
//포화 검사
int is_full(ArrayList* L)
{
	return L->size == MAX_LIST_SIZE;
}

//pos 위치의 요소를 보여준다
element get_entry(ArrayList* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치오류");
	return L->array[pos];
}
//리스트 출력
void print_list(ArrayList* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
//리스트 마지막에 요소 추가
void insert_last(ArrayList* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
//pos위치에 요소 삽입
void insert(ArrayList* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
//pos위치의 요소 삭제
element delete(ArrayList* L, int pos)
{
	element item;

	if (pos<0 || pos>L->size)
		error("위치오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

int main(void)
{
	ArrayList list;

	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
	return 0;


}