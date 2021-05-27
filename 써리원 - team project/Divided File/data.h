#pragma once
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