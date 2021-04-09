#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int head, tail;
}DequeType;

//�����Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init_deque(DequeType* q) {
	q->head = q->tail = 0;
}

//���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->head == q->tail);
}

//��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return ((q->tail + 1) % MAX_SIZE == q->head);
}

//����ť ��� �Լ�
void deque_print(DequeType* q) {
	printf("DEQUE(head =%d rear = %d) =", q->head, q->tail);
	if (!is_empty(q)) {
		int i = q->head;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->tail) {
				break;
			}
		} while (i != q->head);
	}
	printf("\n");
}
//�����Լ�
void add_tail(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->tail = (q->tail + 1) % MAX_SIZE;
	q->data[q->tail] = item;
}

//�����Լ�
element delete_head(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->head = (q->head + 1) % MAX_SIZE;
	return q->data[q->head];
}

//�����Լ�
element get_head(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->head + 1) % MAX_SIZE];
}

void add_head(DequeType* q, element val) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->head] = val;
	q->head = (q->head - 1 + MAX_SIZE) % MAX_SIZE;
}

element delete_tail(DequeType* q) {
	int prev = q->tail;
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->tail = (q->tail - 1 + MAX_SIZE) % MAX_SIZE;
	return q->data[prev];
}

element get_tail(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->tail];
}
int main(void)
{
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_head(&queue, i);
		deque_print(&queue);
	}

	for (int i = 0; i < 3; i++) {
		delete_tail(&queue);
		deque_print(&queue);
	}
	return 0;
}