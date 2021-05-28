#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ �ִ� ũ��
#define MAX_STACK_SIZE 100
// �̷��� ����, ���� ����
#define MAZE_SIZE 8

typedef struct {
	short r; // �̷� ��, �Ʒ�
	short c; // �̷� ��, ��
}Runner;

// �̷ο��� �� �� �ִ� ������ ���� ���� ����
typedef struct {
	Runner data[MAZE_SIZE]; // �̵� ���� �� ������ ������ data ����
	int top; // ���� �������
}Stack;

// ���� ����
void init_stack(Stack* s) {
	s->top = -1;
}

// ������ ����ִ��� �Ǵ�
int is_empty(Stack* s) {
	return (s->top == -1);
}

// ������ ���� �� �ִ��� �Ǵ�
int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���ÿ� ���ο� ������ �߰�(�Ű����� : ������ ����, runner�� ���� ��ġ)
void push(Stack* s, Runner data) {
	if (is_full(s)) {
		fprintf(stderr, "������ �����ͷ� ��á���ϴ�.\n");
		return;
	}
	else
		s->data[++(s->top)] = data;
}

//
Runner pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���ÿ� �����Ͱ� �����ϴ�.\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

// �̷� �� ����
Runner here = { 1, 0 }, entry = { 1, 0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1', '1', '1'},
	{'e', '0', '0', '0', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '1', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '1', '1', '0', '0', '0'},
	{'1', '0', '1', '1', '1', '1', '1', 'x'},
	{'1', '0', '0', '1', '1', '1', '1', '1'}
};

// Runner�� ��ġ�� ���ÿ� �����Ѵ�.
void push_loc(Stack* s, int r, int c) {
	// Runner�� ��ġ�� r < 0 || c < 0�� ��� �̷��� ������ ����Ƿ� ����
	if (r < 0 || c < 0) return;
	// Runner�� ��ġ�� '.', '1'�� �ƴ� ��
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		Runner tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

// �̷� ���
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%2c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void) {
	int r, c;
	// Runner�� ��ġ�� �־��� ���� ����
	Stack s;

	// ���� ����
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		// Runner�� ������ ���� '.'���� �ٲ��ش�.
		maze[r][c] = '.';
		maze_print(maze);
		// Runner�� ��, ��, ��, �Ʒ��� �־� Runner�� �� �� �ִ� ��ġ�� ���ÿ� �־���
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		// ���ÿ� Runner�� �� �� �ִ� ������ ���̻� ���� ��� ����
		if (is_empty(&s)) {
			fprintf(stderr, "����\n");
			return;
		}
		else here = pop(&s);
	}
	// �׷��� ���� ��� ����
	printf("����\n");
	return 0;
}