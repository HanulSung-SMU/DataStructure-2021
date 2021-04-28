//
//  ListPoly.hpp
//  data_struct
//
//  Created by 쩡수 on 2021/04/21.
//

#ifndef ListPoly_hpp
#define ListPoly_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct ListPolynomialNode {
    int coef;
    int expon;
    struct ListPolynomialNode * link;
} ListPolynomialNode;

typedef struct {
    int size;
    ListPolynomialNode * head;
    ListPolynomialNode * tail;
} ListPolynomialType;



void InsertListPoly(ListPolynomialType * lp, int coef, int expon);
void PrintListPoly(ListPolynomialType * lp);

ListPolynomialType * Create();
void SumListPoly(ListPolynomialType * lp1, ListPolynomialType * lp2, ListPolynomialType * lp3);

#endif /* ListPoly_hpp */
