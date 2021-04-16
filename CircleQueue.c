/*
* 201710815 황선웅
* 6주차 원형큐 구현
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
} Queue;

void init_Queue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

int is_full(Queue* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(Queue* q, element n)
{
	if (is_full(q))
	{
		fprintf(stderr, "큐 포화 상태\n");
		exit(1);
	}
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = n;
	}
}

element dequeue(Queue* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "큐 공백 상태\n");
		exit(1);
	}
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void print_Queue(Queue* q)
{
	int i;
	printf("Queue(front : %d, rear : %d) : ", q->front, q->rear);
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
	Queue q;
	int choice;
	int num;

	init_Queue(&q);

	while (1)
	{
		printf("1.삽입  2.삭제 (종료는 0) : ");
		scanf_s("%d", &choice);
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			if (is_full(&q))
			{
				printf("큐 포화 상태입니다.\n");
			}
			else
			{
				printf("큐에 삽입할 값을 입력하세요 : ");
				scanf_s("%d", &num);
				enqueue(&q, num);
				print_Queue(&q);
			}
			break;
		case 2:
			if (is_empty(&q))
			{
				printf("큐 공백 상태 입니다.\n");
			}
			else
			{
				printf("큐에서 하나의 값을 삭제합니다.\n");
				num = dequeue(&q);
				printf("삭제한 값 : %d\n", num);
				print_Queue(&q);
			}
			break;
		}
	}

	return 0;
}