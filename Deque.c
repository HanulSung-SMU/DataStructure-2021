#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 5

#define true 1
#define false 0
#define error -1

typedef int element;

typedef struct {					//큐타입
	int front;
	int rear;
	element data[MAX_SIZE];

} Deque;


// 초기화함수
void init_deque(Deque* q)
{
	q->rear = 0;
	q->front = 0;
}

// 공백상태검사
int is_empty(Deque* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

// 포화상태검사
int is_full(Deque* q) {
	if (q->rear == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}

// 덱앞에 요소추가함수
void add_front(Deque* q, element data) {
	if (is_full(q)) {
		printf("큐가 포화상태입니다\n");
		return;
	}
	//printf("\nadd front %d \n\n",data);
	//printf("\n");
	q->data[q->front] = data;
	q->front = (q->front - 1 + MAX_SIZE)% MAX_SIZE;
	return;
}

// 덱뒤에 요소추가함수
void add_rear(Deque* q, element data) {
	if (is_full(q)) {
		printf("큐가 포화상태입니다\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = data;
}

//덱앞의 요소 반환
element get_front(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다\n");
		return q->data[q->rear];
	}
	return 0;
}

//덱뒤의 요소 반환
element get_rear(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다\n");
		return error;
	}
	return q->data[(q->rear - 1) % MAX_SIZE];
}

//덱앞의 요소 반환 후 삭제
element delete_front(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다\n");
		return error;
	}
	element tmp = get_front(q);
	q->front = (q->front + 1) % MAX_SIZE;
	return tmp;
}

//덱뒤의 요소 반환 후 삭제
element delete_rear(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다\n");
		return error;
	}
	element tmp = get_rear(q);
	//printf("\n delete rear %d \n\n",data);
	//printf("\n");
	q->rear = ((q->rear - 1) + MAX_SIZE) % MAX_SIZE;
	return q->data[q->rear];
}

void deque_print(Deque* q){
	printf("DEQUE(front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		}         
		while (i != q->front);
	}
	printf("\n");
}

int main() {
	Deque q;
	init_deque(&q);

	for (int i = 0; i < 3; i++) {
		add_front(&q, i);
		deque_print(&q);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&q);
		deque_print(&q);
	}
	return 0;
}