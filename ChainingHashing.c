#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct Node
{
	int value;
	struct Node* link;
} Node;

Node* InsertLastHashValue(Node* head, int n)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	newNode->value = n;
	if (head == NULL)
	{
		head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}
	return head;
}

int SearchHashValue(Node* head, int n)
{
	Node* i;
	int check = 0;
	for (i = head->link; i != head; i = i->link)
	{
		if (i->value == n)
		{
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		if (i->value == n)
		{
			check = 1;
		}
	}

	return check;
}

void PrintHashValue(Node* head)
{
	if (head == NULL) return;
	Node* node;
	for (node = head->link; node != head; node = node->link)
	{
		printf("[%d]-> ", node->value);
	}
	printf("[%d]", node->value);
}

int main(void)
{
	Node* head[MAX_SIZE] = { NULL };

	int num[MAX_SIZE];
	int i;
	int index;
	int findNum;

	srand(time(NULL));

	for (i = 0; i < MAX_SIZE; i++)
	{
		num[i] = rand() % 100;
	}

	for (i = 0; i < MAX_SIZE; i++)
	{
		index = num[i] % 10;
		head[index] = InsertLastHashValue(head[index], num[i]);
	}

	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("head %d: ", i);
		PrintHashValue(head[i]);
		printf("\n");
	}

	printf("탐색하고 싶은 정수를 입력하세요 : ");
	scanf_s("%d", &findNum);
	index = findNum % 10;
	if (head[index] == NULL)
	{
		printf("%d 를 탐색 실패\n", findNum);
	}
	else if (SearchHashValue(head[index], findNum) == 1)
	{
		printf("%d 를 탐색 성공\n", findNum);
	}
	else
	{
		printf("%d 를 탐색 실패\n", findNum);
	}

	return 0;
}