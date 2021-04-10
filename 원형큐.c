#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}Que;
//���� ��� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//�ʱ�ȭ
void init_que(Que* q)
{
	q->front = 0;
	q->rear = 0;
}
//���� ��ȭ �˻�
int is_full(Que* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
//���� ���� �˻�
int is_empty(Que* q)
{
	return (q->front == q->rear);
}

//ť ����ϴ� �Լ�
//����ť ������ q.front�� q.rear���� Ŀ���� ������ ����Ƿ� �� ���� ���� ������ ���
void que_print(Que* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (q->front > q->rear)
		{
			if (i > q->rear && i <= q->front)
				printf("  |");
			else
				printf("%d|", q->data[i]);
		}
		else
		{
			if (i > q->rear || i <= q->front)
				printf("  |");
			else
				printf("%d|", q->data[i]);
		}
	}
	printf("\n");
}
//ť �ǵڿ� �ϳ� ����ִ� �Լ�
void enque(Que* q, int item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//ť �Ǿտ��� �ϳ� ���� �Լ�
int deque(Que* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->data[q->front]);
}
//ť ä���� ����� �ٽ� ä��� �ݺ�
int main(void)
{
	Que queue;
	int element;

	init_que(&queue);
	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ�:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	while(!is_empty(&queue))
	{
		element = deque(&queue);
		printf("������ ���� : %d\n", element);
		que_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n\n");

	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ�:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	while (!is_empty(&queue))
	{
		element = deque(&queue);
		printf("������ ���� : %d\n", element);
		que_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n\n");

	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ�:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	
	return 0;
	

	
	return 0;
}
