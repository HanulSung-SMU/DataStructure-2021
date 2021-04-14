#include <stdio.h>
#include <stdlib.h>
#define max_queue_size 5

typedef struct
{
	int front;
	int rear;
	int data[max_queue_size];
} queuetype;

void error (char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(queuetype *q)
{
	q->rear = -1;
	q->front = -1;
}
void queue_print(queuetype *q)
{
	for (int i=0; i<max_queue_size; ++i)
	{
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full (queuetype *q)
{
	if (q->rear == max_queue_size - 1)
		return 1;
	else
		return 0;
}

int is_empty(queuetype *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(queuetype *q, int item)
{
	if (is_full(q))
	{
		error("큐가 포화상태");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(queuetype *q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main()
{
	int item = 0;
	queuetype q;
	
	init_queue(&q);
	
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	
	return 0;
}
