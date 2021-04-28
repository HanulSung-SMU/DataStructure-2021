#include <stdio.h>
#include <iostream>

#define MAX_LL_SIZE 100

using namespace std;

typedef int element_LL;
typedef struct {
    element_LL data[MAX_LL_SIZE];
    int size {};
} ArrayListType;

void Init(ArrayListType * l);
void Insert(ArrayListType * l, int pos, int item);
void InsertLast(ArrayListType * l, int item);
void InsertFirst(ArrayListType * l, int item);
int Delete(ArrayListType * l, int pos);
void Clear(ArrayListType * l);

int GetEntry(ArrayListType * l, int pos);
int GetLength(ArrayListType * l);

bool IsEmpty(ArrayListType * l);
bool IsFull(ArrayListType * l);

void PrintList(ArrayListType * l);

