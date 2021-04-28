#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// 덱

typedef struct
{
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_q(QueueType* q)
{
	q->rear = 0;
	q->front = 0;
}


int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void add_front(QueueType* q, int item) {
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	q->front = ((q->front - 1) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	q->data[(q->front + 1) % MAX_QUEUE_SIZE] = item;
}


int delete_rear(QueueType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	q->rear = ((q->rear - 1) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[q->rear];
}

void q_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int main(void)
{
	int item = 0;
	QueueType q;

	init_q(&q);

	enqueue(&q, 10);
	q_print(&q);
	enqueue(&q, 20);
	q_print(&q);
	enqueue(&q, 30);
	q_print(&q);
	enqueue(&q, 40);
	q_print(&q);

	item = delete_rear(&q);
	q_print(&q);
	item = dequeue(&q);
	q_print(&q);

	add_front(&q, 7);
	q_print(&q);
	add_front(&q, 9);
	q_print(&q);
	item = delete_rear(&q);
	q_print(&q);
	enqueue(&q, 33);
	q_print(&q);

	return 0;
}