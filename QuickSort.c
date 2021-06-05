#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10


int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do
	{
		do
		{
			low++;
		} while (low <= right && list[low] < pivot);

		do
		{
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high)
		{
			SWAP(list[low], list[high], temp);
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}


void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	int i, j;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
		
		for (j = 0; j < i; j++)
		{
			if (list[i] == list[j])
			{
				i--;
			}
		}
	}

	quick_sort(list, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}