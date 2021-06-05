#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5
#define TABLE_SIZE 5

typedef struct element
{
	int key;
} element;

typedef struct list
{
	element item;
	int key;
	struct list* link;
}list;

list* hash_table[TABLE_SIZE];

int hash_func(int key)
{
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_func(item.key);
	struct list* ptr;
	struct list* node_before = NULL;
	struct list* node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;
	int hash_value = hash_func(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "Ž�� %d ���� \n", item.key);
			return;
		}
	}
	printf("Ű�� ã�� ������\n");
}

void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d]->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("===============================\n\n");
}


int main(void)
{
	int data[SIZE] = { 8, 1, 9, 6, 13 };
	element e;
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
}