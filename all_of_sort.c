#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int sorted[MAX_SIZE];
int list[MAX_SIZE];
int n;

//선택정렬
void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (int i = 0; i < n - 1; i++)
	{
		least = 1;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}
// 삽입정렬
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for(i=1; i<n; i++){
		key = list[i];
		for(j=i-1; j>=0 && list[j]>key; j--)
			list[j+1] = list[j]; // 레코드의 오른쪽 이동
		list[j+1] = key;
	}
}

void bubble_sort(int list[], int n){
	int i, j, temp;
	for (i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(list[j]>list[j+1])
				SWAP(list[j], list[j+1], temp);
		}
	}
}


void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i=left; j=mid+1; k=left;
	while(i<=mid && j<=right){
		if(list[i]<=list[j]) 
			sorted[k++] = list[i++];
		else 
			sorted[k++] = list[j++];
	}
	if(i>mid) 
		for(l=j; l<=right; l++)
			sorted[k++] = list[l];
	else 
		for(l=i; l<=mid; l++)
			sorted[k++] = list[l];
	for(l=left; l<=right; l++)
		list[l] = sorted[l];
}


void merge_sort(int list[], int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2; // 리스트의 균등분할
		merge_sort(list, left, mid); // 부분리스트 정렬
		merge_sort(list, mid+1, right);//부분리스트 정렬
		merge(list, left, mid, right); // 합병
	}
}

int main(void)
{
	int i;
	int k;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;
/*
	insertion_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
	
	selection_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;

	bubble_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
*/
	merge_sort(list, k, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
