#include <stdio.h>

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1) // ������ ���ȣ���� ���� �ʵ��� ����� ���� ���� ���� 
	{
		printf("���� 1�� %c -> %c �� �ű��\n", from, to);
	}
	else
	{
		hanoi(n - 1, from, to, tmp); // from���� �������� to�� ����ؼ� tmp�� ����
		printf("���� %d�� %c -> %c �� �ű��\n",n, from, to); // ���� ū ���� �Ű��� 
		hanoi(n - 1, tmp, from, to); // �������� �ִ� ����(tmp�� �ִ� ����) to�� �ű�
	}
}
int main(void)
{
	hanoi(3, 'A', 'B', 'C');
	return 0;
}