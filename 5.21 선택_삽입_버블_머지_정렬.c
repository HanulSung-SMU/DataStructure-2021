#include<stdio.h>
#define MAX 10
int sorted[MAX];
void selection_osrt(int list[MAX], int n) {
	int least, tmp;
	for (int i = 0; i < n; i++) {
		least = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[least])
				least = j;
		tmp = list[i];
		list[i] = list[least];
		list[least] = tmp;
	}
}

void insertion_sort(int list[MAX], int n) {
	int least, tmp, j;
	for (int i = 1; i < n; i++) {
		least = list[i];
		for (j = i - 1; j >= 0 && least < list[j]; j--)
			list[j + 1] = list[j];
		list[j + 1] = least;
	}
}

void bubble_sort(int list[MAX], int n) {
	int i, j, tmp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 
			if (list[j] > list[j + 1]) {
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
	}

}

void merge(int list[MAX], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[MAX], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		merge_sort(list, left, mid); 
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right); 
	}
}

int main(void){
	int i;
	int n = MAX;
	int list[MAX], list1[MAX], list2[MAX], list3[MAX];
	srand(time(NULL));
	for (i = 0; i < n; i++) { 
		list[i] = list1[i] = list2[i] = list3[i] = rand() % 100;
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("선택정렬\n");
	selection_osrt(list, n); 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("버블정렬\n");
	insertion_sort(list1, n);
	for (i = 0; i < n; i++)
		printf("%d ", list1[i]);
	printf("\n");

	printf("버블정렬\n");
	bubble_sort(list2, n);
	for (i = 0; i < n; i++)
		printf("%d ", list2[i]);
	printf("\n");

	printf("머지정렬\n");
	merge_sort(list3, 0, n-1);
	for (i = 0; i < n; i++)
		printf("%d ", list3[i]);
	printf("\n");

	return 0;
}
