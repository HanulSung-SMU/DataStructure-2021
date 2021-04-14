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
		error("큐가 포화상태");
	
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[(q->rear)] = item;
}

int dequeue(queuetype *q)
{
	if (is_empty(q))
		error("큐가 공백상태");
		
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

int main()
{
	queuetype queue;
	int element;
	
	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하세요: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");
	
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
