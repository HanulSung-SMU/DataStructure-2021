#include <stdio.h>

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1) // 무조건 재귀호출을 하지 않도록 만들기 위해 조건 생김 
	{
		printf("원판 1을 %c -> %c 로 옮긴다\n", from, to);
	}
	else
	{
		hanoi(n - 1, from, to, tmp); // from에서 경유지로 to를 사용해서 tmp로 보냄
		printf("원판 %d를 %c -> %c 로 옮긴다\n",n, from, to); // 가장 큰 원반 옮겨짐 
		hanoi(n - 1, tmp, from, to); // 경유지에 있던 것을(tmp에 있던 것을) to로 옮김
	}
}
int main(void)
{
	hanoi(3, 'A', 'B', 'C');
	return 0;
}