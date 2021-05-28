#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t)((t)=(x),(x)=(y), (y)=(t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE];

// 선택정렬
void selection_sort(int list[], int n)
{   int i, j, least, temp;
    for(i=0; i<n-1; i++) {
    least = i;
        for(j=i+1; j<n; j++)
            if(list[j]<list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}

// 삽입정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

// 버블정렬
void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++)
            if (list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}
void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL)); // 난수 생성

    for (i = 0; i < n; i++)
        list[i] = rand() % 100; // 난수 범위 0~99

    selection_sort(list, n); // 선택정렬
    printf("--- 선택정렬 ---\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n\n");

    insertion_sort(list, n); // 삽입정렬
    printf("--- 삽입정렬 ---\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n\n");

    bubble_sort(list, n); // 버블정렬
    printf("--- 버블정렬 ---\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n\n");

    merge_sort(list, 0, n-1); // 버블정렬
    printf("--- 합병정렬 ---\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n\n");


    return 0;
}