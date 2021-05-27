#include"menu_modify.h"
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

BeverageNode* add_bv_menu(BeverageNode** phead){

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

void delete_bv_menu(BeverageNode** phead, BeverageNode* remove){

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