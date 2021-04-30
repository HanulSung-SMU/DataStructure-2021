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
	return q->head == (q->tail + 1) % MAX;
}

void add_head(queue* q, int val) {
	if (is_full(q)) {
		printf("memory is full\n");
		exit(1);
	}
	else {
		q->head -= 1;
		if (q->head < 0)
			q->head = MAX - 1;
		q->data[q->head] = val;
	}
}

void add_tail(queue* q, int val) {
	if (is_full(q)) {
		printf("memory is full\n");
		exit(1);
	}
	else {
		q->tail = (q->tail + 1) % MAX;
		q->data[q->tail] = val;
	}
}

void delete_head(queue* q) {

	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else 
		q->head = (q->head + 1) % MAX;
}

void delete_tail(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else {
		q->tail -= 1;
		if (q->tail < 0)
			q->tail = MAX - 1;
	}
}

int get_head(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else 
		return q->data[q->head];
}

int get_tail(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	else
		return q->data[q->tail];
}

void queue_print(queue* q) {
	if (is_empty(q)) {
		printf("memory is empty\n");
		exit(1);
	}
	for (int i = q->head; i != (q->tail + 1) % MAX;) {
		printf("%d ", q->data[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int main(void)
{
	queue q;
	init_queue(&q);
	add_head(&q, 5);
	add_tail(&q, 1);
	add_tail(&q, 2);
	add_head(&q, 4);
	queue_print(&q);

	delete_head(&q);
	delete_tail(&q);
	queue_print(&q);

	printf("%d \n", get_head(&q));
	printf("%d \n", get_tail(&q));

	return 0;
}
