// 선형 큐 코드
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;							// Queue's first elemenet's index
	int rear;							// Queue's last element's index
	element data[MAX_QUEUE_SIZE];		// new data's storage
} QueueType;

// Error method
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Reset method
void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

// print queue method
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("    |");
		else
			printf(" %d |", q->data[i]);
	}
	printf("\n");
}

// Check if Queue's data is full
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

// Check if Queue's data is empty
int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

// Insert new data in Queue
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

// Delete data in Queue
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}


// main method
int main(void) {
	int item = 0;		// Put data that Dequeue in item variable
	QueueType q;

	init_queue(&q);		// Reset Queue

	// Insert new data & print Queue
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);


	// Delete data in Queue & put it in item.va & print Queue
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);


	return 0;
}