#ifndef _409_Deq_hpp
#define _409_Deq_hpp

#include <stdio.h>
#include <iostream>

#define MAX_DEQ_SIZE 8

using namespace std;

typedef int element_deq;
typedef struct {
    int head, tail;
    element_deq data[MAX_DEQ_SIZE];
} DeqType;


void InitDeq(DeqType * q);
void PrintDeq(DeqType * q);

bool IsFullDeq(DeqType * q);
bool IsEmptyDeq(DeqType * q);

void PushFront(DeqType * q, int data);
void PushBack(DeqType * q, int data);

int PopFront(DeqType * q);
int PopBack(DeqType * q);

int PeekFront(DeqType * q);
int PeekBack(DeqType * q);


#endif /* _409_DEQ_hpp */
