//
//  0604.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/06/11.
//

#include "0604.hpp"


void QuickSort(int list[], int left, int right) {
    if (left < right) {
        int q = Partition(list, left, right);
        QuickSort(list, left, q - 1);
        QuickSort(list, q + 1, right);
    }
}

int Partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;
    
    low = left;
    high = right + 1;
    pivot = list[left];
    
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


void RadixSort(int list[], int n) {
    int factor = 1;
    int i;
    CircularQueType queues[BUCKETS];
    
    for (int b {0}; b < BUCKETS; b++) {
        C_InitQue(&queues[b]);
    }
    
    for (int d {0}; d < DIGITS; d++) {
        for (int i {0}; i < n; i++) {
            C_Enqueue(&queues[(list[i] / factor) % 10], list[i]);
        }
        
        i = 0;
        for (int b {0}; b < BUCKETS; b++) {
            while (!C_IsEmptyQue(&queues[b])) {
                list[i++] = C_Dequeue(&queues[b]);
            }
        }
        
        factor *= 10;
    }
}



void InitTable(elements ht[]) {
    for (int i {0}; i < TABLE; i++) {
        ht[i].keys[0] = NULL;
    }
}

int Transform(char * key) {
    int num = 0;
    while (*key) {
        num = 31 * num + *key++;
    }
    return num;
}

int HashFunc(char * key) {
    return Transform(key) % TABLE;
}

void HashAdd(elements item, elements ht[]) {
    int hash_value, i;
    hash_value = i = HashFunc(item.keys);

    
    while (!EmptyChar(ht[i])) {
        if (EqualChar(item, ht[i])) {
            exit(1);
        }
        
        i = (i + 1) % TABLE;
        if (i == hash_value) {
            exit(1);
        }
    }
    ht[i] = item;
}

void HashSearch(elements item, elements ht[]) {
    int hash_value, i;
    hash_value = i = HashFunc(item.keys);
    
    while (!EmptyChar(ht[i])) {
        if (EqualChar(item, ht[i])) {
            cout << "탐색 위치 " << item.keys << " = " << i << "\n";
            return;
        }
        
        i = (i + 1) % TABLE;
        if (i == hash_value) {
            cout << "찾는 값이 없음\n";
            return;
        }
    }
    cout << "찾는 값이 없음\n";
}

void HashPrint(elements ht[]) {
    cout << "-------------------------\n";
    for (int i {0}; i < TABLE; i++) {
        cout << i << " " << ht[i].keys << "\n";
    }
    cout << "-------------------------\n\n";
}

bool EqualChar(elements item1, elements item2) {
    return !strcmp(item1.keys, item2.keys);
}


bool EmptyChar(elements item) {
    return strlen(item.keys) == 0;
}
