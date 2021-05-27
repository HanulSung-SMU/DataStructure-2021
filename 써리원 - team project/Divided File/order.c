#include"order.h"
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
			printf("1~2�� �׸���̿��� ����ּ���.\n");
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
		else if(Con_type == 2){
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
	strcpy(node->menu_name, name);
	store(porder, node);
}

void Cal(Order* order, InfoHead* InfoHead){

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
					total_price +=  j->bvprice;
					break;
				}
			}
		}
	}
	//����� ���ο� ���� ����Ʈ 30% ����
	printf("total price is %d\n", total_price);
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

int getYesorNo(){

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