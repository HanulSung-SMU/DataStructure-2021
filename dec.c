#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX_DEQUE_SIZE 5
#include <stdio.h>
#include <stdlib.h>

typedef int boolean;
typedef int element;
typedef struct __duqueueType {
    element* data;
    int rear, front;
}Deque;
void init_deque(Deque* q) {
    q->data = (element*)malloc(sizeof(element) * MAX_DEQUE_SIZE);
    q->front = q->rear = 0;
}
boolean is_empty(Deque* q) {
    if (q->front == q->rear) return TRUE;
    else return FALSE;
}
element get_rear(Deque* q) {

    if (is_empty) {
        printf("공백큐\n");
        return ERROR;
    }
    return q->data[q->rear];
}
element get_front(Deque* q) {
    if (is_empty(q)) {
        printf("공백큐\n");
        return ERROR;
    }
    return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}
void add_rear(Deque* q, element data) {
    if (is_full(q)) {
        printf("포화큐\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
    q->data[q->rear] = data;
}
element delete_front(Deque* q) {
    if (is_empty(q)) {
        printf("공백큐\n");
        return ERROR;
    }
    element tmp = get_front(q);
    q->front = (q->front + 1) % MAX_DEQUE_SIZE;
    return tmp;
}
element delete_rear(Deque* q) {
    if (is_empty(q)) {
        printf("공백큐\n");
        return ERROR;
    }
    element tmp = q->data[q->rear];
    q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return tmp;
}
void add_front(Deque* q, element data) {
    if (is_full(q)) {
        printf("포화큐\n");
        return;
    }
    q->data[q->front] = data;
    q->front = (q->front - 1 + MAX_DEQUE_SIZE)
        % MAX_DEQUE_SIZE;
    return;
}
boolean is_full(Deque* q) {
    if (((q->rear + 1) % MAX_DEQUE_SIZE) == q->front) return TRUE;
    else return FALSE;
}
void deque_print(Deque* q) {
    int i = (q->front + 1) % MAX_DEQUE_SIZE;
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if (is_empty(q)) {
        printf("공백큐\n");
        return;
    }
    while (i != q->rear) {
        printf("%d | ", q->data[i]);
        i = (i + 1) % MAX_DEQUE_SIZE;
    }
    printf("%d\n", q->data[i]);
}
int main() {
    Deque q;
    init_deque(&q);
    printf("# ADD FRONT\n\n");
    for (int i = 0; i < 3; i++) {
        add_front(&q, i);
        deque_print(&q);
    }
    printf("\n# DELETE REAR\n\n");
    for (int i = 0; i < 3; i++) {
        delete_rear(&q);
        deque_print(&q);
    }
    printf("\n# ADD REAR\n\n");
    for (int i = 0; i < 3; i++) {
        add_rear(&q, i);
        deque_print(&q);
    }
    printf("\n# DELETE FRONT\n\n");
    for (int i = 0; i < 3; i++) {
        delete_front(&q);
        deque_print(&q);
    }
 `  free(q.data);
    return 0;
}

