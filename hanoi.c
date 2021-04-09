#include <stdio.h>

void hanoi_tower(int, char, char, char);

int main(void)
{
	hanoi_tower(3, 'A', 'B', 'C');
	return 0;
}

void hanoi_tower(int n, char from, char temp, char to)
{
	if (n == 1) printf("���� 1�� %c ���� %c �� �ű��.\n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, temp);
		printf("���� %d�� %c ���� %c�� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}
// 201710815 Ȳ����