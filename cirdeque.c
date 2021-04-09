#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 6

typedef int ele;
typedef struct {
    int head, tail;
    ele data[MAX_DEQUE_SIZE];
} Dequetype;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(Dequetype *q)
{
    q->head = q->tail = 0;
}

int is_empty(Dequetype *q)
{
    return (q->head == q->tail);
}

int is_full(Dequetype *q)
{
    return ((q->tail + 1) % MAX_DEQUE_SIZE == q->head);
}

void deque_print(Dequetype *q)
{
    printf("Deque(head=%d tail=%d) = ", q->head, q->tail);
    if (!is_empty(q)) {
        int i = q->head;
        do {
            i = (i + 1) % (MAX_DEQUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->tail)
                break;
        } while (i != q->head);
    }
    putchar('\n');
}

void add_tail(Dequetype *q, ele item)
{
    if (is_full(q))
        error("Deque is full");
    q->tail = (q->tail + 1) % MAX_DEQUE_SIZE;
    q->data[q->tail] = item;
}

void delete_head(Dequetype *q)
{
    if (is_empty(q))
        error("Queue is empty");
    q->head = (q->head + 1) % MAX_DEQUE_SIZE;
}

void add_head(Dequetype *q, ele item)
{
    if (is_full(q))
        error("Deque is full");
    q->data[q->head] = item;
    q->head = (q->head - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

void delete_tail(Dequetype *q)
{
    if (is_empty(q))
        error("Queue is empty");
    q->tail = (q->tail - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

int main(void)
{
    Dequetype q;
    
    init_deque(&q);
    for (int i = 0; i < 4; i++) {
        add_head(&q, i);
        deque_print(&q);
    }
    for (int i = 0; i < 5; i++) {
        delete_tail(&q);
        deque_print(&q);
    }
    return 0;
}
