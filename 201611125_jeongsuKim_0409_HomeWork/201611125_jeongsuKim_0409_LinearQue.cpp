#include "0409_LinearQue.hpp"

void InitQue(LinearQueType * q) {
    q -> head = -1;
    q -> tail = -1;
}

void PrintQue(LinearQueType * q) {
    for (int i {0}; i < MAX_QUE_SIZE; i++) {
        if (i <= q -> head || i > q -> tail) {
            cout << " ||";
        } else {
            cout << q -> data[i] << "||";
        }
    }
    cout << "\n\n";
}

bool IsFullQue(LinearQueType * q) {
    if (q -> tail == MAX_QUE_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool IsEmptyQue(LinearQueType * q) {
    if (q -> tail == q -> head) {
        return true;
    } else {
        return false;
    }
}

void Enqueue(LinearQueType * q, int data) {
    if (IsFullQue(q)) {
        cout << "Que is FULL\n";
        return;
    } else {
        q -> data[++(q -> tail)] = data;
    }
    
}

int Dequeue(LinearQueType * q) {
    if (IsEmptyQue(q)) {
        cout << "Que is EMPTY\n";
        return 0;
    } else {
        return q -> data[++(q -> head)];
    }
}

int Peek(LinearQueType * q) {
    if (IsEmptyQue(q)) {
        cout << "Que is EMPTY\n";
        return 0;
    } else {
        return q -> data[(q -> head) + 1];
    }
}
