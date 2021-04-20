#include<stdio.h>
void hanoi_tower(int n, int start, int tmp, int end) {
	if (n == 1)
		printf("%d번째 원반이 %c에서 %c로 움직인다.\n", n, start, end);
	else {
		hanoi_tower(n - 1, start, end, tmp);
		printf("%d번쨰 원반이 %c에서 %c로 움직인다.\n", n, start, end);
		hanoi_tower(n - 1, tmp, start, end);
	}
}

int main() {
	char a = 'A', b = 'B', c = 'C';
	int num;
	printf("하노이타워 층을 입력하십시오.\n");
	scanf_s("%d", &num);
	hanoi_tower(num, a, b, c);
}