#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct
{
	element data[MAX_LIST_SIZE];
	int size;
} ArrayList;

void init_ArrayList(ArrayList* a)
{
	a->size = 0;
}

int is_empty(ArrayList* a)
{
	return a->size == 0;
}

int is_full(ArrayList* a)
{
	return a->size == MAX_LIST_SIZE;
}

void insert(ArrayList* a, int pos, element n)
{
	int i;
	if (!is_full(a) && pos >= 0 && pos <= a->size)
	{
		for (i = a->size - 1; i >= pos; i--)
		{
			a->data[i + 1] = a->data[i];
		}
		a->data[pos] = n;
		a->size++;
	}
}

void insert_last(ArrayList* a, element n)
{
	if (is_full(a))
	{
		fprintf(stderr, "더이상 입력시 리스트 오버플로우가 발생합니다.\n");
		exit(1);
	}
	else
	{
		a->data[a->size] = n;
		a->size++;
	}
}

element delete(ArrayList* a, int pos)
{
	int i;
	element temp;

	if (pos < 0 || pos >= a->size)
	{
		fprintf(stderr, "위치 오류 발생\n");
		exit(1);
	}
	else
	{
		temp = a->data[pos];
		for (i = pos; i < a->size - 1; i++)
		{
			a->data[i] = a->data[i + 1];
		}
		a->size--;
		return temp;
	}
}

element get_entry(ArrayList* a, int pos)
{
	if (pos < 0 || pos >= a->size)
	{
		fprintf(stderr, "위치 오류 발생\n");
		exit(1);
	}
	else
	{
		return a->data[pos];
	}
}

void print_ArrayList(ArrayList* a)
{
	int i;
	for (i = 0; i < a->size; i++)
	{
		printf("%d->", a->data[i]);
	}
	printf("\n");
}

int main(void)
{
	ArrayList list;

	init_ArrayList(&list);

	insert(&list, 0, 10);
	print_ArrayList(&list);
	insert(&list, 0, 20);
	print_ArrayList(&list);
	insert(&list, 0, 30);
	print_ArrayList(&list);
	insert_last(&list, 40);
	print_ArrayList(&list);

	delete(&list, 0);
	print_ArrayList(&list);
	delete(&list, 1);
	print_ArrayList(&list);

	return 0;
}