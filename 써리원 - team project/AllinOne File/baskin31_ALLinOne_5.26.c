#include<stdio.h>
#pragma warning(disable : 4996)
#define MAX 30
typedef struct IcecreamNode {	// ���̽�ũ�� ����
	int ic_num;					// ��ȣ
	char name[MAX];				// ��ǰ��
	int kcal;					// ����(kcal)
	int prefer;					// ��ǰ��ȣ����
	struct IcecreamNode* link;  // ���� ����� �ּҸ� ������ ������ 
}IcecreamNode;

typedef struct IcecreamConeNode {// ���̽�ũ�� ��/�� ����
	int con_num;				// ��ȣ
	char ctype[MAX];			// ������
	int cserving;				// ������(g)
	int cprice;					// ����(\)
	struct IcecreamConeNode* link;// ���� ����� �ּҸ� ������ ������
}IcecreamConeNode;

typedef struct HandPackNode {	// handpack ����
	int hp_num;					// ��ȣ
	char htype[MAX];			// ������
	int hserving;				// ������(g)
	int hprice;					// ����(\)
	struct HandPackNode* link;	// ���� ����� �ּҸ� ������ ������
}HandPackNode;

typedef struct BeverageNode {	// ��������
	int bv_num;					// ��ȣ
	char bvtype[MAX];			// ��ǰ��
	int bvserving;				// ������
	int kcal;					// ����
	int bvprice;				// ����
	int prefer;					// ��ȣ��
	struct BeverageNode* link;  // ���� ����� �ּҸ� ������ ������
}BeverageNode;

typedef struct InfoHead {		// txt���Ͽ� ����Ǿ� �ִ� �������� �޸𸮻����� �÷����´�.
	IcecreamNode* icecream_link;// ���̽�ũ��, ��/��, handpack, ���� ����
	IcecreamConeNode* icecreamcone_link;
	HandPackNode* handpack_link;
	BeverageNode* beverage_link;
}InfoHead;

typedef struct Order {			// �ֹ� ����Ʈ
	struct MList* head;			// �� �ֹ��� ���� ����
	int spoon_num;				// ��Ǭ����
}Order;

typedef struct MList {			// �� �ֹ��� ���� ����
	char menu_name[MAX];		// �޴� �̸� -> ����, ��/��, handpack����
	char icecream[6][MAX];		// ���̽�ũ�� �̸�
	int num;					// ��, handpack�� ��� ���̽�ũ�� ���� 
	int type;					// �ش� �ֹ��� ��/��(1), handpack(2), ����(3)���� ����
	struct MList* link;			// ���� ����� �ּҸ� ������ ������
}MList;

// stream func
void MemoryError(char* message);
void saveTxt(InfoHead* info_head);
InfoHead* loadTxt();
IcecreamNode* makeNode_ice();
IcecreamConeNode* makeNode_con();
HandPackNode* makeNode_hp();
BeverageNode* makeNode_bv();
void print_ic(IcecreamNode* head);
void printIcInfo(IcecreamNode* head);
void print_bv(BeverageNode* head);
void printBvInfo(BeverageNode* head);
char* search_ic_with_num(IcecreamNode* Icecream_info, int menu_num);
IcecreamNode* search_ic_with_name(IcecreamNode* phead);
char* search_bv_with_num(BeverageNode* beverage_info, int menu_num);
BeverageNode* search_bv_with_name(BeverageNode* phead);

// menu_modify func
IcecreamNode* add_icecream_menu(IcecreamNode** phead);
void delete_icecream_menu(IcecreamNode** phead, IcecreamNode* remove);
BeverageNode* add_bv_menu(BeverageNode** phead);
void delete_bv_menu(BeverageNode** phead, BeverageNode* remove);

// order func
void Ordering(InfoHead* info_head);
int input();
void init_Order(Order* order);
int Show_MenuType();
void MenuList(Order** porder, InfoHead* info_head, int type);
void store(Order** order, MList* node);
void show(Order* order);
void IcecreamType(Order** porder, IcecreamNode* Icecream_info);
void select_ConandCup(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num, int count);
void select_Handpack(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num);
void select_beverage(Order** porder, BeverageNode* beverage_info);
void Cal(Order* order, InfoHead* InfoHead);
int getYesorNo();

void MemoryError(char* message) {

	// �ַ��߻� �� ȣ��, ���� ���� ��� �� ���α׷� ����

	printf("%s", message);
	exit(1);
}

InfoHead* loadTxt() {

	// ������ �޸� ������ �÷����´�.
	// ���̽�ũ��, ��/��, handpack, ���� ����
	// return : InfoHead* -> �� ������ ���� ������ ���� ��� �ִ� ������ 

	InfoHead* info_head = (InfoHead*)malloc(sizeof(info_head));
	if (!info_head)
		MemoryError("memory assignment error\n");
	IcecreamNode* icecream_head = NULL, * icecream_rear = NULL;
	IcecreamConeNode* icecreamcone_head = NULL, * icecreamcone_rear = NULL;
	HandPackNode* handpack_head = NULL, * handpack_rear = NULL;
	BeverageNode* beverage_head = NULL, * beverage_rear = NULL;

	FILE* fp = fopen("icecream_info.txt", "r");
	if (!fp)
		MemoryError("File open error\n");
	while (!feof(fp))// ���� ������ ���� ���� (���� ������ ��� 0 ��ȯ)
	{
		IcecreamNode* newnode = makeNode_ice();
		fscanf(fp, "%d %s %d %d", &(newnode->ic_num), newnode->name, &(newnode->kcal), &(newnode->prefer));
		if (icecream_head == NULL) {
			icecream_head = newnode;
			icecream_rear = newnode;
			newnode->link = NULL;
		}
		else {
			icecream_rear->link = newnode;
			newnode->link = NULL;
			icecream_rear = newnode;
		}
	}
	fclose(fp);

	FILE* fp1 = fopen("icecreamCone_info.txt", "r");
	if (!fp1)
		MemoryError("File open error\n");
	while (!feof(fp1))// ���� ������ ���� ���� (���� ������ ��� 0 ��ȯ)
	{
		IcecreamConeNode* newnode = makeNode_con();
		fscanf(fp1, "%d %s %d %d", &(newnode->con_num), newnode->ctype, &(newnode->cserving), &(newnode->cprice));
		if (icecreamcone_head == NULL) {
			icecreamcone_head = newnode;
			handpack_rear = newnode;
			newnode->link = NULL;
		}
		else {
			handpack_rear->link = newnode;
			newnode->link = NULL;
			handpack_rear = newnode;
		}
	}
	fclose(fp1);

	FILE* fp2 = fopen("HandPack_info.txt", "r");
	if (!fp2)
		MemoryError("File open error\n");
	while (!feof(fp2))// ���� ������ ���� ���� (���� ������ ��� 0 ��ȯ)
	{
		HandPackNode* newnode = makeNode_hp();
		fscanf(fp2, "%d %s %d %d", &(newnode->hp_num), newnode->htype, &(newnode->hserving), &(newnode->hprice));
		if (handpack_head == NULL) {
			handpack_head = newnode;
			handpack_rear = newnode;
			newnode->link = NULL;
		}
		else {
			handpack_rear->link = newnode;
			newnode->link = NULL;
			handpack_rear = newnode;
		}
	}
	fclose(fp2);

	FILE* fp3 = fopen("beverage_info.txt", "r");
	if (!fp3)
		MemoryError("File open error\n");
	while (!feof(fp3))// ���� ������ ���� ���� (���� ������ ��� 0 ��ȯ)
	{
		BeverageNode* newnode = makeNode_bv();
		fscanf(fp3, "%d %s %d %d %d %d", &(newnode->bv_num), newnode->bvtype, &(newnode->bvserving), &(newnode->kcal), &(newnode->bvprice), &(newnode->prefer));
		if (beverage_head == NULL) {
			beverage_head = newnode;
			beverage_rear = newnode;
			newnode->link = NULL;
		}
		else {
			beverage_rear->link = newnode;
			newnode->link = NULL;
			beverage_rear = newnode;
		}
	}
	fclose(fp3);

	info_head->icecream_link = icecream_head;
	info_head->icecreamcone_link = icecreamcone_head;
	info_head->handpack_link = handpack_head;
	info_head->beverage_link = beverage_head;

	return info_head;
}
void saveTxt(InfoHead* info_head) {

	// �����ߴ� ���̽�ũ��, ��/��, handpack, ���� ������ �ٽ� ���Ͽ� ����

	IcecreamNode* ic = info_head->icecream_link;
	BeverageNode* bv = info_head->beverage_link;
	IcecreamNode* ic_tmp = NULL;
	BeverageNode* bv_tmp = NULL;

	FILE* fp;
	if (fopen_s(&fp, "Icecream_info.txt", "w") != NULL) {
		MemoryError("File open error\n");
		exit(1);
	}
	else {
		while (1) {
			if (ic->link == NULL) {
				fprintf(fp, "%d %s %d %d", ic->ic_num, ic->name, ic->kcal, ic->prefer);
				ic_tmp = ic;
				ic = ic->link;
				free(ic_tmp);
				break;
			}
			fprintf(fp, "%d %s %d %d\n", ic->ic_num, ic->name, ic->kcal, ic->prefer);
			ic_tmp = ic;
			ic = ic->link;
			free(ic_tmp);
		}
	}
	fclose(fp);

	FILE* fp1;
	if (fopen_s(&fp1, "Beverage_info.txt", "w") != NULL) {
		MemoryError("File open error\n");
		exit(1);
	}
	else {
		while (1) {
			if (bv->link == NULL) {
				fprintf(fp1, "%d %s %d %d %d %d", bv->bv_num, bv->bvtype, bv->bvserving, bv->kcal, bv->bvprice, bv->prefer);
				bv_tmp = bv;
				bv = bv->link;
				free(bv_tmp);
				break;
			}
			fprintf(fp1, "%d %s %d %d %d %d\n", bv->bv_num, bv->bvtype, bv->bvserving, bv->kcal, bv->bvprice, bv->prefer);
			bv_tmp = bv;
			bv = bv->link;
			free(bv_tmp);
		}
	}
	fclose(fp1);

}

IcecreamNode* makeNode_ice() {

	// ���̽�ũ�� ��� ����
	// return : ���̽�ũ�� ��� ������

	IcecreamNode* tmp = (IcecreamNode*)malloc(sizeof(IcecreamNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

IcecreamConeNode* makeNode_con() {

	// ��/�� ��� ����
	// return : ��/�� ��� ������

	IcecreamConeNode* tmp = (IcecreamConeNode*)malloc(sizeof(IcecreamConeNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

HandPackNode* makeNode_hp() {

	// handpack ��� ����
	// return : handpack ��� ������

	HandPackNode* tmp = (HandPackNode*)malloc(sizeof(HandPackNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

BeverageNode* makeNode_bv() {

	// ���� ��� ����
	// return : ���� ��� ������

	BeverageNode* tmp = (BeverageNode*)malloc(sizeof(BeverageNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

void print_ic(IcecreamNode* head) {

	// ���̽�ũ�� �޴� ���� ���

	IcecreamNode* curr = head;
	printf(" ��ȣ          �̸�            kcal  ��ȣ��\n");
	while (curr != NULL) {
		printf("%3d�� %20s %5dkcal %3dȸ\n", curr->ic_num, curr->name, curr->kcal, curr->prefer);
		curr = curr->link;
	}
}

void printIcInfo(IcecreamNode* head) {

	// ���̽�ũ�� ���� �ϳ� ���

	IcecreamNode* curr = head;
	printf(" ��ȣ          �̸�            kcal  ��ȣ��\n");
	printf("%3d�� %20s %5dkcal %3dȸ\n", curr->ic_num, curr->name, curr->kcal, curr->prefer);
	printf("\n");
}

void print_bv(BeverageNode* head) {

	// ���� �޴� ���� ���

	BeverageNode* curr = head;
	printf(" ��ȣ           �̸�            ������   kcal      ����  ��ȣ��\n");
	while (curr != NULL) {
		printf("%3d�� %25s %4dg %5dkcal %6d�� %3d��\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
		curr = curr->link;
	}
}

void printBvInfo(BeverageNode* head) {

	// ���� ���� �ϳ� ���

	BeverageNode* curr = head;
	printf(" ��ȣ           �̸�            ������   kcal      ����  ��ȣ��\n");
	printf("%d�� %s %dg %dkcal %d�� %dȸ\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
	printf("\n");
}

char* search_ic_with_num(IcecreamNode* Icecream_info, int menu_num) {

	// ���̽�ũ���� ��ȣ�� �˻�
	// return : �߰� = ���̽�ũ�� �̸�, �߰� X = NULL 

	for (IcecreamNode* i = Icecream_info; i != NULL; i = i->link) {
		if (i->ic_num == menu_num) {
			i->prefer++;
			return i->name;
		}
	}
	return NULL;
}

IcecreamNode* search_ic_with_name(IcecreamNode* phead) {

	// ���̽�ũ�� �̸����� �˻�
	// return : �߰� = �ش� ���̽�ũ�� ���

	IcecreamNode* p = phead;
	char n[MAX];

	do
	{
		printf("** �˻��� ���̽�ũ���� �̸��� �Է����ּ��� **\n");
		scanf_s("%s", n, sizeof(n));

		while (p != NULL)
		{
			if (strcmp(p->name, n) == 0) // �� ����� �����Ϳ� �ִ� �̸� �� 
				return p; // ã���� while �� ��������
			p = p->link; // ���� ���� �̵�
		}
		if (p == NULL) // ���������� ���µ� �˻��� ���̽�ũ�� ������ �������� �ʴ´ٸ� 
		{
			printf("\n�˻��� ���̽�ũ�� ������ �������� �ʽ��ϴ�\n\n");
			continue;
		}
	} while (p == NULL);

	return p; // �˻��� ���̽�ũ���� �̸��� ���� ��� �ּҰ� ��ȯ
}

char* search_bv_with_num(BeverageNode* beverage_info, int menu_num) {

	// ���Ḧ ��ȣ�� �˻�
	// return : �߰� = ���� �̸�, �߰� X = NULL 

	for (BeverageNode* i = beverage_info; i != NULL; i = i->link) {
		if (i->bv_num == menu_num) {
			i->prefer++;
			return i->bvtype;
		}
	}
	return NULL;
}

BeverageNode* search_bv_with_name(BeverageNode* phead) {

	// ���Ḧ �̸����� �˻�
	// return : �߰� = �ش� ���� ���

	BeverageNode* p = phead;
	char n[MAX];

	do
	{
		printf("** �˻��� ������ �̸��� �Է����ּ��� **\n");
		scanf_s("%s", n, sizeof(n));

		while (p != NULL)
		{
			if (strcmp(p->bvtype, n) == 0) // �� ����� �����Ϳ� �ִ� �̸� �� 
				return p; // ã���� while �� ��������
			p = p->link; // ���� ���� �̵�
		}
		if (p == NULL) // ���������� ���µ� �˻��� ���� ������ �������� �ʴ´ٸ� 
		{
			printf("\n�˻��� ���� ������ �������� �ʽ��ϴ�\n\n");
			continue;
		}
	} while (p == NULL);

	return p; // �˻��� ������ �̸��� ���� ��� �ּҰ� ��ȯ
}

IcecreamNode* add_icecream_menu(IcecreamNode** phead) {

	// ���̽�ũ�� �޴� �߰�
	// return : ���̽�ũ�� �޴� 

	IcecreamNode* p = (IcecreamNode*)malloc(sizeof(IcecreamNode));
	if (!p)
		MemoryError("memory assignment error");
	IcecreamNode* pre = NULL;
	IcecreamNode* front = *phead;
	IcecreamNode* rear = *phead;

	printf("** �߰��� ���̽�ũ���� ��ǰ��, ����, ��ǰ��ȣ������ �Է����ּ��� **\n");
	fscanf(stdin, "%s %d %d", (p->name), &(p->kcal), &(p->prefer));

	while (rear != NULL)
	{
		pre = rear;
		rear = rear->link; // ���� ���� �̵�

		if (rear == NULL)
		{
			pre->link = p;
			p->link = NULL;
			p->ic_num = pre->ic_num + 1;
		}
	}

	return front;
}

void delete_icecream_menu(IcecreamNode** phead, IcecreamNode* remove) {

	// ���̽�ũ�� �̸��� �˻��ؼ� ���̽�ũ�� �޴� ��Ͽ��� ����

	IcecreamNode* s = *phead;
	IcecreamNode* p = NULL;

	if (s == NULL) {
		printf("icecream�޴��� �������� �ʽ��ϴ�. \n");
		return;
	}
	else {
		while (s != NULL) {
			if (s == remove) {
				p->link = remove->link;
				free(remove);
				break;
			}
			p = s;
			s = s->link;
		}

		while (1)
		{
			p = p->link;
			if (!p)
				break;
			--(p->ic_num);
		}
	}
}

BeverageNode* add_bv_menu(BeverageNode** phead) {

	// ���� �޴� �߰�
	// return : ���� �޴� 

	BeverageNode* p = (BeverageNode*)malloc(sizeof(BeverageNode));
	if (!p)
		MemoryError("memory assignment error");
	BeverageNode* pre = NULL;
	BeverageNode* front = *phead;
	BeverageNode* rear = *phead;

	printf("** �߰��� ������� ��ǰ��, ������, ����, ����, ��ǰ��ȣ������ �Է����ּ��� **\n");
	fscanf(stdin, "%s %d %d %d %d", (p->bvtype), &(p->bvserving), &(p->kcal), &(p->bvprice), &(p->prefer));
	while (rear != NULL)
	{
		pre = rear;
		rear = rear->link;

		if (rear == NULL)
		{
			pre->link = p;
			p->link = NULL;
			p->bv_num = pre->bv_num + 1;
		}
	}

	return front;
}

void delete_bv_menu(BeverageNode** phead, BeverageNode* remove) {

	// ���� �̸��� �˻��ؼ� ���� �޴� ��Ͽ��� ����

	BeverageNode* s = *phead;
	BeverageNode* p = NULL;
	print_bv(*phead);
	if (s == NULL) {
		printf("icecream�޴��� �������� �ʽ��ϴ�. \n");
		return;
	}
	else
	{
		while (s != NULL) {
			if (s == remove) {
				p->link = remove->link;
				free(remove);
				break;
			}
			p = s;
			s = s->link;
		}

		while (1)
		{
			p = p->link;
			if (!p)
				break;
			--(p->bv_num);
		}
	}
}

void Ordering(InfoHead* info_head) {

	// �ֹ��ϴ� �Լ� 

	Order* order = (Order*)malloc(sizeof(Order));
	if (!order)
		MemoryError("memory assignment error");
	init_Order(order);
	int type = 0, type2 = 0;
	while (1) {
		type = Show_MenuType();
		MenuList(&order, info_head, type);	//�޴����� ���ϴ� �׸� �����ϱ�
		show(order);						// �ֹ���������
		while (1) {
			printf("\n*************************\n");
			printf("     1. �����ϱ�\n");
			printf("     2. �� �ֹ��ϱ�");
			printf("\n*************************\n");
			scanf_s("%d", &type2);
			if (type2 < 1 || type2 > 2) {
				printf("1~2�� �ȿ��� �������ּ���.\n");
				continue;
			}
			break;
		}
		if (type2 == 1) {
			if (order->spoon_num == -1) {
				printf("���ϴ� ������ ������ �Է��ϼ���.\n");
				order->spoon_num = input();
			}
			break;
		}
	}
	//����ϱ�
	Cal(order, info_head);
}
int input() {

	// ����ڷκ��� �ֹ������� �Է¹޴� �Լ�
	// 1�̻����� �Է¹��� ������ �ݺ�
	// return : �ֹ�����

	int num = 0;
	while (1) {
		scanf_s("%d", &num);
		if (num <= 0) {
			printf("�Ѱ��̻� �ֹ����ּ���.\n");
			continue;
		}
		break;
	}
	return num;
}
void init_Order(Order* order) {

	// �ֹ� ����Ʈ �ʱ�ȭ

	order->spoon_num = 0;
	order->head = NULL;
}
int Show_MenuType() {

	// ����ڿ��� �ֹ� �׸��� �����ְ� �ش� �׸� ���� �Է��� ���� 
	// 1 : ���̽�ũ�� , 2 : ����� 
	// return : �ֹ� �׸� ���� index

	printf("���ϴ� �׸��� �����ϼ���.\n");
	for (int type = 0; ;) {
		printf("***********************\n");
		printf("    1. IceCream\n");
		printf("    2. Beverage\n");
		printf("***********************\n");
		scanf_s("%d", &type);
		if (type < 1 || type>2) {
			printf("1~2�� �׸���̿��� ����ּ���.\n");
			continue;
		}
		return type;
	}
}
void MenuList(Order** porder, InfoHead* info_head, int type) {

	// �ֹ� �׸� ���� ���̽�ũ���� ����ȭ���̳� ���ἱ��ȭ������ �̵� 

	switch (type) {
	case 1:
		IcecreamType(porder, info_head->icecream_link);
		break;
	case 2:
		select_beverage(porder, info_head->beverage_link);
		break;
	}
}
void store(Order** order, MList* node) {

	// �ֹ������� �ֹ�����Ʈ�� �߰�

	if ((*order)->head == NULL) {
		node->link = NULL;
		(*order)->head = node;
	}
	else {
		node->link = (*order)->head;
		(*order)->head = node;
	}
}
void show(Order* order) {

	// �ֹ������� ������

	printf("~~~~~~~~~�ֹ�����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (MList* i = order->head; i != NULL; i = i->link) {
		if (i->num > 1) {
			printf("* �޴� : %s, ���� : 1��\n���̽�ũ�� ����\n", i->menu_name);
			for (int j = 0; j < i->num; j++)
				printf("%d. %s\n", j + 1, i->icecream[j]);
		}
		else if (strcmp(i->icecream[0], "no") == 0)
			printf("* �޴� : %s, ���� : 1��\n", i->menu_name);
		else
			printf("* �޴� : %s, ���̽�ũ�� ���� : %s, ���� : %d��\n", i->menu_name, i->icecream[0], i->num);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void IcecreamType(Order** porder, IcecreamNode* Icecream_info) {

	// ��/�� �� handpack�� �ϳ��� ����
	// ���� �� ���̽�ũ�� �Է�ȭ������ �̵�

	int type = 0, Con_type = 0, Handpack_type = 0, _num = 0, count = 0;
	char icecreamtype_name[MAX];
	printf("���ϴ� �׸��� �����ϼ���.\n");
	while (1) {													// Con&Cup�� HandPack�� �ϳ� ����
		printf("***********************\n");
		printf("    1. Con & Cup\n");
		printf("    2. HandPack\n");
		printf("***********************\n");
		scanf_s("%d", &type);
		if (type < 1 || type>2) {
			printf("1~4�� �׸���̿��� ����ּ���.\n");
			continue;
		}
		break;
	}

	printf("���ϴ� ����� �����ϼ���.\n");
	if (type == 1) {
		while (1) {
			printf("-----------------------\n");
			printf("    1. �̱۷��ַ�\n");
			printf("    2. �̱�ŷ\n");
			printf("    3. �����ִϾ�\n");
			printf("    4. �����ַ�\n");
			printf("-----------------------\n");
			scanf_s("%d", &Con_type);
			if (Con_type < 1 || Con_type>4) {
				printf("1~4�� �׸���̿��� ����ּ���.\n\n");
				continue;
			}
			break;
		}

		printf("��� �����Ͻ��� �Է��Ͻʽÿ�.\n");
		count = input();

		if (Con_type == 1) {
			strcpy(icecreamtype_name, "�̱۷��ַ�");
			_num = 1;
		}
		else if (Con_type == 2) {
			strcpy(icecreamtype_name, "�̱�ŷ");
			_num = 1;
		}
		else if (Con_type == 3) {
			strcpy(icecreamtype_name, "�����ִϾ�");
			_num = 2;
		}
		else {
			strcpy(icecreamtype_name, "�����ַ�");
			_num = 2;
		}

		select_ConandCup(porder, Icecream_info, icecreamtype_name, _num, count);
	}
	else {
		while (1) {
			printf("-----------------------\n");
			printf("    1. ����Ʈ\n");
			printf("    2. ����\n");
			printf("    3. �йи�\n");
			printf("    4. ��������\n");
			printf("-----------------------\n");
			scanf_s("%d", &Handpack_type);
			if (Handpack_type < 1 || Handpack_type>4) {
				printf("1~4�� �׸���̿��� ����ּ���.\n\n");
				continue;
			}
			break;
		}
		if (Handpack_type == 1) {
			strcpy(icecreamtype_name, "����Ʈ");
			_num = 3;
		}
		else if (Handpack_type == 2) {
			strcpy(icecreamtype_name, "����");
			_num = 4;
		}
		else if (Handpack_type == 3) {
			strcpy(icecreamtype_name, "�йи�");
			_num = 5;
		}
		else {
			strcpy(icecreamtype_name, "��������");
			_num = 6;
		}

		select_Handpack(porder, Icecream_info, icecreamtype_name, _num);
	}
}
void select_ConandCup(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num, int count) {

	// ��/�ſ��� ���̽�ũ�� ����ȭ��, ����ڰ� �Է��ߴ� ������ŭ ���̽�ũ�� �Է�

	int icecream_num = 0;
	char* name;
	for (int i = 0; i < count; i++) {
		MList* node = (MList*)malloc(sizeof(MList));
		if (!node)
			MemoryError("memory assignment error");

		node->num = num;
		node->type = 1;
		for (int i = 0; i < num; i++) {
			strcpy(node->menu_name, icecreamtype_name);
			printf("���ϴ� ���̽�ũ�� �׸��� ��ȣ�� �Է��ϼ���.\n");
			print_ic(Icecream_info);
			while (1) {
				printf("=> ");
				scanf_s("%d", &icecream_num);
				name = search_ic_with_num(Icecream_info, icecream_num);
				if (icecream_num < 0 || !name) {
					printf("����Ʈ �ȿ��� �ֹ����ּ���.");
					continue;
				}
				break;
			}
			strcpy(node->icecream[i], name);
		}
		store(porder, node);
	}
}

void select_Handpack(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num) {

	// handpack���� ���̽�ũ�� ����ȭ��

	int icecream_num = 0;
	char* name = NULL;
	MList* node = (MList*)malloc(sizeof(MList));
	if (!node)
		MemoryError("memory assignment error");
	node->num = num;
	node->type = 2;
	(*porder)->spoon_num = -1;
	strcpy(node->menu_name, icecreamtype_name);

	for (int i = 0; i < num;) {
		print_ic(Icecream_info);
		printf("%d���� ���� �����ϼ���.\n", num - i);
		while (1) {
			printf("=> ");
			scanf_s("%d", &icecream_num);
			name = search_ic_with_num(Icecream_info, icecream_num);
			if (icecream_num < 0 || !name) {
				printf("����Ʈ �ȿ��� �ֹ����ּ���.");
				continue;
			}
			break;
		}
		strcpy(node->icecream[i++], name);
	}
	printf("\n");
	store(porder, node);
}

void select_beverage(Order** porder, BeverageNode* beverage_info) {

	// ���� ����ȭ��, ����ڰ� �Է��ߴ� ������ŭ ���ἱ��

	int beverage_num;
	char* name = NULL;

	MList* node = (MList*)malloc(sizeof(MList));
	if (!node)
		MemoryError("memory assignment error");

	node->num = 1;
	node->type = 3;
	strcpy(node->icecream[0], "no");
	printf("���ϴ� ���� �׸��� ��ȣ�� �Է��ϼ���.\n");
	print_bv(beverage_info);
	while (1) {
		printf("=> ");
		scanf_s("%d", &beverage_num);
		name = search_bv_with_num(beverage_info, beverage_num);
		if (beverage_num < 0 || !name) {
			printf("����Ʈ �ȿ��� �ֹ����ּ���.");
			continue;
		}
		break;
	}
	printf("name : %s\n", name);
	strcpy(node->menu_name, name);
	store(porder, node);
}

void Cal(Order* order, InfoHead* InfoHead) {

	// �ֹ�����Ʈ�� ������ ��� �� ����ڿ��� ������ �Է¹޾� �Ž������� ����ϰ� ����

	int total_price = 0, money = 0, change = 0;
	int membership;
	for (MList* i = order->head; i != NULL; i = i->link) {
		switch (i->type) {
		case 1:
			for (IcecreamConeNode* j = InfoHead->icecreamcone_link; j != NULL; j = j->link) {
				if (!strcmp(i->menu_name, j->ctype)) {
					total_price += j->cprice;
					break;
				}
			}
		case 2:
			for (HandPackNode* j = InfoHead->handpack_link; j != NULL; j = j->link) {
				if (!strcmp(i->menu_name, j->htype)) {
					total_price += j->hprice;
					break;
				}
			}
		case 3:
			for (BeverageNode* j = InfoHead->beverage_link; j != NULL; j = j->link) {
				if (!strcmp(i->menu_name, j->bvtype)) {
					total_price += j->bvprice;
					break;
				}
			}
		}
	}
	//����� ���ο� ���� ����Ʈ 30% ����
	printf("KT ����� ���̽ö�� ����Ʈ�� 30%%\ �����ص帳�ϴ�. KT ����� ���̽Ű���?\n");
	membership = getYesorNo();
	if (membership == 1) {
		for (MList* i = order->head; i != NULL; i = i->link) {
			if (!strcmp(i->menu_name, "����Ʈ")) {
				total_price -= 2500;
			}
		}
	}
	while (1) {
		printf("�� ������ %d �� �Դϴ�. ������ �׼��� �Է����ּ���(��) : ", total_price);
		scanf_s("%d", &money);
		change = money - total_price;
		if (change >= 0) {
			printf("�Ž������� %d ���Դϴ�. ����Ų��󽺸� �̿����ּż� �����մϴ�!\n", change);
			printf("---------------------------------------------------------------\n");
			saveTxt(InfoHead);
			free(order);
			exit(1);
		}
		else {
			printf("\n�ݾ��� �����մϴ�. �׼��� �ٽ� �Է��� �ּ���.\n");
			printf("---------------------------------------------------------------\n");
			change = 0;
		}
	}
}

int getYesorNo() {

	// Y �Ǵ� N�� ���� �Է¹޴� �Լ�
	// y/Y : 1, n/N : 2, ���н� -1
	// return : 1 / 2 / -1

	int key;

	printf("(�� : Y, �ƴϿ� : N) : ");

	while ((key = getch()) != NULL) {
		if (key == 'y' || key == 'Y') {
			puts("Y");
			return 1; // ���� ��ȯ
		}
		else if (key == 'n' || key == 'N') {
			puts("N");
			return 0; // ������ ��ȯ
		}
	}
	return -1;
}

int main(void)
{
	IcecreamNode* getInfoIc = NULL;
	BeverageNode* getInfoBv = NULL;
	IcecreamNode* editIc = NULL;
	int input;

	InfoHead* info_head = loadTxt();
	printf("===========================================\n");
	printf("** ^^������� �轺Ų��� 31�Դϴ�^^ **\n");
	printf("===========================================\n");
	printf("\n");
	do
	{
		printf("\n���Ͻô� ��ȣ�� ���� �������ּ���\n");
		printf("\n");
		printf("0. �����ϱ�\n");
		printf("1. ���̽�ũ�� ���� ����\n");
		printf("2. ���� ���� ����\n");
		printf("3. �ֹ��ϱ�\n");
		printf("4. ���̽�ũ�� ���� �˻��ϱ�\n");
		printf("5. ���� ���� �˻��ϱ�\n");
		printf("\n");
		printf("===========================================\n");
		printf("**** ������ ���� ****\n");
		printf("===========================================\n");
		printf("6. ���̽�ũ�� �޴� �߰��ϱ�\n");
		printf("7. ���̽�ũ�� �޴� �����ϱ�\n");
		printf("8. ���� �޴� �߰��ϱ�\n");
		printf("9. ���� �޴� �����ϱ�\n");
		printf("\n");
		printf("���Ͻô� ��ȣ�� �Է����ּ���\n");
		scanf_s("%d", &input, sizeof(input));

		switch (input)
		{
		case 0:
			printf("�����մϴ�^^ �����ϰڽ��ϴ�\n");
			saveTxt(info_head);
			break;

		case 1:
			// ���̽�ũ�� ��ü ���� ����
			print_ic(info_head->icecream_link);
			break;

		case 2:
			// ���� ��ü ���� ���� 
			print_bv(info_head->beverage_link);
			break;

		case 3:
			Ordering(info_head);
			break;

		case 4:
			// ã�� ���� ���̽�ũ�� ���� �˻�   
			getInfoIc = search_ic_with_name(info_head->icecream_link);
			printIcInfo(getInfoIc);
			break;

		case 5:
			// ã�� ���� ���� ���� �˻�   
			getInfoBv = search_bv_with_name(info_head->beverage_link);
			printBvInfo(getInfoBv);
			break;

		case 6:
			// ���̽�ũ�� �޴� �߰�  
			printf("** ���̽�ũ�� ������ �߰��ϰڽ��ϴ� **\n");
			info_head->icecream_link = add_icecream_menu(&(info_head->icecream_link));
			printf("\n");
			print_ic(info_head->icecream_link);// ic�� �Ű������� �����ص� ��� ����.  
			break;
		case 7:
			// ���̽�ũ�� �޴� ���� �Լ� 
			printf("** ���̽�ũ�� ������ �����ϰڽ��ϴ� **\n");
			print_ic(info_head->icecream_link);
			IcecreamNode* ic_searched = search_ic_with_name(info_head->icecream_link);
			delete_icecream_menu(&info_head->icecream_link, ic_searched);
			printf("\n");
			print_ic(info_head->icecream_link);
			break;

		case 8:
			// ���� �޴� �߰� �Լ� 
			printf("** ���� ������ �߰��ϰڽ��ϴ� **\n");
			info_head->beverage_link = add_bv_menu(&info_head->beverage_link);
			printf("\n");
			print_bv(info_head->beverage_link);
			break;

		case 9:
			// ���� �޴� ���� �Լ� 
			printf("** ���� ������ �����ϰڽ��ϴ� **\n");
			print_bv(info_head->beverage_link);
			BeverageNode* bv_searched = search_bv_with_name(info_head->beverage_link);
			delete_bv_menu(&info_head->beverage_link, bv_searched);
			printf("\n");
			print_bv(info_head->beverage_link);
			break;
		}
	} while (input != 0);

	return 0;
}