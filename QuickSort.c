#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int Partition(int* list, int left, int right)
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
			temp = list[high];
			list[high] = list[low];
			list[low] = temp;
		}
	} while (low < high);

	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	return high;
}

void QuickSort(int* list, int left, int right)
{
	if (left < right)
	{
		int q = Partition(list, left, right);
		QuickSort(list, left, q - 1);
		QuickSort(list, q + 1, right);
	}
}

int main(void)
{
	int i;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand() % 100;
	}

	QuickSort(list, 0, MAX_SIZE - 1);
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}