#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
    int i, j, least, temp;
    for (i = 0; i < n-1; i++) {
        least = i;
        for (j = i+1; j < n; j++) {
            if (list[j] < list[least])
                least = j;
        }
        SWAP(list[i], list[least], temp);
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
    
    selection_sort(list, n);
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
