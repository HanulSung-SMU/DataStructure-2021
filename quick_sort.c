#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

# define MAX_SIZE 10
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )


int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값), left대신 MAX_SIZE-1도 가능함

    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot);

        do {
            high--;
        } while (high >= left && list[high] > pivot);

        if (low < high) {
            SWAP(list[low], list[high], temp);
        }
    } while (low < high);
    SWAP(list[left], list[high], temp);

    return high;
}

// 퀵정렬
void quick_sort(int list[], int left, int right) {

    if (left < right) {
        int q = partition(list, left, right); // q: pivot의 위치

        // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }

}

void main() {
    int i;
    int list[MAX_SIZE];
    int n = MAX_SIZE;


    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    quick_sort(list, 0, n - 1);

    printf("\n\n\n");
    for (i = 0; i < n; i++) {
        printf("[%d] ", list[i]);
    }
    printf("\n\n\n");
}