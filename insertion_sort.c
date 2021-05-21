#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void insertion(int list[], int n)
{
    int i, j, key;
    for (i = 0; i < n; i++) {
        key = list[i];
        for (j = i-1; j >= 0 && list[j]>key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
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
    
    insertion(list, n);
    for (i = 0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
