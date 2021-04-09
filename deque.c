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

void add_front(QueueType* q, element item)
{
	if (is_full(q)) {
		error("��ȭ ���� ����\n");
	}
	q->data[q->front] = item;
	q->front = (q->front - 1) % MAX_QUEUE_SIZE;
}

void add_rear(QueueType* q, element item) // ť ���� �Լ�
{
	if (is_full(q)) { // ť�� ��ȭ ������ ��� �������� ���
		error("��ȭ ���� ����\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item; 
}

int del_front(QueueType* q) // ť ���� �Լ�
{
	if (is_empty(q)) { // ť�� ���� ������ ��� �������� ���
		error("���� ���� ����\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int del_rear(QueueType* q)
{
	if (is_empty(q)) {
		error("���� ���� ����\n");
	}
	q->rear = (q->rear - 1) % MAX_QUEUE_SIZE;
	return q->data[q->rear];
}
void get_front(QueueType* q) // ť�� �� ���� ���� ���� �Լ�
{
	if (is_empty(q)) { // ť�� ���� ������ ��� �������� ���
		error("���� ���� ����\n");
	}
	printf("\n%d\n\n", q->data[(q->front + 1) % MAX_QUEUE_SIZE]); // ť�� rear ��ġ�� �ִ� �� ���
}

void get_rear(QueueType* q)
{
	if (is_empty(q)) {
		error("���� ���� ����\n");
	}
	printf("\n%d\n\n", q->data[q->rear]);
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

int main(void)
{
	int item = 0;
	QueueType q;
	init_queue(&q);

	add_rear(&q, 10);
	print_queue(&q);
	add_front(&q, 20);
	print_queue(&q);
	add_rear(&q, 30);
	print_queue(&q);
	get_front(&q);
	get_rear(&q);

	del_rear(&q);
	print_queue(&q);
	del_front(&q);
	print_queue(&q);
	get_front(&q);
	get_rear(&q);

	add_rear(&q, 40);
	print_queue(&q);
	del_front(&q);
	print_queue(&q);
	get_rear(&q);
	get_front(&q);

	return 0;
}