#include<stdio.h>
#define MAX 6
typedef struct {
	int head;
	int tail;
	int data[MAX];
}queue;
void init_queue(queue* q) {
	q->head = 0;
	q->tail = 0;
}
int is_empty(queue* q) {
	return q->head == q->tail;
}
int is_full(queue* q) {
	return q->head == (q->tail + 1) % MAX;
}
void enqueue(queue* q, int val) {
	if (is_full(q)) {
		printf("memory is full\n");
		exit(1);
	}
	else {
		q->tail = (q->tail+1) % MAX;	
		q->data[q->tail] = val;
	}
}
int dequeue(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else {
		q->head = (q->head + 1) % MAX;
		return q->data[q->head];
	}
}
void queue_print(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	for (int i = q->head; i != q->tail;) {
		i = (i + 1) % MAX;
		printf("%d ", q->data[i]);
	}
	printf("\n");
}
int main(void)
{
	queue q;
	init_queue(&q);
	for (int i = 0; i < 5; i++) 
		enqueue(&q, i + 1);
	queue_print(&q);
	for (int i = 0; i < 4; i++)
		dequeue(&q);

	for (int i = 0; i < 3; i++)
		enqueue(&q, i + 6);
	queue_print(&q);
	for (int i = 0; i < 4; i++) 
		dequeue(&q);
	return 0;
}
