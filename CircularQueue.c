#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;
void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}
void init_queue(QueueType *q)
{
    q->rear = 0;
    q->front = 0;
}
void queue_print(QueueType *q)
{
    for (int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i <= q->front || i > q->rear)
            printf("  | ");
        else
            printf("%d | ",q->data[i]);
    }
    printf("\n");
}
int is_full(QueueType *q) {
    if ((q->rear+1)%MAX_QUEUE_SIZE == q->front)
        return 1;
    else
        return 0;
}
int is_empty(QueueType *q) {

    if (q->front == q->rear) 
        return 1;

    else 
        return 0;
}
void enqueue(QueueType *q, int item) {
    if (is_full(q)==1) 
        error("큐 포화");
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}
int dequeue(QueueType *q) {
    if (is_empty(q)==1) 
        error("큐 공백");
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void)
{
    QueueType q;
    int element;
    init_queue(&q);
    while(is_full(&q)==0)
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&q,element);
        queue_print(&q);
    }
    printf("큐 포화\n\n");
    printf("데이터 삭제 단계 \n");
   while(is_empty(&q)==0)
   {
       element = dequeue(&q);
       printf("꺼내진 정수 : %d \n",element);
       queue_print(&q);
   }
   printf("큐 공백\n");
    return 0;
}
