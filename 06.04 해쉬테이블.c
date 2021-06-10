#include<stdio.h>
#include<time.h>
#define SIZE 10
#define HASH_SIZE 5
typedef struct Data {
	int data;
	struct Data* link;
}Data;
typedef struct HashTable {
	int type;
	struct HashTable* link;
	struct Data* dlink;
}HashTable;

HashTable* head = NULL;																// Modular head ����

void makeHashTable(int n) {
	HashTable* _head = NULL;
	HashTable* rear = NULL;
	for (int i = 0; i < n; i++) {
		HashTable* node = (HashTable*)malloc(sizeof(HashTable));
		node->type = i;
		node->link = NULL;
		node->dlink = NULL;
		if (_head == NULL) {
			_head = node;
			rear = node;
		}
		else {
			rear->link = node;
			rear = node;
		}
	}
	head = _head;
}
void hash_store(int data, int count) {
	int jump = 0;
	HashTable* hashType = head;
	for (int i = 0; i < count; hashType = hashType->link, i++);					// Modultype���� �̵�	

	Data* node = (Data*)malloc(sizeof(Data));
	node->link = NULL;
	node->data = data;

	if (hashType->dlink == NULL) {
		hashType->dlink = node;
	}
	else {
		Data* preNode = NULL;
		for (Data* i = hashType->dlink; i != NULL; preNode = i, i = i->link);		// �ش� Modular�� data�� ����� ���Ḯ��Ʈ�� ������ ���� ������带 ����
		preNode->link = node;
	}
}

void hash_chain_add(int list[], int n) {
	int tmp[SIZE];
	for (int i = 0; i < n; i++)													// ���� �ڸ� sort
		tmp[i] = list[i] % 5;

	for (int i = 0; i < n; i++) {
		switch (tmp[i]) {
		case 0:
			hash_store(list[i], 0);
			break;
		case 1:
			hash_store(list[i], 1);
			break;
		case 2:
			hash_store(list[i], 2);
			break;
		case 3:
			hash_store(list[i], 3);
			break;
		case 4:
			hash_store(list[i], 4);
			break;
		}
	}
}
void hash_chain_search(int data) {
	int k;
	int index = data % 5;
	HashTable* i = head;
	for (int k = 0; k < index; i = i->link, k++);
	for (Data* j = i->dlink; j != NULL; j = j->link)
	if (j->data == data) {
		printf("%d�� hashTable�� �����մϴ�.\n",data);
		return;
	}
	printf("%d�� hashTable�� �������� �ʽ��ϴ�.\n",data);
}

void hash_chain_print() {
	for (HashTable* i = head; i != NULL; i = i->link) {
		printf("------------------------------\n");
		printf("mode %d\n", i->type);
		for (Data* j = i->dlink; j != NULL; j = j->link)
			printf("%d ", j->data);
		printf("\n");
	}
}
int main(void)
{
	int n = SIZE;
	int hashSize = HASH_SIZE;
	int data[SIZE];
	int compare[SIZE];

	makeHashTable(hashSize);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		data[i] = rand() % 100;
		printf("%d ", data[i]);
	}
	printf("\n");

	hash_chain_add(data, n);
	hash_chain_print();
	printf("\n");

	printf("hashTable�� �����͵���� ��(��� ������ ���;���)\n");
	for (int i = 0; i < SIZE; i++)
		hash_chain_search(data[i]);
	printf("\n\n");
	printf("�������� ������ ���ڵ�� hashTable��\n");
	for (int i = 0; i < n; i++) {
		compare[i] = rand() % 100;
		printf("%d ", compare[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) 
		hash_chain_search(compare[i]);
	return 0;
}