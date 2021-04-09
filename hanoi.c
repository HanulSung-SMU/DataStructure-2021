#include <stdio.h>

void hanoi_tower(int, char, char, char);

int main(void)
{
	hanoi_tower(3, 'A', 'B', 'C');
	return 0;
}

void hanoi_tower(int n, char from, char temp, char to)
{
	if (n == 1) printf("원판 1을 %c 에서 %c 로 옮긴다.\n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, temp);
		printf("원판 %d을 %c 에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}
// 201710815 황선웅