#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int sorted[MAX_SIZE];

void SelectionSort(int* list)
{
	int i, j;
	int minIndex;
	int temp;

	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < MAX_SIZE; j++)
		{
			if (list[minIndex] > list[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}

void InsertionSort(int* list)
{
	int i, j, key;
	for (i = 1; i < MAX_SIZE; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

void BubbleSort(int* list)
{
	int i, j, temp;
	for (i = MAX_SIZE - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void Merge(int* list, int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void MergeSort(int* list, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid + 1, right);
		Merge(list, left, mid, right);
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

	SelectionSort(list);
	printf(">>> 선택정렬\n");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
	}

	InsertionSort(list);
	printf("\n>>> 삽입정렬\n");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
	}

	BubbleSort(list);
	printf("\n>>> 버블정렬\n");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
	}

	MergeSort(list, 0, MAX_SIZE - 1);
	printf("\n>>> 합병정렬\n");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}