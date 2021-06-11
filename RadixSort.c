#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100
#define BUCKETS 10
#define DIGITS 4
#define SIZE 10

typedef int element;
typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} Queue;

void InitQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int IsEmpty(Queue* q)
{
	return (q->front == q->rear);
}

int IsFull(Queue* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void Enqueue(Queue* q, element item)
{
	if (IsFull(q))
	{
		fprintf(stderr, "큐가 포화상태입니다.\n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element Dequeue(Queue* q)
{
	if (IsEmpty(q))
	{
		fprintf(stderr, "큐가 공백상태입니다.\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void RadixSort(int* list, int n)
{
	int i, b, d;
	int factor = 1;
	Queue queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++)
		InitQueue(&queues[b]);
	for (d = 0; d < DIGITS; d++)
	{
		for (i = 0; i < n; i++)
		{
			Enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}

		for (b = i = 0; b < BUCKETS; b++)
		{
			while (!IsEmpty(&queues[b]))
				list[i++] = Dequeue(&queues[b]);
		}
		factor *= 10;
	}
}

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		list[i] = rand() % 100;
	}

	RadixSort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}