#include <stdio.h>
#include <stdlib.h>
#define max_list_size 100

typedef struct
{
	int array[max_list_size];
	int size;		// 리스트에 저장된 항목들의 개수  
} arraylisttype;

void error (char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(arraylisttype *L)	// 리스트 초기화 함수  
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
		error("위치 오류");
	return L->array[pos];
}

void print_list(arraylisttype *L)
{
	for (int i=0; i < L->size; ++i)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(arraylisttype *L, int item)	// 마지막 위치에 삽입  
{
	if (L->size >= max_list_size)
	{
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(arraylisttype *L, int pos, int item)	// 중간 위치에 삽입  
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i>=pos; --i)	  
			L->array[i + 1] = L->array[i];			// 한칸씩 뒤로 밀음
		L->array[pos] = item;
		L->size++;
	}
}

int Delete(arraylisttype *L, int pos)
{
	int item;
	
	if (pos<0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i<(L->size - 1); ++i)
		L->array[i] = L->array[i + 1];		// 한칸씩 앞으로 당김  
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
