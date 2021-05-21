#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

//버블정렬
void bubble_sort(int list[], int n)
{
    int i, j, temp;

    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++) //앞 뒤의 레코드를 비교한 후 교체
            if (list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}

int main(void)
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
    bubble_sort(list, n);
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}