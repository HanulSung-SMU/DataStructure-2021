#include"stream.h"
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
		//printf(" %d %s %d %d\n", newnode->hp_num, newnode->htype, newnode->hserving, newnode->hprice);
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

void printIcInfo(IcecreamNode* head){

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

void printBvInfo(BeverageNode* head){

	// 음료 정보 하나 출력

	BeverageNode* curr = head;
	printf(" 번호           이름            제공량   kcal      가격  선호도\n");
	printf("%3d번 %25s %4dg %5dkcal %6d원 %3d번\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
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
		IcecreamNode* p = phead;

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
	} while (strcmp(p->name, n) != 0 || p == NULL);

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
		BeverageNode* p = phead;

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
	} while (p == NULL || (strcmp(p->bvtype, n) != 0));

	return p; // 검색할 음료의 이름을 가진 노드 주소값 반환
}
