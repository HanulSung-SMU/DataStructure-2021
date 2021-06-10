#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100
#define SIZE 10
#define BUCKETS 10
#define DIGITS 4

typedef int element;
typedef struct { // 큐 타입
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType *q)
{
    q->rear = q->front = 0;
}


int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q)) 
        error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(QueueType *q)
{
    if (is_empty(q)) 
        error("큐가 공백상태입니다.");
    q->rear = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++)
        init(&queues[b]); // 큐들의 초기화

    for (d = 0; d < DIGITS; d++) {
        for (i = 0; i < n; i++) // 데이터들을 자리수에 따라 큐에 입력
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        for (b = i = 0; b < BUCKETS; b++) // 버켓에서 꺼내어 list로 합친다.
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10; // 그 다음 자리수로 간다.
    }
}

int main(void)
{
    int list[SIZE];
    int sub_i;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) { // 난수 생성 및 출력
        list[i] = rand() % 100;
        for (sub_i = 0; sub_i < i; sub_i++) { // 중복된 난수 제거
            if (list[i] == list[sub_i]) {
                i--;
                break;
            }
        }
    }

    radix_sort(list, SIZE); // 기수정렬 호출
    for (int i = 0; i < SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
