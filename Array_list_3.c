#include<stdio.h>
#include<stdlib.h>
#include <string.h>


//다항식 리스트의 노드 구조 정의
typedef struct node {
    int coef; //계수
    int expo; //지수
    struct node* link;
} node;

typedef struct listhead {
    node* head;
} listhead;

//공백 다항식 리스트 생성
listhead* createLinkedList(void) {
    listhead* L;
    L = (listhead*)malloc(sizeof(listhead));
    L->head = NULL;
    return L;
}

//다항식 리스트에 마지막 노드 삽입
void addLastnode(listhead* L, int coef, int expo) {
    node* newnode;
    node* p;
    newnode = (node*)malloc(sizeof(node));
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->link = NULL;
    if (L->head == NULL) {
        L->head = newnode;
        return;
    }
    else {
        p = L->head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = newnode;
    }
}

//두 다항식의 합
void addPoly(listhead* A, listhead* B, listhead* C) {
    node* pA = A->head;
    node* pB = B->head;
    int sum;

    while (pA && pB) {
        if (pA->expo == pB->expo) {
            sum = pA->coef + pB->coef;
            addLastnode(C, sum, pA->expo);
            pA = pA->link; pB = pB->link;
        }
        else if (pA->expo > pB->expo) {
            addLastnode(C, pA->coef, pA->expo);
            pA = pA->link;
        }
        else {
            addLastnode(C, pB->coef, pB->expo);
            pB = pB->link;
        }
    }
    for (; pA != NULL; pA = pA->link)
        addLastnode(C, pA->coef, pA->expo);
    for (; pB != NULL; pB = pB->link)
        addLastnode(C, pB->coef, pB->expo);
}

//다항식 리스트를 출력
void printPoly(listhead* L) {
    node* p = L->head;
    for (;p;p = p->link) {
        printf("%3.0dx^%d", p->coef, p->expo);
    }
}

int main(void) {
    //리스트 노드 생성
    listhead* A, * B, * C;
    //공백 다항식 리스트 A, B, C 생성
    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();

    addLastnode(A, 3, 12);
    addLastnode(A, 2, 8);
    addLastnode(A, 1, 0);
    printf("A =");
    printPoly(A);

    addLastnode(B, 8, 12);
    addLastnode(B, -3, 10);
    addLastnode(B, 10, 6);
    printf("\nB =");
    printPoly(B);

    addPoly(A, B, C);
    printf("\nC = A + B =");
    printPoly(C);
    getchar();
}