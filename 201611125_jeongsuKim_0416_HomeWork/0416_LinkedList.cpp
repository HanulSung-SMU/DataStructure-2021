//
//  04.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/04/16.
//

#include "0416_LinkedList.hpp"


void Init(ArrayListType * l) {
    l -> size = 0;
}


void Insert(ArrayListType * l, int pos, int item) {
    if (!IsFull(l) && pos >= 0 && pos <= l -> size) {
        for (int i {l -> size - 1}; i >= pos; i--) {
            l -> data[i + 1] = l -> data[i];
        }
        l -> data[pos] = item;
        l -> size++;
    }
}

void InsertLast(ArrayListType * l, int item) {
    if (!IsFull(l)) {
        l -> data[l -> size] = item;
        l -> size++;
    } else {
        cout << "용량 부족\n";
    }
}

void InsertFirst(ArrayListType * l, int item) {
    if (!IsFull(l)) {
        for (int i {l -> size - 1}; i >= 0; i--) {
            l -> data[i + 1] = l -> data[i];
        }
        l -> data[0] = item;
        l -> size++;
    } else {
        cout << "용량 부족\n";
    }
}

int Delete(ArrayListType * l, int pos) {
    int item {};
    if (!IsEmpty(l) && pos >= 0 && pos <= l -> size) {
        item = l -> data[pos];
        for (int i {pos}; i < l -> size - 1; i++) {
            l -> data[i] = l -> data [i + 1];
        }
        l -> size--;
        return item;
    } else {
        return -1;
    }
}

void Clear(ArrayListType * l) {
    if (!IsEmpty(l)) {
        for (int i {0}; i < l -> size; i++) {
            l -> data[i] = 0;
        }
    } else {
        cout << "empty\n";
    }
}

int GetEntry(ArrayListType * l, int pos) {
    if (!IsEmpty(l) && pos >= 0 && pos <= l -> size) {
        return l -> data[pos];
    } else {
        return -1;
    }
}

int GetLength(ArrayListType * l) {
    int lenght {};
    if (!IsEmpty(l)) {
        lenght = l -> size;
    }
    return lenght;
}

bool IsEmpty(ArrayListType * l) {
    if (l -> size == 0) {
        return true;
    } else {
        return false;
    }
}

bool IsFull(ArrayListType * l) {
    if (l -> size == MAX_LL_SIZE) {
        return true;
    } else {
        return false;
    }
}

void PrintList(ArrayListType * l) {
    for (int i {0}; i < l -> size; i++) {
        cout << l -> data[i] << " ";
    }
    cout << "\n";
}
