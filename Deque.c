#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_DEQUE_SIZE];
}Deque;

void init_deque(Deque *q) { //덱초기화
    
    q->front = q->rear = 0;
    
}
void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}
int is_empty(Deque *q) {

    if (q->front == q->rear) 
        return 1;

    else 
        return 0;
}

int is_full(Deque *q) {
    if (((q->rear + 1) % MAX_DEQUE_SIZE) == q->front) 
        return 1;
    else 
      return 0;
}
element get_rear(Deque *q) { //현재 rear 값

    if (is_empty) {
        error("공백 에러\n");
        return 0;
    }
    return q->data[q->rear];
}
element get_front(Deque *q) { //현재 fornt 
    if (is_empty(q)) {
        error("공백 에러\n");
        return 0;
    }
    return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}
void add_rear(Deque *q, element data) {  //덱의 뒤에 추가
    if (is_full(q)==1) {
        printf("포화큐\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
    q->data[q->rear] = data;
}

element delete_front(Deque *q) { //덱 앞에서 삭제
    if (is_empty(q)==1) {
        printf("공백큐\n");
        return 0;
    }
    element tmp = get_front(q);
    q->front = (q->front + 1) % MAX_DEQUE_SIZE;
    return tmp;
}

element delete_rear(Deque *q) { //덱의 뒤에서 삭제
    if (is_empty(q)==1) {
        printf("공백큐\n");
        return 0;
    }
    element tmp = q->data[q->rear];
    q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return tmp;
}

void add_front(Deque *q, element data) { //덱 앞에서 추가
    if (is_full(q)==1) {
        printf("포화큐\n");
        return;
    }
    q->data[q->front] = data;
    q->front = (q->front - 1 + MAX_DEQUE_SIZE)% MAX_DEQUE_SIZE;
    return;
}


void deque_print(Deque *q) {
    int i = (q->front + 1) % MAX_DEQUE_SIZE;
    printf("덱(front=%d rear=%d) = ",q->front,q->rear);
    if (is_empty(q)==1) {
        printf("공백큐\n");
        return;
    }
    while (i!=q->rear) {
        printf("%d | ",q->data[i]);
        i = (i + 1) % MAX_DEQUE_SIZE;
    }
    printf("%d\n",q->data[i]);
}
int main() {
    Deque q;
    init_deque(&q);

    printf("# 앞에서부터 추가\n\n");
    for (int i = 0; i < 3; i++) {
        add_front(&q, i);
        deque_print(&q);
    }
    printf("\n# 뒤에서부터 삭제\n\n");
    for (int i = 0; i < 3; i++) {
        delete_rear(&q);
        deque_print(&q);
    }
    printf("\n# 뒤에서부터 추가\n\n");
    for (int i = 0; i < 3; i++) {
        add_rear(&q, i);
        deque_print(&q);
    }
    printf("\n# 앞에서부터 삭제\n\n");
    for (int i = 0; i < 3; i++) {
        delete_front(&q);
        deque_print(&q);
    }
    return 0;
}

