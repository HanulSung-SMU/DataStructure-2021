#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define max_size 10
#define swap(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[max_size];
int n;
int sorted[max_size];

void merge (int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid+1; k = left;
	
	while (i <=mid && j<=right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l<=right; l++)
			sorted[k++] = list[l];
	else
		for (l=i; l<=mid; l++)
			sorted[k++] = list[l];
	for (l=left; l<=right; l++)
		list[l] = sorted[l];
}

void merge_sort (int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right)/2;
		merge_sort (list, left, mid);
		merge_sort (list, mid+1, right);
		merge (list, left, mid, right);
	}
}

int main ()
{
	int i, sub_i;
	n = max_size;
	srand (time(NULL));
	
	// �ߺ� ����  
	for (i=0; i<max_size; i++) 
	{
		list[i] = rand() % 100; 
        for (sub_i = 0; sub_i < i; sub_i++) 
		{
            if (list[i] == list[sub_i]) 
			{
                i--;
                break;
            }
        }
    }
	merge_sort(list, 0, n-1);
	for (i=0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
			
