#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define max_stack_size 1000

#define SIZE_easy 10
#define SIZE_middle 30
#define SIZE_high 50 // 난이도별 미로 크기
#define SIZE_max 100

char maze_array[SIZE_max][SIZE_max];
int start_row, start_col;


typedef struct
{
	int r;	// 행 
	int c;	// 열   
} element;

typedef struct
{
	element data[max_stack_size];
	int top;
} stacktype;

void init_stack(stacktype* s)	// 스택 초기화 함수  
{
	s->top = -1;
}

int is_empty(stacktype* s)	// 공백상태 검출 함수  
{
	return (s->top == -1);
}

int is_full(stacktype* s)	// 포화상태 검출 함수  
{
	return (s->top == (max_stack_size - 1));
}

void push(stacktype* s, element item)	// item을 삽입해주는 함수  
{

	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else
		s->data[++(s->top)] = item;
}

element pop(stacktype* s)	// 삭제 함수  
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(stacktype* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


element entry;	// 입구 위치  
element here;	// 현재 위치  


void push_loc(stacktype* s, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (maze_array[r][c] != '0' && maze_array[r][c] != 'x')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze_array[SIZE_max][SIZE_max], int SIZE_level)
{
	printf("\n");
	for (int r = 0; r < SIZE_level + 1; r++)
	{
		for (int c = 0; c < SIZE_level + 1; c++)
		{
			if (maze_array[r][c] == '0')
				printf("■");
			else if (maze_array[r][c] == 'x')
				printf("◎");
			else if (maze_array[r][c] == 'G')
				printf("★");
			else
				printf("  ");
		}
		printf("\n");
	}
}

char make_maze(int SIZE_level)
{
	int** map = (int**)malloc(sizeof(int*) * SIZE_level);
	for (int n = 0; n < SIZE_level + 1; ++n)
		map[n] = (int*)malloc(sizeof(int*) * SIZE_level);

	int** maze = (int**)malloc(sizeof(int*) * SIZE_level);
	for (int n = 0; n < SIZE_level + 1; ++n)
		maze[n] = (int*)malloc(sizeof(int*) * SIZE_level);

	int i, j, rotate;
	int col = 0, row = 0;

	for (i = 0; i < SIZE_level + 1; i++)
	{
		for (j = 0; j < SIZE_level + 1; j++)
		{
			map[i][j] = 0;
			maze[i][j] = 0;
			maze_array[i][j] = '0';
		}
	}

	srand(time(NULL));
	Sleep(100);
	int goal_col = SIZE_level;
	int goal_row = 1 + rand() % (SIZE_level - 3);

	map[start_row][start_col] = 1, map[start_row][start_col + 1] = 1;
	map[start_row + 1][start_col] = 1, map[start_row - 1][start_col] = 1;

	map[goal_row][goal_col - 1] = 1, map[goal_row][goal_col - 2] = 1;
	map[goal_row][goal_col - 3] = 1, map[goal_row - 1][goal_col - 2] = 1, map[goal_row + 1][goal_col - 2] = 1;



	for (i = 0; i < 100000; i++)
	{

		rotate = rand() % 4 + 1;
		if (rotate == 1)
		{
			if (row == 0)
				continue;
			if (map[row - 2][col] == 0)
			{
				row--; map[row][col] = 1;
				row--; map[row][col] = 1;
			}
			else
				row -= 2;
		}
		if (rotate == 2)
		{
			if (row == SIZE_level - 2)
				continue;
			if (map[row + 2][col] == 0)
			{
				row++; map[row][col] = 1;
				row++; map[row][col] = 1;
			}
			else
				row += 2;
		}
		if (rotate == 3)
		{
			if (col == 0)
				continue;
			if (map[row][col - 2] == 0)
			{
				col--; map[row][col] = 1;
				col--; map[row][col] = 1;
			}
			else
				col -= 2;
		}
		if (rotate == 4) {
			if (col == SIZE_level - 2)
				continue;
			if (map[row][col + 2] == 0) {
				col++; map[row][col] = 1;
				col++; map[row][col] = 1;
			}
			else {
				col += 2;
			}
		}

	}

	for (i = 0; i < SIZE_level; i++)
	{
		for (j = 0; j < SIZE_level; j++)
			maze[i + 1][j + 1] = map[i][j];
	}

	for (i = 0; i < SIZE_level + 1; i++)
	{
		for (j = 0; j < SIZE_level + 1; j++) {
			if (i - 1 == start_row && j == 0) // 출발지점
				maze_array[i][j] = 'S';
			else if (i - 1 == goal_row && j == goal_col) // 도착지점
				maze_array[i][j] = 'G';
			else if (maze[i][j] == 0)
				maze_array[i][j] = '0';
			else if (maze[i][j] == 1)
				maze_array[i][j] = '1';
			//printf("%c ", maze_array[i][j]); // char형으로 표현된 미로를 볼 수 있음
		}
		printf("\n");
	}

	for (i = 0; i < SIZE_level + 1; i++)
	{
		for (j = 0; j < SIZE_level + 1; j++)
		{
			//Sleep(50);
			if (i - 1 == start_row && j == 0) // 출발지점
				printf("◎");
			else if (i - 1 == goal_row && j == goal_col) // 도착지점
				printf("★");
			else if (maze[i][j] == 0)
				printf("■");      // 벽
			else if (maze[i][j] == 1)
				printf("  ");     // 길
		}
		printf("\n");
	}
	printf("\n\n");
	return maze_array;

	for (int n = 0; n < SIZE_level + 1; ++n)
		free(map[n]);
	free(map);

	for (int n = 0; n < SIZE_level + 1; ++n)
		free(maze[n]);
	free(maze);
}

int main(void)
{
	srand(time(NULL));
	int SIZE_level = SIZE_middle;
	start_col = 0;
	start_row = 1 + rand() % (SIZE_level - 3);
	element entry = { start_row + 1 ,start_col };
	element here = entry;

	int r, c;
	stacktype s;
	init_stack(&s);
	Sleep(100);

	make_maze(SIZE_level);

	// 미로찾기 부분
	while (maze_array[here.r][here.c] != 'G')
	{
		Sleep(50); // 함수실행 딜레이, 조절가능
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		maze_array[here.r][here.c] = 'x';
		maze_print(maze_array, SIZE_level);
		push_loc(&s, here.r - 1, here.c);	// 상 
		push_loc(&s, here.r + 1, here.c);	// 하 
		push_loc(&s, here.r, here.c - 1);	// 좌 
		push_loc(&s, here.r, here.c + 1);	// 우  

		if (is_empty(&s))
		{
			printf("길이 없음!!\n");
			return 0;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}