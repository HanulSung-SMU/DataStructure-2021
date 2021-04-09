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
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType* q) // 포화 상태 검사 함수
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType* q) // 공백 상태 검사 함수
{
	return (q->front == q->rear);
}

void add_front(QueueType* q, element item)
{
	if (is_full(q)) {
		error("포화 상태 오류\n");
	}
	q->data[q->front] = item;
	q->front = (q->front - 1) % MAX_QUEUE_SIZE;
}

void add_rear(QueueType* q, element item) // 큐 삽입 함수
{
	if (is_full(q)) { // 큐가 포화 상태일 경우 오류문자 출력
		error("포화 상태 오류\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item; 
}

int del_front(QueueType* q) // 큐 삭제 함수
{
	if (is_empty(q)) { // 큐가 공백 상태일 경우 오류문자 출력
		error("공백 상태 오류\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int del_rear(QueueType* q)
{
	if (is_empty(q)) {
		error("공백 상태 오류\n");
	}
	q->rear = (q->rear - 1) % MAX_QUEUE_SIZE;
	return q->data[q->rear];
}
void get_front(QueueType* q) // 큐의 맨 앞의 값을 보는 함수
{
	if (is_empty(q)) { // 큐가 공백 상태일 경우 오류문자 출력
		error("공백 상태 오류\n");
	}
	printf("\n%d\n\n", q->data[(q->front + 1) % MAX_QUEUE_SIZE]); // 큐의 rear 위치에 있는 값 출력
}

void get_rear(QueueType* q)
{
	if (is_empty(q)) {
		error("공백 상태 오류\n");
	}
	printf("\n%d\n\n", q->data[q->rear]);
}
void print_queue(QueueType* q) // 큐 출력 함수
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