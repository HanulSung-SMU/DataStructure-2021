#ifndef _409_CircularQue_hpp
#define _409_CircularQue_hpp

#include <stdio.h>
#include <iostream>

#define MAX_CQUE_SIZE 5

using namespace std;

typedef int element_cque;
typedef struct {
    int head, tail;
    element_cque data[MAX_CQUE_SIZE];
} CircularQueType;

void C_InitQue(CircularQueType * q);
void C_PrintQue(CircularQueType * q);
bool C_IsFullQue(CircularQueType * q);
bool C_IsEmptyQue(CircularQueType * q);
void C_Enqueue(CircularQueType * q, int data);
int C_Dequeue(CircularQueType * q);
int C_Peek(CircularQueType * q);

#endif /* _409_CircularQue_hpp */
