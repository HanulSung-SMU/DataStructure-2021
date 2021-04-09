#include stdio.h
#include stdlib.h
#define MAX 10
typedef struct
{
  int head;
  int tail;
  int data[MAX];
} DequeType;

void error(char message)
{
  fprintf(stderr, %sn, message);
  exit(1);
}

void init_deque(DequeType d)
{
  d-tail = -1;
  d-head = -1;
}

int is_full(DequeType d)
{
  if(d-tail == MAX - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_empty(DequeType d)
{
  if(d-head == d-tail)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void print_deque(DequeType d)
{
  for(int i = 0; i  MAX; i++)
  {
    if((d-data[i] == 0)  (i = d-head)  (i  d-tail))
    {
      printf( , );
    }
    else
    {
      printf(%d, , d-data[i]);
    }
  }
  printf(n);
  return;
}

void add_head(DequeType d, int item)
{
  if(is_full(d))
  {
    error(full error);
    return;
  }
  else
  {
    for(int i = MAX; i  0; i--)
    {
      d-data[i] = d-data[i - 1];
    }
    d-data[0] = item;
    d-tail++;
    print_deque(d);
  }
}

void add_tail(DequeType d, int item)
{
  if(is_full(d))
  {
    error(full error);
    return;
  }
  else
  {
    d-data[++d-tail] = item;
    print_deque(d);
  }
}

void delete_head(DequeType d)
{
  if(is_empty(d))
  {
    error(empty error);
    return;
  }
  else
  {
    for(int i = 0; i  MAX - 1; i++)
    {
      d-data[i] = d-data[i + 1];
    }
    d-data[d-tail--] = 0;
    print_deque(d);
  }
}

void delete_tail(DequeType d)
{
  if(is_empty(d))
  {
    error(empty error);
    return;
  }
  else
  {
    d-data[d-tail--] = 0;
    print_deque(d);
  }
}

int main(void)
{
  DequeType d;
  init_deque(&d);

  add_tail(&d, 1);
  add_tail(&d, 2);
  add_tail(&d, 3);
  add_head(&d, 4);
  delete_tail(&d);
  delete_head(&d);
  add_tail(&d, 5);
  add_head(&d, 6);
}