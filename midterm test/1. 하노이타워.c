#include<stdio.h>
void hanoi_tower(int n, int start, int tmp, int end) {
	if (n == 1)
		printf("%d��° ������ %c���� %c�� �����δ�.\n", n, start, end);
	else {
		hanoi_tower(n - 1, start, end, tmp);
		printf("%d���� ������ %c���� %c�� �����δ�.\n", n, start, end);
		hanoi_tower(n - 1, tmp, start, end);
	}
}

int main() {
	char a = 'A', b = 'B', c = 'C';
	int num;
	printf("�ϳ���Ÿ�� ���� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &num);
	hanoi_tower(num, a, b, c);
}