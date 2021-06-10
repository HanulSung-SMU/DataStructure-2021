#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct
{ //큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

//오류함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화 함수
void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 4

void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++)
        init_queue(&queues[b]); //큐들의 초기화

    for (d = 0; d < DIGITS; d++)
    {
        for (i = 0; i < n; i++) //데이터들을 자리수에 따라 큐에 삽입
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        for (b = i = 0; b < BUCKETS; b++) //버킷에서 꺼내어 list로 합친다.
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10; //그 다음 자리수로 간다.
    }
}

#define SIZE 10

int main(void)
{
    int list[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) //난수 생성 및 출력
        list[i] = rand() % 100;

    radix_sort(list, SIZE); //기수정렬 호출
    for (int i = 0; i < SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}