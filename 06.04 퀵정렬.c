#include<stdio.h>
#define MAX 10
void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int list[], int left, int right) {
	int low = left, high = right + 1;
	int pivot = list[left];
	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);
		do {
			high--;
		} while (high >= left && list[high] > pivot);
		if (low < high) swap(&list[low], &list[high]);
	} while (low < high);

	swap(&list[left], &list[high]);

	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	int i;
	int n = MAX;
	int list[MAX];
	srand(time(NULL));

	for (i = 0; i < n; i++) 
		list[i] = rand() % 100;

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	quick_sort(list, 0, n - 1); 

	printf("~SORTED~\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}