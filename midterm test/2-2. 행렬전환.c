#include<stdio.h>
int** make_array(int x, int y) {
	int** p = (int**)malloc(sizeof(int) * x);
	for (int i = 0; i < x; i++)
		p[i] = (int*)malloc(sizeof(int) * y);
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			p[i][j] = j + 1 + i * x;
	return p;
}
void print_array(int** p, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			printf("%3d ", p[i][j]);
		printf("\n");
	}
}

void transpos(int** from, int** to, int row, int col) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			to[j][i] = from[i][j];
}

int main() {
	int row, col;
	int** p = NULL;
	int** p1 = NULL;
	printf("행과 열을 입력하세요(행과 열은 같아야 합니다).\n");
	scanf_s("%d %d", &row, &col);

	p = make_array(row, col);
	p1 = make_array(row, col);
	print_array(p, row, col);
	printf("\n");

	transpos(p, p1, row, col);
	print_array(p1, row, col);

	free(p);
	free(p1);
	return 0;
}