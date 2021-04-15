// 원형 큐 코드
#include <stdio.h> 
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;							// element = int
typedef struct {				
	element data[MAX_QUEUE_SIZE];				// Queue's storage
	int front, rear;							// front : queue's start part, rear : queue;s end part
} QueueType;

// error message method
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Reser Queue's data
void init_queue(QueueType* q) {
	// 선형 큐와 다른 점
	q->front = 0;
	q->rear = 0;
}

// Check if queue is empty(front value == rear value -> queue is empty)
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// Check if queue is full(front value == (rear value) % MAX_QUEUE_SIZE + 1 -> queue is full)
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);							// q->rear + 1 : empty, full을 구분하기 위해서 1자리 비워둔다. -> 선형 큐와 다른 점
}

// print queue's data
void queue_print(QueueType* q) {
	printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);						// while문의 조건이 처음부터 성립하지않으므로 do-while 사용
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");

	return 0;
}
