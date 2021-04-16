#include <stdio.h> 
#include <stdlib.h>
#define MAX_SIZE 5

#define TRUE 1
#define FALSE 0
#define ERROR -1
typedef int element;
typedef int boolean;


typedef struct { // 큐 타입
	element data[MAX_SIZE];
	int front, rear;
} Queuetype;



/*        큐 초기화        */

void init_queue(Queuetype* q){
	q->front = q->rear = 0;
}



/*        공백 상태인지 여부        */

int is_empty(Queuetype* q) {
	if (q->front == q->rear) return TRUE;
	else return FALSE;
}

/*        포화 상태인지 여부        */

int is_full(Queuetype* q) {
	if (((q->rear + 1) % MAX_SIZE) == q->front) return TRUE;
	else return FALSE;
}

/*        큐에 데이터 삽입        */

void enqueue(Queuetype* q, element data) {

	if (is_full(q)) {
		printf("\n포화 큐\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % (MAX_SIZE);
		q->data[q->rear] = data;
	}
	return;
}

/*        큐 데이터 꺼내기        */

element dequeue(Queuetype* q) {
	if (is_empty(q)) {
		printf("큐는 공백 상태입니다.\n");
	}
	q->front = (q->front + 1) % (MAX_SIZE);
	return q->data[q->front];
}

/*        현재 큐 프린트        */

void queue_print(Queuetype* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


int main(void)
{
	Queuetype queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf_s("%d", &element);
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