#include<stdio.h>
#define MAX 100
typedef struct ArrayList {
	int data[MAX];
	int count;
}ArrayList;
void init(ArrayList* list) {
	list->count = 0;
}
int is_empty(ArrayList* list) {
	return list->count == 0;
}
int is_full(ArrayList* list) {
	return list->count == MAX;
}

void insert(ArrayList* list, int pos, int val) {
	if (is_full(list)) {
		printf("memory is full");
		exit(1);
	}
	else {
		for (int i = list->count; i >= pos; i--)
			list->data[i + 1] = list->data[i];
		list->data[pos] = val;
		list->count++;
	}
}
void insert_last(ArrayList* list, int val) {
	if (is_full(list)) {
		printf("memory is full");
		exit(1);
	}
	else 
		list->data[list->count++] = val;
}
void delete(ArrayList* list, int pos) {
	if (is_empty(list)) {
		printf("memory is full");
		exit(1);
	}
	else {
		for (int i = pos - 1; i < list->count; i++)
			list->data[i] = list->data[i + 1];

		list->count--;
	}
}

void print_list(ArrayList* list) {
	for (int i = 0; ; ) {
		printf("%d ", list->data[i]);
		i++;
		if (i == list->count)
			break;
		printf("-> ");
	}
	printf(" count : %d\n", list->count);
}
int main(void)
{
	ArrayList list;
	init(&list);
	insert(&list, 0, 10); print_list(&list); 
	insert(&list, 0, 30); print_list(&list); 
	insert(&list, 0, 40); print_list(&list); 
	insert(&list, 2, 20); print_list(&list);
	insert_last(&list, 40); print_list(&list); 
	delete(&list, 3); print_list(&list); 
	return 0;
}