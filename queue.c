#include <stdio.h> // c에서 기본적으로 쓰는 함수들을 사용하는데 필요한 헤더파일
#include <stdlib.h> // 문자열 변환, 사 난수 생성, 동적 메모리 관리 등의 함수들을 사용할때 필요한 헤더파일
#define MAX_QUEUE_SIZE 5 // 선형큐의 최대 사이즈를 5라고 둔다.
typedef int element; // 이제 int를 element라고 부른다.
typedef struct { // QueueType 이라는 이름의 구조체를 생성한다.
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE]; 
} QueueType;

void error(char* message) // 에러가 날때 
{
	fprintf(stderr, "%s\n", message); // fprintf(파일포인터, 서식, 값1, 값2, ...)
	exit(1);
}
void init_queue(QueueType* q) // 객체를 초기화 해준다.
{
	q->rear = -1; // 포인터가 입혀졌기 때문에 -> 이런식으로 접근해야한다.
	q->front = -1;
}
void queue_print(QueueType* q) // 선형큐를 프린트해주는 함수를 만들어준다.
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) // 만약에 프론트가 0보다크거나 같거나 i가 rear 보다 클때
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
int is_full(QueueType* q) // 선형큐가 꽉찼을 때 쓰는 함수를 만들어준다.
{
	if (q->rear == MAX_QUEUE_SIZE - 1) // rear가 4랑 같을때 
		return 1;
	else
		return 0;
}
int is_empty(QueueType* q) // 선형큐가 자리가 비었을 때 쓰는 함수를 만들어준다.
{
	if (q->front == q->rear) // front와 rear의 값이 같을때
		return 1;
	else
		return 0;
}
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) { // is_full함수의 값을 불러와준다.
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}
int dequeue(QueueType* q)
{
	if (is_empty(q)) { // is_empty함수의 값을 불러와준다.
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}
int main(void) // main함수를 만들어준다.
{
	int item = 0;
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}
