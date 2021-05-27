#include"stream.h"
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

void printIcInfo(IcecreamNode* head){

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

void printBvInfo(BeverageNode* head){

	// ���� ���� �ϳ� ���

	BeverageNode* curr = head;
	printf(" ��ȣ           �̸�            ������   kcal      ����  ��ȣ��\n");
	printf("%3d�� %25s %4dg %5dkcal %6d�� %3d��\n", curr->bv_num, curr->bvtype, curr->bvserving, curr->kcal, curr->bvprice, curr->prefer);
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
		IcecreamNode* p = phead;

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
	} while (strcmp(p->name, n) != 0 || p == NULL);

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
		BeverageNode* p = phead;

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
	} while (p == NULL || (strcmp(p->bvtype, n) != 0));

	return p; // �˻��� ������ �̸��� ���� ��� �ּҰ� ��ȯ
}
