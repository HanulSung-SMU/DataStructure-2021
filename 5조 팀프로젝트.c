#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<CoreWindow.h>

#define MAX_SIZE 1000

typedef struct Pos {
	int x;
	int y;
}Pos;

typedef struct Stack {
	Pos data[MAX_SIZE];
	int top;
}Stack;

int* m_init(int size) {
	srand(time(NULL));
	if (size % 2 == 0)
		return;
	int msize = size;
	int** maze = malloc(sizeof(int*) * size);
	for (int l = 0; l < size; l++)
	{
		maze[l] = malloc(sizeof(int*) * size);
	}
	for (int y = 0; y < msize; y++)
	{
		for (int x = 0; x < msize; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				maze[y][x] = '1';
			else
				maze[y][x] = '0';
		}
	}
	for (int y = 0; y < msize; y++)
	{
		int count = 1;
		for (int x = 0; x < msize; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x == msize - 2 && y == msize - 2)
				continue;

			if (y == msize - 2)
			{
				maze[y][x + 1] = '0';
				continue;
			}

			if (x == msize - 2)
			{
				maze[y + 1][x] = '0';
				continue;
			}

			if (rand() % 2 == 0)
			{
				maze[y][x + 1] = '0';
				count++;
			}
			else
			{
				int random = rand() % count;
				maze[y + 1][x - random * 2] = '0';
				count = 1;
			}
		}
	}
	maze[1][0] = 's'; //출발점 지정
	maze[size - 2][size - 1] = 'e'; //출구 지정

	printmaze(maze);

	return maze;

}

void s_init(Stack* p)
{
	p->top = -1;
}

int isfull(Stack* p)
{
	if (p->top == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}
int isempty(Stack* p)
{
	if (p->top == -1)
		return 1;
	else
		return 0;
}
void push(Stack* p, Pos data)
{
	if (isfull(p) == 1)
	{
		printf("스택 포화\n");
		exit(1);
	}
	else
	{
		p->top++;
		p->data[p->top].x = data.x; //스택에 x좌표값 저장
		p->data[p->top].y = data.y; //스택에 y좌표값 저장
	}
}
Pos peek(Stack* p)
{
	if (isempty(p) == 1)
	{
		printf("스택 공백\n");
		exit(1);
	}
	return p->data[(p->top)];
}
Pos pop(Stack* p)
{
	if (isempty(p) == 1)
	{
		printf("스택 공백\n");
		exit(1);
	}
	return p->data[(p->top)--];
}
int findway(int** maze, Stack* s, int x, int y)
{
	if (x < 0 || y < 0 || x>25 || y>25) //미로 범위를 벗어나면
		return;

	//갈 수 있는 좌표를 모두 스택에 push로 넣어둔다.
	if ((maze[x][y] != '1') && (maze[x][y] != '.') && (maze[x][y] != '2')) // 1 :벽 / . : 이미 방문한 곳
	{
		Pos tmp;
		tmp.x = x;
		tmp.y = y;
		push(s, tmp); //스택 s에 갈 수 있는 좌표값 push
		return 1;
	}
	else
		return 0;
}
int maze_find(int** maze)
{
	Stack s;
	Pos position;
	int i, j, x, y;
	s_init(&s);


	// 시작점 탐색
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 25; j++)
		{
			if (maze[i][j] == 's')
			{
				position.x = i;
				position.y = j;
			}
		}
	}

	//미로 탐색
	while (maze[position.x][position.y] != 'e')
	{
		x = position.x;
		y = position.y;

		if (maze[x][y] != 's')
			maze[x][y] = '.'; //방문한 곳 . 으로 표시
		printmaze(maze);
		Sleep(10);
		system("cls");

		//탐색
		if (findway(maze, &s, x, y + 1) == 1);
		else if (findway(maze, &s, x + 1, y) == 1);
		else if (findway(maze, &s, x - 1, y) == 1);
		else if (findway(maze, &s, x, y - 1) == 1);

		//막다른길이면 돌아감
		if ((maze[position.x][position.y + 1] == '1' || maze[position.x][position.y + 1] == '.' || maze[position.x][position.y + 1] == '2') &&
			(maze[position.x + 1][position.y] == '1' || maze[position.x + 1][position.y] == '.' || maze[position.x + 1][position.y] == '2') &&
			(maze[position.x - 1][position.y] == '1' || maze[position.x - 1][position.y] == '.' || maze[position.x - 1][position.y] == '2') &&
			(maze[position.x][position.y - 1] == '1' || maze[position.x][position.y - 1] == '.' || maze[position.x][position.y - 1] == '2')) {
			maze[x][y] = '2';
			position = pop(&s);
			position = peek(&s);
		}

		else
			position = peek(&s);

		if (isempty(&s) == 1)
		{
			printf("실패\n");
			exit(1);
		}

	}

	printmaze(maze);
	printf("(%d,%d) 도착\n", position.x, position.y);
	printf("탐색 성공\n");

	return 0;

}

int printmaze(int** maze)
{
	for (int i = 0; i < 25; i++)
	{
		for (int k = 0; k < 25; k++)
		{
			if (maze[i][k] == '0')
				printf("  ");
			else if (maze[i][k] == '1')
				printf("■");
			else if (maze[i][k] == 's')
				printf("ⓢ");
			else if (maze[i][k] == '2')
				printf("  ");
			else if (maze[i][k] == 'e')
				printf("ⓔ");
			else
				printf("\033[1;33m★\033[0m");
		}
		printf("\n");
	}
}


int main(void)
{
	char q = '1';

	printf("===============================================================\n");
	printf("===============================================================\n\n\n\n\n");

			printf("\033[1;31m		   	   미\033[0m");
			printf("\033[1;32m로\033[0m");
			printf("\033[1;33m찾\033[0m");
			printf("\033[1;35m기\033[0m");
	
	printf("\n\n\n\n===============================================================\n");
	printf("===============================================================\n\n");
	printf("			25x25미로에서\n\n");
	printf(" 시작 점 (1,0)에서 도착 점(23,24)까지 길을 찾는 프로그램입니다.\n\n\n");
	printf("	        시작하려면 ");
	printf("\033[1;36mEnter\033[0m");
	printf("를 눌러주세요.");
	scanf_s("%c", &q);
	while (1)
		if (q == '\n')break;
	int* maze = m_init(25);
	maze_find(maze);
	return 0;
}