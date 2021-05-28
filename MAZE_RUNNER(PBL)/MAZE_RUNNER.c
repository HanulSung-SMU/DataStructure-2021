#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택의 최대 크기
#define MAX_STACK_SIZE 100
// 미로의 가로, 세로 길이
#define MAZE_SIZE 8

typedef struct {
	short r; // 미로 위, 아래
	short c; // 미로 좌, 우
}Runner;

// 미로에서 갈 수 있는 영역을 담을 스택 선언
typedef struct {
	Runner data[MAZE_SIZE]; // 이동 가능 한 영역을 저장할 data 변수
	int top; // 스택 구성요소
}Stack;

// 스택 구성
void init_stack(Stack* s) {
	s->top = -1;
}

// 스택이 비어있는지 판단
int is_empty(Stack* s) {
	return (s->top == -1);
}

// 스택이 가득 차 있는지 판단
int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 스택에 새로운 데이터 추가(매개변수 : 생성된 스택, runner의 현재 위치)
void push(Stack* s, Runner data) {
	if (is_full(s)) {
		fprintf(stderr, "스택이 데이터로 꽉찼습니다.\n");
		return;
	}
	else
		s->data[++(s->top)] = data;
}

//
Runner pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택에 데이터가 없습니다.\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

// 미로 판 설정
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

// Runner의 위치를 스택에 삽입한다.
void push_loc(Stack* s, int r, int c) {
	// Runner의 위치가 r < 0 || c < 0일 경우 미로판 범위에 벗어나므로 오류
	if (r < 0 || c < 0) return;
	// Runner의 위치가 '.', '1'이 아닐 때
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		Runner tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

// 미로 출력
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
	// Runner의 위치를 넣어줄 스택 선언
	Stack s;

	// 스택 생성
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		// Runner가 지나간 곳은 '.'으로 바꿔준다.
		maze[r][c] = '.';
		maze_print(maze);
		// Runner의 좌, 우, 위, 아래를 넣어 Runner가 갈 수 있는 위치를 스택에 넣어줌
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		// 스택에 Runner가 갈 수 있는 공간이 더이상 없을 경우 실패
		if (is_empty(&s)) {
			fprintf(stderr, "실패\n");
			return;
		}
		else here = pop(&s);
	}
	// 그렇지 않을 경우 성공
	printf("성공\n");
	return 0;
}