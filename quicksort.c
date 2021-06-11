#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20

void swap(int a, int b){
	int temp  = a;
	a = b;
	b = temp;
	
	return;
}

void array_print(int list[])
{
	int n = MAX_SIZE;
	for(int i = 0; i < n; i++){
		printf("%d ->", list[i]);
	}
	printf("\n");
	return;
}

int partition(int list[], int left, int right);

void quick_sort(int list[], int left, int right){
	if(left < right){
		int q = partition(list, left, right);
		quick_sort(list, left, q-1);
		quick_sort(list, q+1, right);
	}
}

int partition(int list[], int left, int right)
{
	int low, high, pivot, temp;
	low = left;
	high = right + 1;
	pivot = list[left];
	
	do{
		do
			low++;
		while(low<=right && list[low] < pivot);

		do
			high--;
		while(high>=left && list[high] > pivot);
		if(low < high)
			swap(list[low], list[high]);
	}while(low<high);

	swap(list[left], list[high]);

	return high;
}

int main(void){
	int list[MAX_SIZE];
	srand(time(NULL));
	for(int i = 0; i < MAX_SIZE; i++){
		list[i] = rand() % 100;
	}
	printf("정렬전\n");
	array_print(list);
	printf("정렬 후 \n");
	quick_sort(list, 0, MAX_SIZE -1);
	array_print(list);
	return 0;

}
