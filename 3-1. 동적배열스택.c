#include<stdio.h>
typedef struct {						//스택에 대한 데이터 타입 설정
	int* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {			// top을 -1로, capacity를 10으로 하고 데이타를 array형식으로 저장하기 위해 동적할당
	s->top = -1;
	s->capacity = 10;
	s->data = (int*)calloc(sizeof(int), (s->capacity));
}

int is_empty(StackType* s) {			// 스택이 비었는지 top과 값 비교를 통해 확인
	return s->top == -1;
}

int is_full(StackType* s) {				// 스택이 꽉 차있는지 top과 capacity를 비교
	return s->top == s->capacity - 1;
}

void push(StackType* s, int val) {
	if (is_full(s)) {				    // 스택이 꽉 차있다면 용량을 2배로 늘림
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = val;		// 데이타를 array형식으로 저장(활용은 스택처럼), index는 top
}

int pop(StackType* s) {					// 스택이 비어있지 않다면 스택 가장 위에 있는 값을 제거하고 그 값을 반환
	if (is_empty(s))
		printf("no data\n");
	else {
		if (s->data[s->top] % 10 == 0)	// 값을 한줄에 10개씩 출력하기 위함
			printf("\n");
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) {				// 스택이 비어있지 않다면 스택 가장 위에 있는 값을 반환
	if (is_empty(s))
		printf("no data\n");
	else
		return s->data[(s->top)];
}

void endfile(StackType* s) {			// 동적할당 메모리 해제(데이터에 관한 동적할당, 스택에 대한 동적할당)
	free(s->data);
	free(s);
}

int main() {
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int n;

	printf("어떤 수까지 스택에 입력할까요?\n");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)			// n까지의 수를 스택에 push
		push(s, i);

	for (; !is_empty(s); )				// 스택이 빌때까지 pop후 값 출력
		printf("%d ", pop(s));

	endfile(s);							// 동적할당 해제
	return 0;
}