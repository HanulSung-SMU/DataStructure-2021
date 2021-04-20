#include<stdio.h>
typedef struct {						//���ÿ� ���� ������ Ÿ�� ����
	int* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {			// top�� -1��, capacity�� 10���� �ϰ� ����Ÿ�� array�������� �����ϱ� ���� �����Ҵ�
	s->top = -1;
	s->capacity = 10;
	s->data = (int*)calloc(sizeof(int), (s->capacity));
}

int is_empty(StackType* s) {			// ������ ������� top�� �� �񱳸� ���� Ȯ��
	return s->top == -1;
}

int is_full(StackType* s) {				// ������ �� ���ִ��� top�� capacity�� ��
	return s->top == s->capacity - 1;
}

void push(StackType* s, int val) {
	if (is_full(s)) {				    // ������ �� ���ִٸ� �뷮�� 2��� �ø�
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = val;		// ����Ÿ�� array�������� ����(Ȱ���� ����ó��), index�� top
}

int pop(StackType* s) {					// ������ ������� �ʴٸ� ���� ���� ���� �ִ� ���� �����ϰ� �� ���� ��ȯ
	if (is_empty(s))
		printf("no data\n");
	else {
		if (s->data[s->top] % 10 == 0)	// ���� ���ٿ� 10���� ����ϱ� ����
			printf("\n");
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) {				// ������ ������� �ʴٸ� ���� ���� ���� �ִ� ���� ��ȯ
	if (is_empty(s))
		printf("no data\n");
	else
		return s->data[(s->top)];
}

void endfile(StackType* s) {			// �����Ҵ� �޸� ����(�����Ϳ� ���� �����Ҵ�, ���ÿ� ���� �����Ҵ�)
	free(s->data);
	free(s);
}

int main() {
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int n;

	printf("� ������ ���ÿ� �Է��ұ��?\n");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)			// n������ ���� ���ÿ� push
		push(s, i);

	for (; !is_empty(s); )				// ������ �������� pop�� �� ���
		printf("%d ", pop(s));

	endfile(s);							// �����Ҵ� ����
	return 0;
}