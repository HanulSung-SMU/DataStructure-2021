/*
* 201710815 황선웅
* 6주차 덱 구현
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
} Deque;

void init_Deque(Deque* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(Deque* q)
{
	return (q->front == q->rear);
}

int is_full(Deque* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void add_rear(Deque* q, element n)
{
	if (is_full(q))
	{
		fprintf(stderr, "큐 포화 상태입니다.\n");
		exit(1);
	}
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = n;
	}
}

element delete_front(Deque* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "큐 공백 상태입니다.\n");
		exit(1);
	}
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void add_front(Deque* q, element n)
{
	if (is_full(q))
	{
		fprintf(stderr, "큐 포화 상태입니다.\n");
		exit(1);
	}
	else
	{
		q->data[q->front] = n;
		q->front = ((q->front - 1) + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
}

element delete_rear(Deque* q)
{
	int rearIndex;
	if (is_empty(q))
	{
		fprintf(stderr, "큐 공백 상태입니다.\n");
		exit(1);
	}
	else
	{
		rearIndex = q->rear;
		q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return q->data[rearIndex];
	}
}

void print_Deque(Deque* q)
{
	int i;
	printf("Deque(front : %d, rear : %d) : ", q->front, q->rear);
	if (!is_empty(q))
	{
		i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

int main(void)
{
	Deque q;

	init_Deque(&q);

	add_front(&q, 1);
	print_Deque(&q);
	add_front(&q, 2);
	print_Deque(&q);
	add_front(&q, 3);
	print_Deque(&q);

	delete_rear(&q);
	print_Deque(&q);
	delete_rear(&q);
	print_Deque(&q);
	delete_rear(&q);
	print_Deque(&q);

	return 0;
}