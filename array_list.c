#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ���� 
}ArrayListType; // ���ο� �ڷ������� ���� 

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* l)
{
	l->size = 0; // ����Ʈ �ʱ�ȭ 
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
		error("����Ʈ ũ�� �ʰ�");
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
		error("��ġ����");
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
		error("��ġ����");
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
