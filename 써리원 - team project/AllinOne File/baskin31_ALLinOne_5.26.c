#include<stdio.h>
#pragma warning(disable : 4996)
#define MAX 30
typedef struct IcecreamNode {	// 아이스크림 정보
	int ic_num;					// 번호
	char name[MAX];				// 제품명
	int kcal;					// 열량(kcal)
	int prefer;					// 제품선호도값
	struct IcecreamNode* link;  // 다음 노드의 주소를 저장할 포인터 
}IcecreamNode;

typedef struct IcecreamConeNode {// 아이스크림 콘/컵 정보
	int con_num;				// 번호
	char ctype[MAX];			// 콘종류
	int cserving;				// 제공량(g)
	int cprice;					// 가격(\)
	struct IcecreamConeNode* link;// 다음 노드의 주소를 저장할 포인터
}IcecreamConeNode;

typedef struct HandPackNode {	// handpack 정보
	int hp_num;					// 번호
	char htype[MAX];			// 컵종류
	int hserving;				// 제공량(g)
	int hprice;					// 가격(\)
	struct HandPackNode* link;	// 다음 노드의 주소를 저장할 포인터
}HandPackNode;

typedef struct BeverageNode {	// 음료정보
	int bv_num;					// 번호
	char bvtype[MAX];			// 제품명
	int bvserving;				// 제공량
	int kcal;					// 열량
	int bvprice;				// 가격
	int prefer;					// 선호도
	struct BeverageNode* link;  // 다음 노드의 주소를 저장할 포인터
}BeverageNode;

typedef struct InfoHead {		// txt파일에 저장되어 있는 정보들을 메모리상으로 올려놓는다.
	IcecreamNode* icecream_link;// 아이스크림, 콘/컵, handpack, 음료 정보
	IcecreamConeNode* icecreamcone_link;
	HandPackNode* handpack_link;
	BeverageNode* beverage_link;
}InfoHead;

typedef struct Order {			// 주문 리스트
	struct MList* head;			// 각 주문에 대한 정보
	int spoon_num;				// 스푼개수
}Order;

typedef struct MList {			// 각 주문에 대한 정보
	char menu_name[MAX];		// 메뉴 이름 -> 음료, 콘/컵, handpack정보
	char icecream[6][MAX];		// 아이스크림 이름
	int num;					// 콘, handpack의 경우 아이스크림 개수 
	int type;					// 해당 주문이 콘/컵(1), handpack(2), 음료(3)인지 구분
	struct MList* link;			// 다음 노드의 주소를 저장할 포인터
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

	// 애러발생 시 호출, 에러 종류 출력 후 프로그램 종료

	printf("%s", message);
	exit(1);
}

InfoHead* loadTxt() {

	// 파일을 메모리 상으로 올려놓는다.
	// 아이스크림, 콘/컵, handpack, 음료 정보
	// return : InfoHead* -> 위 정보에 대한 내용을 전부 담고 있는 포인터 

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
	while (!feof(fp))// 파일 끝까지 읽을 동안 (끝에 도달한 경우 0 반환)
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
	while (!feof(fp1))// 파일 끝까지 읽을 동안 (끝에 도달한 경우 0 반환)
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
	while (!feof(fp2))// 파일 끝까지 읽을 동안 (끝에 도달한 경우 0 반환)
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
	while (!feof(fp3))// 파일 끝까지 읽을 동안 (끝에 도달한 경우 0 반환)
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

	// 수정했던 아이스크림, 콘/컵, handpack, 음료 정보를 다시 파일에 저장

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

	// 아이스크림 노드 생성
	// return : 아이스크림 노드 포인터

	IcecreamNode* tmp = (IcecreamNode*)malloc(sizeof(IcecreamNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

IcecreamConeNode* makeNode_con() {

	// 콘/컵 노드 생성
	// return : 콘/컵 노드 포인터

	IcecreamConeNode* tmp = (IcecreamConeNode*)malloc(sizeof(IcecreamConeNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

HandPackNode* makeNode_hp() {

	// handpack 노드 생성
	// return : handpack 노드 포인터

	HandPackNode* tmp = (HandPackNode*)malloc(sizeof(HandPackNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

BeverageNode* makeNode_bv() {

	// 음료 노드 생성
	// return : 음료 노드 포인터

	BeverageNode* tmp = (BeverageNode*)malloc(sizeof(BeverageNode));
	if (!tmp)
		MemoryError("memory assignment error\n");
	tmp->link = NULL;
	return tmp;
}

void print_ic(IcecreamNode* head) {

	// 아이스크림 메뉴 전부 출력

	IcecreamNode* curr = head;
	printf(" 번호          이름            kcal  선호도\n");
	while (curr != NULL) {
		printf("%3d번 %20s %5dkcal %3d회\n", curr->ic_num, curr->name, curr->kcal, curr->prefer);
		curr = curr->link;
	}
}

void printIcInfo(IcecreamNode* head) {

	// 아이스크림 정보 하나 출력

	IcecreamNode* curr = head;
	printf(" 번호          이름            kcal  선호도\n");
	printf("%3d번 %20s %5dkcal %3d회\n", curr->ic_num, curr->name, curr->kcal, curr->prefer);
	printf("\n");
}

void print_bv(BeverageNode* head) {

	// 음료 메뉴 전부 출력

	BeverageNode* curr = head;
	printf(" 번호           이름            제공량   kcal      가격  선호도\n");
	while (curr != NULL) {
		printf("%3d번 %25s %4dg %5dkcal %6d원 %3d번\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
		curr = curr->link;
	}
}

void printBvInfo(BeverageNode* head) {

	// 음료 정보 하나 출력

	BeverageNode* curr = head;
	printf(" 번호           이름            제공량   kcal      가격  선호도\n");
	printf("%d번 %s %dg %dkcal %d원 %d회\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
	printf("\n");
}

char* search_ic_with_num(IcecreamNode* Icecream_info, int menu_num) {

	// 아이스크림을 번호로 검색
	// return : 발견 = 아이스크림 이름, 발견 X = NULL 

	for (IcecreamNode* i = Icecream_info; i != NULL; i = i->link) {
		if (i->ic_num == menu_num) {
			i->prefer++;
			return i->name;
		}
	}
	return NULL;
}

IcecreamNode* search_ic_with_name(IcecreamNode* phead) {

	// 아이스크림 이름으로 검색
	// return : 발견 = 해당 아이스크림 노드

	IcecreamNode* p = phead;
	char n[MAX];

	do
	{
		printf("** 검색할 아이스크림의 이름을 입력해주세요 **\n");
		scanf_s("%s", n, sizeof(n));

		while (p != NULL)
		{
			if (strcmp(p->name, n) == 0) // 각 노드의 데이터에 있는 이름 비교 
				return p; // 찾으면 while 문 빠져나옴
			p = p->link; // 다음 노드로 이동
		}
		if (p == NULL) // 마지막까지 갔는데 검색한 아이스크림 정보가 존재하지 않는다면 
		{
			printf("\n검색한 아이스크림 정보가 존재하지 않습니다\n\n");
			continue;
		}
	} while (p == NULL);

	return p; // 검색할 아이스크림의 이름을 가진 노드 주소값 반환
}

char* search_bv_with_num(BeverageNode* beverage_info, int menu_num) {

	// 음료를 번호로 검색
	// return : 발견 = 음료 이름, 발견 X = NULL 

	for (BeverageNode* i = beverage_info; i != NULL; i = i->link) {
		if (i->bv_num == menu_num) {
			i->prefer++;
			return i->bvtype;
		}
	}
	return NULL;
}

BeverageNode* search_bv_with_name(BeverageNode* phead) {

	// 음료를 이름으로 검색
	// return : 발견 = 해당 음료 노드

	BeverageNode* p = phead;
	char n[MAX];

	do
	{
		printf("** 검색할 음료의 이름을 입력해주세요 **\n");
		scanf_s("%s", n, sizeof(n));

		while (p != NULL)
		{
			if (strcmp(p->bvtype, n) == 0) // 각 노드의 데이터에 있는 이름 비교 
				return p; // 찾으면 while 문 빠져나옴
			p = p->link; // 다음 노드로 이동
		}
		if (p == NULL) // 마지막까지 갔는데 검색한 음료 정보가 존재하지 않는다면 
		{
			printf("\n검색한 음료 정보가 존재하지 않습니다\n\n");
			continue;
		}
	} while (p == NULL);

	return p; // 검색할 음료의 이름을 가진 노드 주소값 반환
}

IcecreamNode* add_icecream_menu(IcecreamNode** phead) {

	// 아이스크림 메뉴 추가
	// return : 아이스크림 메뉴 

	IcecreamNode* p = (IcecreamNode*)malloc(sizeof(IcecreamNode));
	if (!p)
		MemoryError("memory assignment error");
	IcecreamNode* pre = NULL;
	IcecreamNode* front = *phead;
	IcecreamNode* rear = *phead;

	printf("** 추가할 아이스크림의 제품명, 열량, 제품선호도값을 입력해주세요 **\n");
	fscanf(stdin, "%s %d %d", (p->name), &(p->kcal), &(p->prefer));

	while (rear != NULL)
	{
		pre = rear;
		rear = rear->link; // 다음 노드로 이동

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

	// 아이스크림 이름을 검색해서 아이스크림 메뉴 목록에서 삭제

	IcecreamNode* s = *phead;
	IcecreamNode* p = NULL;

	if (s == NULL) {
		printf("icecream메뉴가 존재하지 않습니다. \n");
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

	// 음료 메뉴 추가
	// return : 음료 메뉴 

	BeverageNode* p = (BeverageNode*)malloc(sizeof(BeverageNode));
	if (!p)
		MemoryError("memory assignment error");
	BeverageNode* pre = NULL;
	BeverageNode* front = *phead;
	BeverageNode* rear = *phead;

	printf("** 추가할 음료수의 제품명, 제공량, 열량, 가격, 제품선호도값을 입력해주세요 **\n");
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

	// 음료 이름을 검색해서 음료 메뉴 목록에서 삭제

	BeverageNode* s = *phead;
	BeverageNode* p = NULL;
	print_bv(*phead);
	if (s == NULL) {
		printf("icecream메뉴가 존재하지 않습니다. \n");
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

	// 주문하는 함수 

	Order* order = (Order*)malloc(sizeof(Order));
	if (!order)
		MemoryError("memory assignment error");
	init_Order(order);
	int type = 0, type2 = 0;
	while (1) {
		type = Show_MenuType();
		MenuList(&order, info_head, type);	//메뉴보고 원하는 항목 선택하기
		show(order);						// 주문내역보기
		while (1) {
			printf("\n*************************\n");
			printf("     1. 결제하기\n");
			printf("     2. 더 주문하기");
			printf("\n*************************\n");
			scanf_s("%d", &type2);
			if (type2 < 1 || type2 > 2) {
				printf("1~2번 안에서 선택해주세요.\n");
				continue;
			}
			break;
		}
		if (type2 == 1) {
			if (order->spoon_num == -1) {
				printf("원하는 숟가락 개수를 입력하세요.\n");
				order->spoon_num = input();
			}
			break;
		}
	}
	//계산하기
	Cal(order, info_head);
}
int input() {

	// 사용자로부터 주문개수를 입력받는 함수
	// 1이상으로 입력받을 때까지 반복
	// return : 주문개수

	int num = 0;
	while (1) {
		scanf_s("%d", &num);
		if (num <= 0) {
			printf("한개이상 주문해주세요.\n");
			continue;
		}
		break;
	}
	return num;
}
void init_Order(Order* order) {

	// 주문 리스트 초기화

	order->spoon_num = 0;
	order->head = NULL;
}
int Show_MenuType() {

	// 사용자에게 주문 항목을 보여주고 해당 항목에 대한 입력을 받음 
	// 1 : 아이스크림 , 2 : 음료수 
	// return : 주문 항목에 대한 index

	printf("원하는 항목을 선택하세요.\n");
	for (int type = 0; ;) {
		printf("***********************\n");
		printf("    1. IceCream\n");
		printf("    2. Beverage\n");
		printf("***********************\n");
		scanf_s("%d", &type);
		if (type < 1 || type>2) {
			printf("1~2번 항목사이에서 골라주세요.\n");
			continue;
		}
		return type;
	}
}
void MenuList(Order** porder, InfoHead* info_head, int type) {

	// 주문 항목에 따라 아이스크림을 선택화면이나 음료선택화면으로 이동 

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

	// 주문내역을 주문리스트에 추가

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

	// 주문내역을 보여줌

	printf("~~~~~~~~~주문내역~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (MList* i = order->head; i != NULL; i = i->link) {
		if (i->num > 1) {
			printf("* 메뉴 : %s, 수량 : 1개\n아이스크림 종류\n", i->menu_name);
			for (int j = 0; j < i->num; j++)
				printf("%d. %s\n", j + 1, i->icecream[j]);
		}
		else if (strcmp(i->icecream[0], "no") == 0)
			printf("* 메뉴 : %s, 수량 : 1개\n", i->menu_name);
		else
			printf("* 메뉴 : %s, 아이스크림 종류 : %s, 수량 : %d개\n", i->menu_name, i->icecream[0], i->num);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void IcecreamType(Order** porder, IcecreamNode* Icecream_info) {

	// 콘/컵 과 handpack중 하나를 선택
	// 선택 후 아이스크림 입력화면으로 이동

	int type = 0, Con_type = 0, Handpack_type = 0, _num = 0, count = 0;
	char icecreamtype_name[MAX];
	printf("원하는 항목을 선택하세요.\n");
	while (1) {													// Con&Cup과 HandPack중 하나 선택
		printf("***********************\n");
		printf("    1. Con & Cup\n");
		printf("    2. HandPack\n");
		printf("***********************\n");
		scanf_s("%d", &type);
		if (type < 1 || type>2) {
			printf("1~4번 항목사이에서 골라주세요.\n");
			continue;
		}
		break;
	}

	printf("원하는 사이즈를 선택하세요.\n");
	if (type == 1) {
		while (1) {
			printf("-----------------------\n");
			printf("    1. 싱글레귤러\n");
			printf("    2. 싱글킹\n");
			printf("    3. 더블주니어\n");
			printf("    4. 더블레귤러\n");
			printf("-----------------------\n");
			scanf_s("%d", &Con_type);
			if (Con_type < 1 || Con_type>4) {
				printf("1~4번 항목사이에서 골라주세요.\n\n");
				continue;
			}
			break;
		}

		printf("몇개를 구매하실지 입력하십시오.\n");
		count = input();

		if (Con_type == 1) {
			strcpy(icecreamtype_name, "싱글레귤러");
			_num = 1;
		}
		else if (Con_type == 2) {
			strcpy(icecreamtype_name, "싱글킹");
			_num = 1;
		}
		else if (Con_type == 3) {
			strcpy(icecreamtype_name, "더블주니어");
			_num = 2;
		}
		else {
			strcpy(icecreamtype_name, "더블레귤러");
			_num = 2;
		}

		select_ConandCup(porder, Icecream_info, icecreamtype_name, _num, count);
	}
	else {
		while (1) {
			printf("-----------------------\n");
			printf("    1. 파인트\n");
			printf("    2. 쿼터\n");
			printf("    3. 패밀리\n");
			printf("    4. 하프갤런\n");
			printf("-----------------------\n");
			scanf_s("%d", &Handpack_type);
			if (Handpack_type < 1 || Handpack_type>4) {
				printf("1~4번 항목사이에서 골라주세요.\n\n");
				continue;
			}
			break;
		}
		if (Handpack_type == 1) {
			strcpy(icecreamtype_name, "파인트");
			_num = 3;
		}
		else if (Handpack_type == 2) {
			strcpy(icecreamtype_name, "쿼터");
			_num = 4;
		}
		else if (Handpack_type == 3) {
			strcpy(icecreamtype_name, "패밀리");
			_num = 5;
		}
		else {
			strcpy(icecreamtype_name, "하프갤런");
			_num = 6;
		}

		select_Handpack(porder, Icecream_info, icecreamtype_name, _num);
	}
}
void select_ConandCup(Order** porder, IcecreamNode* Icecream_info, char* icecreamtype_name, int num, int count) {

	// 콘/컵에서 아이스크림 선택화면, 사용자가 입력했던 개수만큼 아이스크림 입력

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
			printf("원하는 아이스크림 항목의 번호를 입력하세요.\n");
			print_ic(Icecream_info);
			while (1) {
				printf("=> ");
				scanf_s("%d", &icecream_num);
				name = search_ic_with_num(Icecream_info, icecream_num);
				if (icecream_num < 0 || !name) {
					printf("리스트 안에서 주문해주세요.");
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

	// handpack에서 아이스크림 선택화면

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
		printf("%d개의 맛을 선택하세요.\n", num - i);
		while (1) {
			printf("=> ");
			scanf_s("%d", &icecream_num);
			name = search_ic_with_num(Icecream_info, icecream_num);
			if (icecream_num < 0 || !name) {
				printf("리스트 안에서 주문해주세요.");
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

	// 음료 선택화면, 사용자가 입력했던 개수만큼 음료선택

	int beverage_num;
	char* name = NULL;

	MList* node = (MList*)malloc(sizeof(MList));
	if (!node)
		MemoryError("memory assignment error");

	node->num = 1;
	node->type = 3;
	strcpy(node->icecream[0], "no");
	printf("원하는 음료 항목의 번호를 입력하세요.\n");
	print_bv(beverage_info);
	while (1) {
		printf("=> ");
		scanf_s("%d", &beverage_num);
		name = search_bv_with_num(beverage_info, beverage_num);
		if (beverage_num < 0 || !name) {
			printf("리스트 안에서 주문해주세요.");
			continue;
		}
		break;
	}
	printf("name : %s\n", name);
	strcpy(node->menu_name, name);
	store(porder, node);
}

void Cal(Order* order, InfoHead* InfoHead) {

	// 주문리스트를 가지고 계산 후 사용자에게 현금을 입력받아 거스름돈을 출력하고 종료

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
	//멤버십 여부에 따라 파인트 30% 할인
	printf("KT 멤버십 고객이시라면 파인트를 30%%\ 할인해드립니다. KT 멤버십 고객이신가요?\n");
	membership = getYesorNo();
	if (membership == 1) {
		for (MList* i = order->head; i != NULL; i = i->link) {
			if (!strcmp(i->menu_name, "파인트")) {
				total_price -= 2500;
			}
		}
	}
	while (1) {
		printf("총 가격은 %d 원 입니다. 지불할 액수를 입력해주세요(원) : ", total_price);
		scanf_s("%d", &money);
		change = money - total_price;
		if (change >= 0) {
			printf("거스름돈은 %d 원입니다. 베스킨라빈스를 이용해주셔서 감사합니다!\n", change);
			printf("---------------------------------------------------------------\n");
			saveTxt(InfoHead);
			free(order);
			exit(1);
		}
		else {
			printf("\n금액이 부족합니다. 액수를 다시 입력해 주세요.\n");
			printf("---------------------------------------------------------------\n");
			change = 0;
		}
	}
}

int getYesorNo() {

	// Y 또는 N의 값을 입력받는 함수
	// y/Y : 1, n/N : 2, 실패시 -1
	// return : 1 / 2 / -1

	int key;

	printf("(예 : Y, 아니오 : N) : ");

	while ((key = getch()) != NULL) {
		if (key == 'y' || key == 'Y') {
			puts("Y");
			return 1; // 참을 반환
		}
		else if (key == 'n' || key == 'N') {
			puts("N");
			return 0; // 거짓을 반환
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
	printf("** ^^어서오세요 배스킨라빈스 31입니다^^ **\n");
	printf("===========================================\n");
	printf("\n");
	do
	{
		printf("\n원하시는 번호를 눌러 선택해주세요\n");
		printf("\n");
		printf("0. 종료하기\n");
		printf("1. 아이스크림 정보 열람\n");
		printf("2. 음료 정보 열람\n");
		printf("3. 주문하기\n");
		printf("4. 아이스크림 정보 검색하기\n");
		printf("5. 음료 정보 검색하기\n");
		printf("\n");
		printf("===========================================\n");
		printf("**** 관리자 설정 ****\n");
		printf("===========================================\n");
		printf("6. 아이스크림 메뉴 추가하기\n");
		printf("7. 아이스크림 메뉴 삭제하기\n");
		printf("8. 음료 메뉴 추가하기\n");
		printf("9. 음료 메뉴 삭제하기\n");
		printf("\n");
		printf("원하시는 번호를 입력해주세요\n");
		scanf_s("%d", &input, sizeof(input));

		switch (input)
		{
		case 0:
			printf("감사합니다^^ 종료하겠습니다\n");
			saveTxt(info_head);
			break;

		case 1:
			// 아이스크림 전체 정보 열람
			print_ic(info_head->icecream_link);
			break;

		case 2:
			// 음료 전체 정보 열람 
			print_bv(info_head->beverage_link);
			break;

		case 3:
			Ordering(info_head);
			break;

		case 4:
			// 찾고 싶은 아이스크림 정보 검색   
			getInfoIc = search_ic_with_name(info_head->icecream_link);
			printIcInfo(getInfoIc);
			break;

		case 5:
			// 찾고 싶은 음료 정보 검색   
			getInfoBv = search_bv_with_name(info_head->beverage_link);
			printBvInfo(getInfoBv);
			break;

		case 6:
			// 아이스크림 메뉴 추가  
			printf("** 아이스크림 정보를 추가하겠습니다 **\n");
			info_head->icecream_link = add_icecream_menu(&(info_head->icecream_link));
			printf("\n");
			print_ic(info_head->icecream_link);// ic를 매개변수로 전달해도 상관 없음.  
			break;
		case 7:
			// 아이스크림 메뉴 삭제 함수 
			printf("** 아이스크림 정보를 삭제하겠습니다 **\n");
			print_ic(info_head->icecream_link);
			IcecreamNode* ic_searched = search_ic_with_name(info_head->icecream_link);
			delete_icecream_menu(&info_head->icecream_link, ic_searched);
			printf("\n");
			print_ic(info_head->icecream_link);
			break;

		case 8:
			// 음료 메뉴 추가 함수 
			printf("** 음료 정보를 추가하겠습니다 **\n");
			info_head->beverage_link = add_bv_menu(&info_head->beverage_link);
			printf("\n");
			print_bv(info_head->beverage_link);
			break;

		case 9:
			// 음료 메뉴 삭제 함수 
			printf("** 음료 정보를 삭제하겠습니다 **\n");
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