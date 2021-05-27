#pragma once
#include<stdio.h>
#include"data.h"
#pragma warning(disable : 4996)

void MemoryError(char* message);
void saveTxt(InfoHead* info_head);
InfoHead* loadTxt();

IcecreamNode* makeNode_ice();
IcecreamConeNode* makeNode_con();
HandPackNode* makeNode_hp();
BeverageNode* makeNode_bv();

void print_hp(HandPackNode* head);
void print_ic(IcecreamNode* head);
void printIcInfo(IcecreamNode* head);
void print_bv(BeverageNode* head);
void printBvInfo(BeverageNode* head);

char* search_ic_with_num(IcecreamNode* Icecream_info, int menu_num);
IcecreamNode* search_ic_with_name(IcecreamNode* phead);
char* search_bv_with_num(BeverageNode* beverage_info, int menu_num);
BeverageNode* search_bv_with_name(BeverageNode* phead);