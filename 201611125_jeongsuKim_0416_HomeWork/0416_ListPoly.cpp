//
//  ListPoly.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/04/21.
//

#include "0416_ListPoly.hpp"

void InsertListPoly(ListPolynomialType * lp, int coe, int exp) {
    ListPolynomialNode * temp = (ListPolynomialNode *)malloc(sizeof(ListPolynomialNode));
    temp -> coef = coe;
    temp -> expon = exp;
    temp -> link = NULL;
    
    if (lp -> tail == NULL) {
        lp -> head = lp -> tail = temp;
    } else {
        lp -> tail -> link = temp;
        lp -> tail = temp;
    }
    lp -> size++;
}

void PrintListPoly(ListPolynomialType * lp) {
    ListPolynomialNode * next;
    next = lp -> head;
    cout << "polynomial is :: ";
    while (next != NULL) {
        cout << next -> coef << "X^" << next -> expon << " + ";
        next = next -> link;
    }
    cout << "\n";
}

ListPolynomialType * Create() {
    ListPolynomialType * listType;
    listType = (ListPolynomialType *)malloc(sizeof(ListPolynomialType));
    listType -> size = 0;
    listType -> head = listType -> tail = NULL;
    return listType;
}


void SumListPoly(ListPolynomialType * lp1, ListPolynomialType * lp2, ListPolynomialType * lp3) {
    ListPolynomialNode * a = lp1 -> head;
    ListPolynomialNode * b = lp2 -> head;
    int sum {};
    
    while (a && b) {
        if (a -> expon == b -> expon) {
            sum = (a -> coef) + (b -> coef);
            InsertListPoly(lp3, sum, a -> expon);
            a = a -> link;
            b = b -> link;
        } else if (a -> expon > b -> expon) {
            sum = a -> coef;
            InsertListPoly(lp3, sum, a -> expon);
            a = a -> link;
        } else {
            sum = b -> coef;
            InsertListPoly(lp3, sum, b -> expon);
            b = b -> link;
        }
    }
    
    if (a != NULL) {
        while (a != NULL) {
            InsertListPoly(lp3, a -> coef, a -> expon);
            a = a -> link;
        }
    } else if (b != NULL) {
        while (b != NULL) {
            InsertListPoly(lp3, b -> coef, b -> expon);
            b = b -> link;
        }
    }
}
