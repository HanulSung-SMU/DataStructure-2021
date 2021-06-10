#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define SIZE 10
#define BUCKETS 10
#define DIGITS  2	//�ڸ���

typedef int element;
typedef struct {
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ �����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < BUCKETS; b++)
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;		//���� �ڸ����� �Ѿ��		
	}
}

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;

	printf("��� ���� ��\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");

	radix_sort(list, SIZE);

	printf("��� ���� ��\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	return 0;
}