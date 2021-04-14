#include <stdio.h>
#include <stdlib.h>

#define max_queue_size 5
typedef struct
{
int data[max_queue_size];
int front, rear;
} dequetype;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(dequetype *q)
{
	q->front = q->rear = 0;
}

int is_empty(dequetype *q)
{
	return (q->front == q->rear);
}


int is_full(dequetype *q)
{
	return ((q->rear + 1) % max_queue_size == q->front);
}

void deque_print(dequetype *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % max_queue_size;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
			} while (i != q->front);
	}
	printf("\n");
}

void add_rear(dequetype *q, int item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

int delete_front(dequetype *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

int get_front(dequetype *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % max_queue_size];
}

void add_front(dequetype *q, int val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + max_queue_size) % max_queue_size;
}

int delete_rear(dequetype *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + max_queue_size) % max_queue_size;
	return q->data[prev];
}

int get_rear(dequetype *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int main()
{
	dequetype queue;
	
	init_deque(&queue);
	for (int i = 0; i<3; ++i)
	{
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i<3; ++i)
	{
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}
