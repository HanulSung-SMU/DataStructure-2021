#include"stream.h"
#include"menu_modify.h"
#include"order.h"
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
		scanf_s("%d", &input,sizeof(input));

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