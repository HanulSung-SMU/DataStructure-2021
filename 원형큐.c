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
//초기화
void init_que(Que* q)
{
	q->front = 0;
	q->rear = 0;
}
//스택 포화 검사
int is_full(Que* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
//스택 공백 검사
int is_empty(Que* q)
{
	return (q->front == q->rear);
}

//큐 출력하는 함수
//원형큐 에서는 q.front가 q.rear보다 커지는 순간이 생기므로 두 가지 경우로 나누어 출력
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
//큐 맨뒤에 하나 집어넣는 함수
void enque(Que* q, int item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//큐 맨앞에서 하나 빼는 함수
int deque(Que* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->data[q->front]);
}
//큐 채웠다 비웠다 다시 채우기 반복
int main(void)
{
	Que queue;
	int element;

	init_que(&queue);
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	while(!is_empty(&queue))
	{
		element = deque(&queue);
		printf("꺼내진 정수 : %d\n", element);
		que_print(&queue);
	}
	printf("큐는 공백상태입니다.\n\n");

	while (!is_full(&queue))
	{
		printf("정수를 입력하시오:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	while (!is_empty(&queue))
	{
		element = deque(&queue);
		printf("꺼내진 정수 : %d\n", element);
		que_print(&queue);
	}
	printf("큐는 공백상태입니다.\n\n");

	while (!is_full(&queue))
	{
		printf("정수를 입력하시오:");
		scanf_s("%d", &element);
		enque(&queue, element);
		que_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");
	
	return 0;
	

	
	return 0;
}
