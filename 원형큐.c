#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

//오류 출력 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType* q)
{
    q->rear = 0;
    q->front = 0;
}

//원형큐 출력함수
void queue_print(QueueType* q)
{
    printf("QUEUE(front=%d rear%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

int is_full(QueueType* q) 
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType* q) 
{
    return(q->front == q->rear);
}
void enqueue(QueueType* q, int item) {
    if (is_full(q))
        error("큐가 포화상태이다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐rk 공백상태이다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태이다.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType q;
    int element;
    init_queue(&q);
    while (is_full(&q) == 0)
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&q, element);
        queue_print(&q);
    }
    printf("큐 포화\n\n");
    printf("데이터 삭제 단계 \n");
    while (is_empty(&q) == 0)
    {
        element = dequeue(&q);
        printf("꺼내진 정수 : %d \n", element);
        queue_print(&q);
    }
    printf("큐 공백\n");
    return 0;
}