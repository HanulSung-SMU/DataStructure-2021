#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
    int i, j ,key;
    for(i = 1; i < n; i++) {
        key = list[i];
        for (j = i-1; j >= 0 && list[j] > key; j--) {
            list[j+1] = list[j];
        }
        list[j + 1] = key;
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand((unsigned int)time(NULL));
    
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        for (int i_1 = 0; i_1 < i; i_1++) {
            if (list[i] == list[i_1]) {
                i--;
                break;
            }
        }
    }
    
    insertion_sort(list, n);
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
