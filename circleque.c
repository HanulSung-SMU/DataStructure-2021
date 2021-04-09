#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef int element;
typedef struct { 
	element data[MAX_SIZE];
	int head, tail;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->head = q->tail = 0;
}

int is_empty(QueueType* q)
{
	return (q->head == q->tail);
}

int is_full(QueueType* q)
{
	return ((q->tail + 1) % MAX_SIZE == q->head);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(head=%d rear=%d) = ", q->head, q->tail);
	if (!is_empty(q)) {
		int i = q->head;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->tail)
				break;
		} while (i != q->head);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->tail = (q->tail + 1) % MAX_SIZE;
	q->data[q->tail] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->head = (q->head + 1) % MAX_SIZE;
	return q->data[q->head];
}
int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}