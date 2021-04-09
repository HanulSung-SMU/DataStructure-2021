#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front; // 맨 마지막 수의 위치를 나타내는 변수
	int rear; // 맨 처음 수의 위치를 나타내는 변수
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message) // 에러 메시지 출력 함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

init_queue(QueueType* q) // 초기화 함수
{
	q->front = -1;
	q->rear = -1;
}

int is_full(QueueType* q) // 포화 상태 검사 함수
{
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(QueueType* q) // 공백 상태 검사 함수
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("포화 상태 오류\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("공백 상태 오류\n");
		return -1;
	}
	return q->data[++(q->front)];
}

void print_queue(QueueType* q) // 큐 출력 함수
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