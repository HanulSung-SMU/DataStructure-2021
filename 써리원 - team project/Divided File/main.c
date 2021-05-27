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
		scanf_s("%d", &input,sizeof(input));

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