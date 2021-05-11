#include<stdio.h>
#include<stdlib.h>

typedef int element; // element -> int�� ���� 
typedef struct {
	element* data; 
	int capacity; // ���� ������ ũ�� 
	int top; 
}StackType; // ����ü ���� 

void init_stack(StackType*s) // ���� �ʱ�ȭ �Լ� 
{
	s->capacity = 2;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{	
	return (s->top == s->capacity - 1);
}

void push(StackType* s, element item)
{
	if (is_full(s)) // ���� ������ á�ٸ� ũ�� �� �÷��ֱ� 
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		s->data[++(s->top)] = item;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}

int main(void)
{
	StackType* s;

	s = (StackType*)malloc(sizeof(StackType));  // ���� �޸� �Ҵ� --> ����ü ũ�� ���� �Ҵ�

	init_stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);
	push(s, 6);
	push(s, 7);

	//for (int j = 0; j < 8; j++)
	//{
	//	printf("%d\n", s->data[j]);
	//}

	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	free(s);

	return 0;
}