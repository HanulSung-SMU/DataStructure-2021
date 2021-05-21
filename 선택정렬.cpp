#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define max_size 10
#define swap(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[max_size];
int n;

void selection_sort (int list[], int n)
{
	int i, j, least, temp;
	for (i=0; i<n-1; i++)
	{
		least = i;
		for (j=i+1; j<n; j++)
			if (list[j] < list[least]) least = j;
		swap (list[i], list[least], temp);
	}
}

int main ()
{
	int i, sub_i;
	n = max_size;
	srand (time(NULL));
		
	// 중복 제외 
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
	selection_sort(list, n);
	for (i=0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
			
