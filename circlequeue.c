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
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType* q) // ��ȭ ���� �˻� �Լ�
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType* q) // ���� ���� �˻� �Լ�
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("��ȭ ���� ����\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("���� ���� ����\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void print_queue(QueueType* q) // ť ��� �Լ�
{
	printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

void peek(QueueType* q)
{
	printf("\n%d\n\n", q->data[q->rear % MAX_QUEUE_SIZE]);
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

	enqueue(&q, 60);

	return 0;
}