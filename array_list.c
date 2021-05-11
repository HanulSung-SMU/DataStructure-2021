#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수 
}ArrayListType; // 새로운 자료형으로 정의 

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* l)
{
	l->size = 0; // 리스트 초기화 
}

int empty(ArrayListType* l)
{
	return l->size == 0;
}

int full(ArrayListType* l)
{
	return l->size == MAX_LIST_SIZE;
}

void insert_last(ArrayListType* l, element item)
{
	if (l->size >= MAX_LIST_SIZE)
	{
		error("리스트 크기 초과");
	}
	l->array[l->size++] = item;
}

void insert(ArrayListType* l, int pos, element item)
{
	if (!full(l) && (pos >= 0) && (pos <= l->size))
	{
		for (int i = (l->size - 1); i >= pos; i--)
		{
			l->array[i + 1] = l->array[i];
		}
		l->array[pos] = item;
		l->size++;
	}
}

element delete(ArrayListType* l, int pos)
{
	element item;

	if (pos < 0 || pos >= l->size)
	{
		error("위치오류");
	}
	item = l->array[pos];
	
	for (int i = pos; i < (l->size - 1); i++)
	{
		l->array[i] = l->array[i + 1];
	}
	l->size--;
	return item;
}

element get_entry(ArrayListType* l, int pos)
{
	if (pos < 0 || pos >=l->size)
	{
		error("위치오류");
	}
	return l->array[pos];
}

void print_list(ArrayListType* l)
{
	for (int i = 0; i < l->size; i++)
	{
		printf("%d ->", l->array[i]);
	}
	printf("\n");
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
