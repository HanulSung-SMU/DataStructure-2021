#include"order.h"
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
			printf("1~2번 항목사이에서 골라주세요.\n");
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
		else if(Con_type == 2){
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
	strcpy(node->menu_name, name);
	store(porder, node);
}

void Cal(Order* order, InfoHead* InfoHead){

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
					total_price +=  j->bvprice;
					break;
				}
			}
		}
	}
	//멤버십 여부에 따라 파인트 30% 할인
	printf("total price is %d\n", total_price);
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

int getYesorNo(){

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