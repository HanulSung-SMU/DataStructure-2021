#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}Que;
//에러 출력 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//큐 초기화
void init_que(Que* q)
{
	q->front = 0;
	q->rear = 0;
}
//공백 검사
int is_empty(Que* q)
{
	return (q->front == q->rear);
}
//포화 검사
int is_full(Que* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
//덱큐 출력 함수
void que_print(Que* q)
{
	printf("DEQUE(front=%d rear=%d) =", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;

			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
		printf("\n");
	}
}
//삽입 함수
void add_front(Que* q, int item)
{
	if (is_full(q))
		error("큐 포화상태");
	q->data[q->front] = item;
	q->front = (q->front -1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
//삽입 함수	
void add_rear(Que* q, int item)
{
	if (is_full(q))
		error("큐 포화상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//삭제 함수
int delete_front(Que* q)
{
	if (is_empty(q))
		error("큐 공백상태");
	q->front = (q->front +1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//삭제 함수
int delete_rear(Que* q)
{
	if (is_empty(q))
		error("큐 공백상태");
	int item = q->data[q->rear];
	q->rear = (q->rear -1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return item;
}

int main(void)
{
	Que queue;

	init_que(&queue);

	for (int i = 0; i < 4; i++)
	{
		add_front(&queue, i);
		que_print(&queue);
	}
	for (int i = 0; i < 3; i++)
	{
		delete_rear(&queue);
		que_print(&queue);
	}
	for (int i = 0; i < 3; i++)
	{
		add_front(&queue, i);
		que_print(&queue);
	}
	return 0;
}