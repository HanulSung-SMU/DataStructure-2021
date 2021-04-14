#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

//���� ��� �Լ�
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
    q->rear = 0;
    q->front = 0;
}

//����ť ����Լ�
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
        error("ť�� ��ȭ�����̴�.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("ťrk ��������̴�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������̴�.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType q;
    int element;
    init_queue(&q);
    while (is_full(&q) == 0)
    {
        printf("������ �Է��Ͻÿ�: ");
        scanf("%d", &element);
        enqueue(&q, element);
        queue_print(&q);
    }
    printf("ť ��ȭ\n\n");
    printf("������ ���� �ܰ� \n");
    while (is_empty(&q) == 0)
    {
        element = dequeue(&q);
        printf("������ ���� : %d \n", element);
        queue_print(&q);
    }
    printf("ť ����\n");
    return 0;
}