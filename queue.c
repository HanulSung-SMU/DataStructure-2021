#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front; // �� ������ ���� ��ġ�� ��Ÿ���� ����
	int rear; // �� ó�� ���� ��ġ�� ��Ÿ���� ����
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message) // ���� �޽��� ��� �Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

init_queue(QueueType* q) // �ʱ�ȭ �Լ�
{
	q->front = -1;
	q->rear = -1;
}

int is_full(QueueType* q) // ��ȭ ���� �˻� �Լ�
{
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(QueueType* q) // ���� ���� �˻� �Լ�
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("��ȭ ���� ����\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("���� ���� ����\n");
		return -1;
	}
	return q->data[++(q->front)];
}

void print_queue(QueueType* q) // ť ��� �Լ�
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf(" | ");
		}
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

void peek(QueueType* q)
{
	printf("\n%d\n\n", q->data[q->rear]);
}

int main(void)
{
	int item = 0;
	QueueType q;
	init_queue(&q);

	enqueue(&q, 10);
	print_queue(&q);
	enqueue(&q, 20);
	print_queue(&q);
	enqueue(&q, 30);
	print_queue(&q);

	peek(&q);

	enqueue(&q, 40);
	print_queue(&q);
	enqueue(&q, 50);
	print_queue(&q);

	peek(&q);

	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);

	peek(&q);

	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);

	enqueue(&q, 60);

	return 0;
}