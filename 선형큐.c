#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueType;
//����
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//ť �ʱ�ȭ
void init_queue(QueType* q)
{
	q->front = -1;
	q->rear = -1;
}
//ť ��� �Լ�
void queue_print(QueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
			printf("  |");
		else
			printf("%d|", q->data[i]);
	}
	printf("\n");
}
//��ȭ �˻�
int is_full(QueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
//���� �˻�
 int is_empty(QueType* q)
{
	if (q->rear == q->front)
		return 1;
	else
		return 0;
}
 //���� �Լ�
void enque(QueType* q, int item)
{
	if (is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�");
		return;
	}
	q->data[++(q->rear)] = item;
}
//���� �Լ�
int deque(QueType* q)
{
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�");
		return;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void)
{
	int item = 0;
	QueType q;

	init_queue(&q);

	enque(&q,10); queue_print(&q);
	enque(&q, 20); queue_print(&q);
	enque(&q, 30); queue_print(&q);

	item = deque(&q); queue_print(&q);
	item = deque(&q); queue_print(&q);
	item = deque(&q); queue_print(&q);

}