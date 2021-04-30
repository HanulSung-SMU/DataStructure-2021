#include<stdio.h>
typedef struct {						
	int* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {			
	s->top = -1;
	s->capacity = 10;
	s->data = (int*)calloc(sizeof(int), (s->capacity));
}

int is_empty(StackType* s) {		
	return s->top == -1;
}

int is_full(StackType* s) {				
	return s->top == s->capacity - 1;
}

void push(StackType* s, int val) {
	if (is_full(s)) {				    
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = val;		
}

int pop(StackType* s) {					
	if (is_empty(s))
		printf("no data\n");
	else {
		if (s->data[s->top] % 10 == 0)	
			printf("\n");
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) {				
	if (is_empty(s))
		printf("no data\n");
	else
		return s->data[(s->top)];
}

void endfile(StackType* s) {			
	free(s->data);
	free(s);
}

int main() {
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int n;

	printf("어떤 수까지 스택에 입력할까요?\n");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)			
		push(s, i);

	for (; !is_empty(s); )				
		printf("%3d ", pop(s));
	printf("\n");

	pop(s);

	push(s, 1000);
	printf("%d", peek(s));

	endfile(s);							
	return 0;
}