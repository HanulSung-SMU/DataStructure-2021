#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
 
int list[MAX_SIZE];
int n;
 
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i>0; i--) {
		for (j = 0; j<i; j++)
			if (list[j]>list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	
		list[i] = rand() % 100; 
		
	printf("버블 정렬 전: "); 
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	bubble_sort(list, n); 
	
	printf("버블 정렬 후: ");
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	return 0;
}
