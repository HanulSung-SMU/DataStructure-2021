#ifndef _4_hpp
#define _4_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_QUE_SIZE 5

typedef int element_que;
typedef struct {
    int head;
    int tail;
    element_que data[MAX_QUE_SIZE];
} LinearQueType;

void InitQue(LinearQueType * q);
void PrintQue(LinearQueType * q);
bool IsFullQue(LinearQueType * q);
bool IsEmptyQue(LinearQueType * q);
void Enqueue(LinearQueType * q, int data);
int Dequeue(LinearQueType * q);
int Peek(LinearQueType * q);

#endif /* _4_hpp */
