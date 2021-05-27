#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x ,y ,t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for(i=1 ; i<n ; i++) {
        key = list[i];
        for(j=i-1 ; j>=0 && list[j]>key ; j--)
            list[j+1] = list[j];
        list[j+1] = key;
    }
}

int main(void)
{
    int i, j;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0 ; i<n; i++) {
            list[i] = rand() % 100;
	    for(j=0 ; j<i ; i++) {
		    if(list[j] == list[j])
			    i--;
	    }
    }
    insertion_sort(list, n);
    for(i=0 ; i<n ; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}