#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = list[i];

		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}

		list[j + 1] = key;
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

	insertion_sort(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}