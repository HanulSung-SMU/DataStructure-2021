#include <stdio.h>
#include <stdlib.h>
#define max_list_size 100

typedef struct
{
	int array[max_list_size];
	int size;		// ����Ʈ�� ����� �׸���� ����  
} arraylisttype;

void error (char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(arraylisttype *L)	// ����Ʈ �ʱ�ȭ �Լ�  
{
	L->size = 0;
}

int is_empty(arraylisttype *L)
{
	return L->size ==0;
}

int is_full(arraylisttype *L)
{
	return L->size == max_list_size;
}

int get_entry(arraylisttype *L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}

void print_list(arraylisttype *L)
{
	for (int i=0; i < L->size; ++i)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(arraylisttype *L, int item)	// ������ ��ġ�� ����  
{
	if (L->size >= max_list_size)
	{
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}

void insert(arraylisttype *L, int pos, int item)	// �߰� ��ġ�� ����  
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i>=pos; --i)	  
			L->array[i + 1] = L->array[i];			// ��ĭ�� �ڷ� ����
		L->array[pos] = item;
		L->size++;
	}
}

int Delete(arraylisttype *L, int pos)
{
	int item;
	
	if (pos<0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i<(L->size - 1); ++i)
		L->array[i] = L->array[i + 1];		// ��ĭ�� ������ ���  
	L->size--;
	return item;
}

int main(void)
{
	arraylisttype list;
	
	init(&list);
	insert(&list, 0, 10); 	print_list(&list);
	insert(&list, 0, 20); 	print_list(&list);
	insert(&list, 1, 30); 	print_list(&list);
	insert_last(&list, 40);	print_list(&list);
	Delete(&list,1); 		print_list(&list);
	return 0;
}
