#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct
{
  int head;
  int tail;
  int data[MAX];
} QueueType;

void error(char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void init_queue(QueueType *q)
{
  q->tail = -1;
  q->head = -1;
}

int is_full(QueueType *q)
{
  if(q->tail == MAX - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_empty(QueueType *q)
{
  if(q->head == q->tail)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void print_queue(QueueType *q)
{
  for(int i = 0; i < MAX; i++)
  {
    if((q->data[i] == 0) || (i <= q->head) || (i > q->tail))
    {
      printf(" , ");
    }
    else
    {
      printf("%d, ", q->data[i]);
    }
  }
  printf("\n");
  return;
}

void enqueue(QueueType *q, int item)
{
  if(is_full(q))
  {
    error("full error");
    return;
  }
  else
  {
    q->data[++q->tail] = item;
    print_queue(q);
  }
}

void dequeue(QueueType *q)
{
  if(is_empty(q))
  {
    error("empty error");
    return;
  }
  else
  {
    for(int i = 0; i < MAX - 1; i++)
    {
      q->data[i] = q->data[i + 1];
    }
    q->data[q->tail--] = 0;
    print_queue(q);
  }
}

int main(void)
{
  QueueType q;
  init_queue(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  dequeue(&q);
  dequeue(&q);
  enqueue(&q, 4);
  dequeue(&q);
  dequeue(&q);
  enqueue(&q, 5);
}