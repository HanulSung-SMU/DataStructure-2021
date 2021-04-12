#include "0409_CircularQue.hpp"

void C_InitQue(CircularQueType * q) {
    q -> head = 0;
    q -> tail = 0;
}

void C_PrintQue(CircularQueType * q) {
    cout << "Que head :: " << q -> head << " :: tail :: " << q -> tail << "\n";
    if (!C_IsEmptyQue(q)) {
        int i = q -> head;
        do {
            i = (i + 1) % MAX_CQUE_SIZE;
            cout << q -> data[i] << "||";
            if (q -> tail == i) {
                break;
            }
        } while (i != q -> head);
        cout << "\n";
    }
}

bool C_IsFullQue(CircularQueType * q) {
    if ((q -> tail + 1) % MAX_CQUE_SIZE == q -> head) {
        return true;
    } else {
        return false;
    }
}

bool C_IsEmptyQue(CircularQueType * q) {
    if (q -> head == q -> tail) {
        return true;
    } else {
        return false;
    }
}

void C_Enqueue(CircularQueType * q, int data) {
    if (C_IsFullQue(q)) {
        cout << "Que is Full :: Can not Insert\n";
    } else {
        q -> tail = (q -> tail + 1) % MAX_CQUE_SIZE;
        q -> data[q -> tail] = data;
    }
}

int C_Dequeue(CircularQueType * q) {
    if (C_IsEmptyQue(q)) {
        cout << "Que is Empty :: Can not Deque\n";
        return 1;
    } else {
        q -> head = (q -> head + 1) % MAX_CQUE_SIZE;
        return q -> data[q -> head];
    }
}


int C_Peek(CircularQueType * q) {
    return q -> data[(q -> head) + 1];
}
