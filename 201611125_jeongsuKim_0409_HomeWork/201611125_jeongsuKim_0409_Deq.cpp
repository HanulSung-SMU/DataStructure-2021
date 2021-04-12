#include "0409_Deq.hpp"


void InitDeq(DeqType * q) {
    q -> head = 0;
    q -> tail = 0;
    
}

void PrintDeq(DeqType * q) {
    cout << "Head :: " << (q -> head) % MAX_DEQ_SIZE << " || Tail :: " << (q -> tail) % MAX_DEQ_SIZE << "\n";
    if (!IsEmptyDeq(q)) {
// 선형으로 출력
//        for (int i {0}; i < MAX_DEQ_SIZE; i++) {
//            if (i >= q -> head || i < q -> tail) {
//                cout << q -> data[i] << " || ";
//            } else {
//                cout << "0 || ";
//            }
//        }
// 비선형으로 출력
        cout << q -> data[0] << " | " << q -> data[1] << " | " << q -> data[2] << "\n";
        cout << q -> data[7] << " |   | " << q -> data[3] << "\n";
        cout << q -> data[6] << " | " << q -> data[5] << " | " << q -> data[4] << "\n";
    } else {
        cout << "Deque is EMPTY!!!\n";
    }
}


bool IsFullDeq(DeqType * q) {
    if (((q -> tail) + 1) % MAX_DEQ_SIZE == q -> head) {
        return true;
    } else {
        return false;
    }
}

bool IsEmptyDeq(DeqType * q) {
    if (q -> tail == q -> head) {
        return true;
    } else {
        return false;
    }
}


void PushFront(DeqType * q, int data) {
    if (IsFullDeq(q)) {
        cout << "Dec is FULL, Push FAIL!!\n";
    } else if (IsEmptyDeq(q)) {
        q -> tail++;
        q -> data[q -> head] = data;
    } else {
        if (q -> head < 1) {
            q -> head = MAX_DEQ_SIZE - 1;
        } else {
            q -> head--;
        }
        
        q -> data[q -> head] = data;
    }
}

void PushBack(DeqType * q, int data) {
    if (IsFullDeq(q)) {
        cout << "Dec is FULL, Push FAIL!!\n";
    } else if (IsEmptyDeq(q)) {
        q -> tail = ((q -> tail) + 1) % MAX_DEQ_SIZE;
        q -> data[q -> head] = data;
    } else {
        q -> data[q -> tail] = data;
        q -> tail = ((q -> tail) + 1) % MAX_DEQ_SIZE;
    }
}



int PopFront(DeqType * q) {
    if (IsEmptyDeq(q)) {
        cout << "Dec is EMPTY, POP FAIL!!\n";
        return 1;
    } else {
        int k = q -> head;
        int pop = q -> data[k];
        q -> head = ((q -> head) + 1) % MAX_DEQ_SIZE;
        q -> data[k] = 0;
        return pop;
    }
}

int PopBack(DeqType * q) {
    if (IsEmptyDeq(q)) {
        cout << "Dec is EMPTY, POP FAIL!!\n";
        return 1;
    } else {
        if (q -> tail < 1) {
            q -> tail = MAX_DEQ_SIZE - 1;
        } else {
            q -> tail--;
        }
        int pop = q -> data[q -> tail];
        q -> data[q -> tail] = 0;
        
        return pop;
    }
}



int PeekFront(DeqType * q) {
    if (IsEmptyDeq(q)) {
        cout << "Dec is EMPTY, PEEK FAIL!!\n";
        return 0;
    } else {
        return q -> data[q -> head];
    }
}

int PeekBack(DeqType * q) {
    if (IsEmptyDeq(q)) {
        cout << "Dec is EMPTY, PEEK FAIL!!\n";
        return 0;
    } else {
        if (q -> tail < 1) {
            return q -> data[MAX_DEQ_SIZE - 1];
        } else {
            return q -> data[(q -> tail) - 1];
        }
    }
}
