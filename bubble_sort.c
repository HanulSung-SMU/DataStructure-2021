#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10

void bubble_sort(int list[], int n)
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				SWAP(list[j], list[j + 1], temp);
			}
		}
	}
}
int main(void)
{
	int i, j, k;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	srand((unsigned)time(NULL));

	for (i = 0; i < n;)
	{
		list[i] = rand() % 100;

		for (j = 0, k = 0; j < i; j++)
		{
			if (list[i] == list[j])
			{
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			i += 1;
		}
	}

	bubble_sort(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}