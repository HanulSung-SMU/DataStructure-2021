#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define max_size 10
#define swap(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[max_size];
int n;

void bubble_sort (int list[], int n)
{
	int i, j, temp;
	for (i=n-1; i>0; i--)
	{
		for (j=0; j<i; j++)
			if (list[j]>list[j+1])
				swap(list[j], list[j+1], temp);
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
	bubble_sort(list, n);
	for (i=0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
			
