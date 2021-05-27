#pragma once
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