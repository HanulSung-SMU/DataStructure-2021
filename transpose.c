#include<stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 3
//
//int main(void)
//{
//	int a[ROWS][COLS] = { {2, 3, 0}, {8, 9, 1}, {7, 0, 5} };
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	int b[ROWS][COLS];
//
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			b[i][j] = a[j][i];
//			printf("%d ", b[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

// 동적할당 활용

int main(void)
{
	
	int** m = malloc(sizeof(int*) * ROWS);

	for (int i = 0; i < ROWS; i++)
	{
		m[i] =(int*)malloc(sizeof(int) * COLS);
	}

	int** result = malloc(sizeof(int*) * COLS);
	for (int i = 0; i < COLS; i++)
	{
		result[i] = (int*)malloc(sizeof(int) * ROWS);
	}

	printf("행렬입력\n");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			scanf_s("%d", &m[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			result[i][j] = m[j][i];
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < COLS; i++)
	{
		free(result[i]);
	}
	free(result);

	for (int i = 0; i < ROWS; i++)
	{
		free(m[i]);
	}
	free(m);

	return 0;
}