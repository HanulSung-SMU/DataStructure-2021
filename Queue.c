/*
* 201710815 Ȳ����
* 6���� ����ť ����
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void init_Queue(Queue* q)
{
	q->front = -1;
	q->rear = -1;
}

int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

int is_full(Queue* q)
{
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue* q, element n)
{
	if (is_full(q))
	{
		fprintf(stderr, "ť ��ȭ �����Դϴ�.\n");
		exit(1);
	}
	else q->data[++(q->rear)] = n;
}

element dequeue(Queue* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "ť ���� �����Դϴ�.\n");
		exit(1);
	}
	else return q->data[++(q->front)];
}

void print_Queue(Queue* q)
{
	int i;

	for (i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
		{
			printf("   | ");
		}
		else printf("%d  | ", q->data[i]);
	}
	printf("\n");
}

int main(void)
{
	Queue q;
	int num;

	init_Queue(&q);

	enqueue(&q, 1);
	print_Queue(&q);
	enqueue(&q, 2);
	print_Queue(&q);
	enqueue(&q, 3);
	print_Queue(&q);
	enqueue(&q, 4);
	print_Queue(&q);
	enqueue(&q, 5);
	print_Queue(&q);

	num = dequeue(&q);
	printf("ť���� ������ �� : %d\n", num);
	print_Queue(&q);
	num = dequeue(&q);
	printf("ť���� ������ �� : %d\n", num);
	print_Queue(&q);
	num = dequeue(&q);
	printf("ť���� ������ �� : %d\n", num);
	print_Queue(&q);

	return 0;
}