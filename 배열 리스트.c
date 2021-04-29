#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;

//����ü ����
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayList;

//����
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//����Ʈ �ʱ�ȭ
void init(ArrayList* L)
{
	L->size = 0;
}
//���� �˻�
int is_empty(ArrayList* L)
{
	return L->size == 0;
}
//��ȭ �˻�
int is_full(ArrayList* L)
{
	return L->size == MAX_LIST_SIZE;
}

//pos ��ġ�� ��Ҹ� �����ش�
element get_entry(ArrayList* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ����");
	return L->array[pos];
}
//����Ʈ ���
void print_list(ArrayList* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
//����Ʈ �������� ��� �߰�
void insert_last(ArrayList* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
	{
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}
//pos��ġ�� ��� ����
void insert(ArrayList* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
//pos��ġ�� ��� ����
element delete(ArrayList* L, int pos)
{
	element item;

	if (pos<0 || pos>L->size)
		error("��ġ����");
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