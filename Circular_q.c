#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

//원형큐 시작
typedef int element;
typedef struct {
    element data[MAX_SIZE];
    int head, tail;
} QueueType;

//오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//공백 상태 검출 함수
void init_queue(QueueType *q) {
    q->head = q->tail = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q) {
    return (q->head == q->tail);
}

//포화 상태 검출 함수
int is_full(QueueType *q) {
    return ((q->tail + 1) % MAX_SIZE == q->head);
}

//원형큐 출력 함수
void queue_print(QueueType *q) {
    printf("QUEUE(head = %d tail = %d) = ", q->head, q->tail);
    if(!is_empty(q)) {
        int i = q->head;
        do {
            i = (i + 1) % (MAX_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->tail)
                break;
        }while (i != q->head);
    }
    printf("\n");
}

//삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->data[q->tail] = item;
}

//삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->head = (q->head + 1) % MAX_SIZE;
    return q->data[q->head];
}

//삭제 함수
element peek(QueueType *q) {
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->head + 1) % MAX_SIZE];
}

//메인 함수
int main(void) {
    QueueType queue;
    int element;
    
    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue)) {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다.\n\n");
    
    printf("--데이터 삭제 단계--\n");
    while (!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("꺼내진 정수: %d\n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}

