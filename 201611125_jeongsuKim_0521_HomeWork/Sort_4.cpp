//
//  SelectionSort.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/27.
//

#include "Sort_4.hpp"


void SelectionSortFunc(int list[], int n) {
    int i, j;
    int least, temp;
    
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least]) {
                least = j;
            }
            
            temp = list[i];
            list[i] = list[least];
            list[least] = temp;
        }
    }
    
}


void InsertSortFunc(int list[], int n) {
    int temp, j;
    for (int i {0}; i < n; i++) {
        temp = list[i];
        for (j = i - 1; j >= 0 && list[j] > temp; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = temp;
    }
}


void BubbleSortFunc(int list[], int n) {
    int temp;
    for (int i {n - 1}; i > 0; i--) {
        for (int j {0}; j < i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int sort_list_merge[max_size];

void MergeFunc(int list[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int l;
    
    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            sort_list_merge[k++] = list[i++];
        } else {
            sort_list_merge[k++] = list[j++];
        }
    }
    
    if (i > mid) {
        for (l = j; l <= right; l++) {
            sort_list_merge[k++] = list[l];
        }
    } else {
        for (l = i; l <= mid; l++) {
            sort_list_merge[k++] = list[l];
        }
    }
    
    for (l = left; l <= right; l++) {
        list[l] = sort_list_merge[l];
    }
    
}


void MergeSortFunc(int list[], int left, int rigth) {
    int mid;
    if (left < rigth) {
        mid = (left + rigth) / 2;
        MergeSortFunc(list, left, mid);
        MergeSortFunc(list, mid + 1, rigth);
        MergeFunc(list, left, mid, rigth);
    }
    
}
