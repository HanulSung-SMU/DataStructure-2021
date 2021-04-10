#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueType;
//에러
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//큐 초기화
void init_queue(QueType* q)
{
	q->front = -1;
	q->rear = -1;
}
//큐 출력 함수
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
//포화 검사
int is_full(QueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
//공백 검사
 int is_empty(QueType* q)
{
	if (q->rear == q->front)
		return 1;
	else
		return 0;
}
 //삽입 함수
void enque(QueType* q, int item)
{
	if (is_full(q))
	{
		error("큐가 포화상태입니다");
		return;
	}
	q->data[++(q->rear)] = item;
}
//삭제 함수
int deque(QueType* q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다");
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