#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int sorted[MAX_SIZE];   // 추가 공간이 필요
int list[MAX_SIZE];
int n;
/* i는 정렬된 왼쪽 리스트에 대한 인덱스
		j는 정렬된 오른쪽 리스트에 대한 인덱스
		k는 정렬될 리스트에 대한 인덱스 */
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i>mid)	/* 남아 있는 레코드의 일괄 복사 */
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else	/* 남아 있는 레코드의 일괄 복사 */
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	/* 배열 sorted[]의 리스트를 배열 list[]로 재복사 */
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
//
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;     
		merge_sort(list, left, mid);    
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right);    
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	
		list[i] = rand() % 100; 
	
	printf("합병 정렬 전: "); 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	merge_sort(list, 0, n - 1); 
	
	printf("합병 정렬 후: ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	return 0;
}
