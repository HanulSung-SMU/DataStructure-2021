#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType *q)
{
    for(int i=0 ; i<MAX_QUEUE_SIZE ; i++)
    {
        if(i <= q->front || i > q->rear)
            printf("   | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

void enqueue(QueueType *q, int item)
{
    if(q->rear != MAX_QUEUE_SIZE-1)
        q->data[++(q->rear)]=item;
    else
    {
        error("큐가 포화상태입니다.");
        return;
    }
}

void dequeue(QueueType *q)
{
    if(q->rear != q->front || (q->rear==MAX_QUEUE_SIZE-1 && q->front==MAX_QUEUE_SIZE-1))
    {
        for(int i=1; i<=q->rear ; i++)
            q->data[i-1] = q->data[i];
    (q->rear)--;
    return;
    }

    else
        error("큐가 공백상태입니다.");
        return;
}

int main(void)
{
    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    enqueue(&q, 40); queue_print(&q);
    enqueue(&q, 50); queue_print(&q);

    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    
    enqueue(&q, 60); queue_print(&q);
    
    return 0;
}
