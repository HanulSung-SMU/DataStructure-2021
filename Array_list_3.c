#include<stdio.h>
#include<stdlib.h>
#include <string.h>


//���׽� ����Ʈ�� ��� ���� ����
typedef struct node {
    int coef; //���
    int expo; //����
    struct node* link;
} node;

typedef struct listhead {
    node* head;
} listhead;

//���� ���׽� ����Ʈ ����
listhead* createLinkedList(void) {
    listhead* L;
    L = (listhead*)malloc(sizeof(listhead));
    L->head = NULL;
    return L;
}

//���׽� ����Ʈ�� ������ ��� ����
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

//�� ���׽��� ��
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

//���׽� ����Ʈ�� ���
void printPoly(listhead* L) {
    node* p = L->head;
    for (;p;p = p->link) {
        printf("%3.0dx^%d", p->coef, p->expo);
    }
}

int main(void) {
    //����Ʈ ��� ����
    listhead* A, * B, * C;
    //���� ���׽� ����Ʈ A, B, C ����
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