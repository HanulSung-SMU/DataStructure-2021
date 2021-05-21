#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

//삽입정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; //레코드의 오른쪽 이동

        list[j + 1] = key;
    }
}

int main()
{
    int i;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("정렬 전 함수\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    printf("정렬 후 함수\n");
    insertion_sort(list, n);
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
