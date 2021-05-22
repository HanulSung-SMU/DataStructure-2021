#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
int sorted[MAX_SIZE];

void arrayprint(int list[]){
	for(int i = 0; i<MAX_SIZE; i++){
		printf("%d -> ", list[i]);
	}
	printf("\n");
	printf("\n");
}

void selection_sort(int A[], int n){
	int least, temp, i, j;
	
	for(i = 0; i < n-1; i++){
		least = i;
		for( j = i+1; j < n; j++){
			if(A[j]<A[least])
				least = j;
		}
		if(i != least){
			temp = A[i];
			A[i] = A[least];
			A[least] = temp;
		}
	}
}

void bubble_sort(int A[], int n){
	int i, j, temp;
	for(i = n-1; i > 1; i--){
		for(j = 0; j < i; j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
void merge(int list[], int left, int mid, int right){
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	
	while(i <= mid && j <= right){
		if(list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if(i > mid){
		for(l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else{
		for(l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}
	for(l = left; l<=right; l++){
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right){
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

void insert_sort(int list[], int n){	
	int i, j, key;
	
	for(i = 1; i < n; i++){
		key = list[i];
		for(j = i - 1; j>=0 && list[j]>key; j--)
			list[j+1] = list[j];
		list[j+1] = key;
	}
}

void random_array(int list[])
{
	int i, ii;
	for(i = 0; i < MAX_SIZE; i++){
		list[i] = rand() % 50 + 1;
		for(ii = 0; ii < i; ii++){
			if(list[i] == list[ii]){
				i--;
				break;
			}
		}
	}
}
int main(void)
{
	srand(time(NULL));
	int list_1[MAX_SIZE], list_2[MAX_SIZE], list_3[MAX_SIZE], list_4[MAX_SIZE];
	
	random_array(list_1);
	random_array(list_2);
	random_array(list_3);
	random_array(list_4);

	printf("정렬 전\n");
	arrayprint(list_1);
	bubble_sort(list_1, MAX_SIZE);
	printf("버블 정렬 후\n");
	arrayprint(list_1);

	printf("정렬 전\n");
	arrayprint(list_2);
	selection_sort(list_2, MAX_SIZE);
	printf("선택 정렬 후 \n");
	arrayprint(list_2);	

	printf("정렬 전\n");
	arrayprint(list_3);
	merge_sort(list_3, 0, MAX_SIZE - 1);
	printf("합병 정렬 후\n");
	arrayprint(list_3);
	
	printf("정렬 전\n");
	arrayprint(list_4);
	insert_sort(list_4, MAX_SIZE);
	printf("삽입 정렬 후\n");
	arrayprint(list_4);
	return 0;
}
