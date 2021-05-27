#include"stream.h"
void Ordering(InfoHead* info_head);
int input();
void init_Order(Order* order);
int Show_MenuType();
void MenuList(Order** porder, InfoHead* info_head, int type);
void store(Order** order, MList* node);
void show(Order* order);
void IcecreamType(Order** porder, IcecreamNode* Icecream_info);
void select_ConandCup(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name,int num, int count);
void select_Handpack(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num);
void select_beverage(Order** porder, BeverageNode* beverage_info);
void Cal(Order* order, InfoHead* InfoHead);
int getYesorNo();