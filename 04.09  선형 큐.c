#include<stdio.h>
#define MAX 5
typedef struct {
	int head;
	int tail;
	int data[MAX];
}queue;
void init_queue(queue* q) {
	q->head = -1;
	q->tail = -1;
}
int is_empty(queue* q) {
	return q->head == q->tail;
}
int is_full(queue* q) {
	return q->tail == MAX - 1;
}
void enqueue(queue* q, int val) {
	if (is_full(q)) {
		printf("memory is full\n");
		exit(1);
	}
	else
		q->data[++(q->tail)] = val;
}
int dequeue(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else
		return q->data[++(q->head)];
}
int peek(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else
		return q->data[(q->head) + 1];
}
void queue_print(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else {
		for (int i = q->head + 1; i <= q->tail; i++)
			printf("%d ", q->data[i]);
		printf("\n");
	}
}
int main(void)
{
	queue q;
	init_queue(&q);
	for (int i = 1; i <= 5; i++)
		enqueue(&q, i);
	queue_print(&q);
	for (int i = 0; i < 4; i++)
		dequeue(&q);
	printf("%d \n", peek(&q));
	return 0;
}
