#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int ele;
typedef struct {
    int head;
    int tail;
    ele data[MAX_QUEUE_SIZE];
} Queuetype;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(Queuetype *q)
{
    q->tail = -1;
    q->head = -1;
}

void queue_print(Queuetype *q)
{
    for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
        if (i <= q->head || i > q->tail)
            printf("   |");
        else
            printf("%3d|", q->data[i]);
    }
    putchar('\n');
}
int is_full(Queuetype *q)
{
    if (q->tail == MAX_QUEUE_SIZE -1)
        return 1;
    else
        return 0;
}

int is_empty(Queuetype *q)
{
    if (q->head == q->tail)
        return 1;
    else
        return 0;
}

void enqueue(Queuetype *q, int item)
{
    if(is_full(q)) {
        error("Queue is full");
        return;
    }
    q->data[++(q->tail)] = item;
}

int dequeue(Queuetype *q)
{
    if(is_empty(q)) {
        error("Queue is empty");
        return -1;
    }
    int item = q->data[++(q->head)];
    return item;
}

int main(void)
{
    int item = 0;
    Queuetype q;
    
    init_queue(&q);
    
    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    return 0;
}
