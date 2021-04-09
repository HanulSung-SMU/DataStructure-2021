#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int ele;
typedef struct {
    int head, tail;
    ele data[MAX_QUEUE_SIZE];
} Queuetype;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(Queuetype *q)
{
    q->head = q->tail = 0;
}

int is_empty(Queuetype *q)
{
    return (q->head == q->tail);
}

int is_full(Queuetype *q)
{
    return ((q->tail + 1) % MAX_QUEUE_SIZE == q->head);
}

void queue_print(Queuetype *q)
{
    printf("Queue(head=%d rear=%d) = ", q->head, q->tail);
    if (!is_empty(q)) {
        int i = q->head;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->tail)
                break;
        } while (i != q->head);
    }
    putchar('\n');
}

void enqueue(Queuetype *q, ele item)
{
    if (is_full(q))
        error("Queue is full");
    q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
    q->data[q->tail] = item;
}

int dequeue(Queuetype *q)
{
    if (is_empty(q))
        error("Queue is empty");
    q->head = (q->head + 1) % MAX_QUEUE_SIZE;
    return q->data[q->head];
}

int main(void)
{
    Queuetype q;
    int ele;
    
    init_queue(&q);
    printf("adding data...\n");
    while(!is_full(&q))
    {
        printf("Enter a integer: ");
        scanf("%d", &ele);
        enqueue(&q, ele);
        queue_print(&q);
    }
    printf("Queue is full.\n");
    
    printf("deleting data...\n");
    while(!is_empty(&q))
    {
        ele = dequeue(&q);
        printf("poped integer: %d \n", ele);
        queue_print(&q);
    }
    printf("Queue is empty.\n");
    return 0;
}
