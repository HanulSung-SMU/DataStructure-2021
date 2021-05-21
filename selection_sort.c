#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i < n-1; i++) {
        least = i;
        for (j = i+1; j < n; j++)
            if (list[j] < list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}

int main(void)
{
    int i, sub_i;
    n = MAX_SIZE;
    srand((unsigned int)time(NULL));
    for (i = 0; i<n; i++) {
        list[i] = rand() % 100;
        for (sub_i = 0; sub_i < i; sub_i++) {
            if (list[i] == list[sub_i]) {
                i--;
                break;
            }
        }
    }
    
    selection(list, n);
    for (i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
