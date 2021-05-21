#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE]; //추가 공간이 필요
int i;                //정렬된 왼쪽리스트에 대한 인덱스
int j;                //정렬된 오른쪽리스트에 대한 인덱스
int k;                //정렬될 리스트에 대한 인덱스

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    //분할 정렬된 list의 합병
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
        mid = (left + right) / 2;         //리스트의 균등분할
        merge_sort(list, left, mid);      //부분리스트의 정렬
        merge_sort(list, mid + 1, right); //부분리스트의 정렬
        merge(list, left, mid, right);    //합병
    }
}

int main()
{
    // int i;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("정렬 전 함수\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    printf("정렬 후 함수\n");
    merge_sort(list, 0, MAX_SIZE - 1);

    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
