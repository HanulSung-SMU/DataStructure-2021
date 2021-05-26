#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int sorted[MAX_SIZE];   // �߰� ������ �ʿ�
int list[MAX_SIZE];
int n;
/* i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
		j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
		k�� ���ĵ� ����Ʈ�� ���� �ε��� */
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i>mid)	/* ���� �ִ� ���ڵ��� �ϰ� ���� */
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else	/* ���� �ִ� ���ڵ��� �ϰ� ���� */
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	/* �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹�� */
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
	
	printf("�պ� ���� ��: "); 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	merge_sort(list, 0, n - 1); 
	
	printf("�պ� ���� ��: ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	return 0;
}
