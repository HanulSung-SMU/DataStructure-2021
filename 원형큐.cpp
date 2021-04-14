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
	q->rear = q->front = 0;
}

int is_empty(queuetype *q)
{
	return (q->front == q->rear);
}

void queue_print(queuetype *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
			} while (i != q->front);
	}
	printf("\n");
}

int is_full (queuetype *q)
{
	return ((q->rear + 1) % max_queue_size == q->front);
}



void enqueue(queuetype *q, int item)
{
	if (is_full(q))
		error("ť�� ��ȭ����");
	
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[(q->rear)] = item;
}

int dequeue(queuetype *q)
{
	if (is_empty(q))
		error("ť�� �������");
		
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

int main()
{
	queuetype queue;
	int element;
	
	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue))
	{
		printf("������ �Է��ϼ���: ");
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
