#include<stdio.h>
#include<time.h>
#define MAX 10
typedef struct Data {
	int data;
	struct Data* link;
}Data;
typedef struct Modular {
	int type;
	struct Modular* link;
	struct Data* dlink;
}Modular;

Modular* head = NULL;																// Modular head 생성

void makeModul(int n) {
	Modular* _head = NULL;
	Modular* rear = NULL;
	for (int i = 0; i < n; i++) {
		Modular* node = (Modular*)malloc(sizeof(Modular));
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
void input(int data, int count) {
	int jump = 0;
	Modular* modulType = head;
	for (int i = 0; i < count; modulType = modulType->link, i++);					// Modultype으로 이동	

	Data* node = (Data*)malloc(sizeof(Data));
	node->link = NULL;
	node->data = data;

	if (modulType->dlink == NULL) {
		modulType->dlink = node;
	}
	else {
		Data* preNode = NULL;
		for (Data* i = modulType->dlink; i != NULL; preNode = i, i = i->link);		// 해당 Modular에 data가 존재시 연결리스트의 마지막 노드로 생성노드를 부착
		preNode->link = node;
	}
}

void radixSort(int list[], int n, int type) {
	int tmp[MAX];
	if(type == 0)
		for (int i = 0; i < n; i++)													// 일의 자리 sort
			tmp[i] = list[i] % 10;
	else
		for (int i = 0; i < n; i++)													// 십의 자리 sort
			tmp[i] = list[i] / 10;
	for (int i = 0; i < n; i++) {
		switch (tmp[i]) {
		case 0:
			input(list[i], 0);
			break;
		case 1:
			input(list[i], 1);
			break;
		case 2:
			input(list[i], 2);
			break;
		case 3:
			input(list[i], 3);
			break;
		case 4:
			input(list[i], 4);
			break;
		case 5:
			input(list[i], 5);
			break;
		case 6:
			input(list[i], 6);
			break;
		case 7:
			input(list[i], 7);
			break;
		case 8:
			input(list[i], 8);
			break;
		case 9:
			input(list[i], 9);
			break;
		}
	}
	int count = 0;
	for (Modular* i = head; i != NULL; i = i->link) {
		for (Data* j = i->dlink; j; j = j->link) 
			list[count++] = j->data;
		i->dlink = NULL;
	}
}

void printList(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}
int main() {
	int i, n = MAX;
	int list[MAX];
	makeModul(MAX);
	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;
	printList(list, n);

	radixSort(list, n, 0);
	radixSort(list, n, 1);

	printf("~SORTED~\n");
	printList(list, n);
}