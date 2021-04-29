#include<stdio.h>
#define MAX_LIST_SIZE 100


typedef int element; //배열,항목을 구조체로 묶어서 새로운 타입정의
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

//오류처리함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
//비어 있으면 1 아니면0 반환
int is_empty(ArrayListType*L)
{
	return L -> size == 0;
}
//가득 차 있으면 1 아니면0 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
//pos 위치의 요소 반환
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치오류");
	return L->array[pos];
}
//리스트의 요소 표시
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
//맨끝에 항목 추가
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
//pos위치에 요소를 추가
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
//pos위치의 요소 삭제
element delete(ArrayListType* l, int pos)
{
	element item;
	if (pos < 0 || pos >= l->size) {
		error("위치오류");
	}
	item = l->array[pos];
	for (int i = pos; i < (l->size - 1); i++)
		l->array[i] = l->array[i + 1];
	l->size--;
	return item;
}

int main(void)
{
	ArrayListType list;

	init(&list);

	insert(&list, 0, 10);
	print_list(&list);
	insert(&list, 0, 20);
	print_list(&list);
	insert(&list, 0, 30);
	print_list(&list);

	insert_last(&list, 40);
	print_list(&list);

	delete(&list, 2);
	print_list(&list);

	return 0;
}
