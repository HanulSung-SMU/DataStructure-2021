#include<stdio.h>
#include<stdlib.h>

typedef int element; // element -> int로 정의 
typedef struct {
	element* data; 
	int capacity; // 현재 데이터 크기 
	int top; 
}StackType; // 구조체 정의 

void init_stack(StackType*s) // 스택 초기화 함수 
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
	if (is_full(s)) // 만약 스택이 찼다면 크기 더 늘려주기 
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
		fprintf(stderr, "스택 공백 에러\n");
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

	s = (StackType*)malloc(sizeof(StackType));  // 동적 메모리 할당 --> 구조체 크기 동적 할당

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