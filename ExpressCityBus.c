#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_PASSENGER 30

typedef struct ExpressCityBus
{
	int seatNum;
	double temperature;
	char passenger[20];
	struct ExpressCityBus* link;
} ExpressCityBus;

typedef struct
{
	int seatNum;
	char checkSeat;
} ExpressCityBusShape;

typedef struct
{
	int seatNum;
	double temperature;
	char passenger[20];
	int time[3];
} PassengerInformation;

int busPassenger = 0;
int boardingOrder = 0;

ExpressCityBus* InsertFirst(ExpressCityBus* head, int seatNum, double temperature, char* passenger);
ExpressCityBus* InsertBetween(ExpressCityBus* head, ExpressCityBus* before, int seatNum, double temperature, char* passenger);
ExpressCityBus* InsertLast(ExpressCityBus* head, int seatNum, double temperature, char* passenger);
ExpressCityBus* GetBeforeLink(ExpressCityBus* head, int beforeSeatNum);
ExpressCityBus* DeleteFirst(ExpressCityBus* head, int seatNum);
ExpressCityBus* DeleteBetween(ExpressCityBus* head, int seatNum);
ExpressCityBus* DeleteLast(ExpressCityBus* head, int seatNum);
void SearchPassenger(ExpressCityBus* head, char* passenger);
void PrintAllPassenger(ExpressCityBus* head);
int CurrentMaxSeatNum(ExpressCityBus* head);
int GetBeforeSeatNum(ExpressCityBus* head, int seatNum);
int CheckSeatNum(ExpressCityBus* head, int seatNum);
int MinSeatNum(ExpressCityBus* head, int seatNum);
int MaxSeatNum(ExpressCityBus* head, int seatNum);
void PrintExpressCityBus(ExpressCityBus* head);
void PrintExpressCityBusShape(ExpressCityBus* head);
void ExpressCityBusMenu(void);
void Event(void);
void BoardingTime(PassengerInformation** information, int seatNum, double temperature, char* passenger);

int main(void)
{
	ExpressCityBus* head = NULL;
	ExpressCityBus* before = NULL;
	PassengerInformation* pInformation = (PassengerInformation*)malloc(sizeof(PassengerInformation));
	if (pInformation == NULL)
	{
		fprintf(stderr, "메모리가 부족해서 할당이 불가합니다.\n");
		exit(1);
	}
	FILE* ofp;
	int choice;
	int seatNum;
	double temperature;
	char passenger[20];
	int maxNum;
	int beforeSeatNum;
	int checkSeatNum;
	int today[3];
	time_t now = time(NULL);
	struct tm* nowtime = localtime(&now);

	today[0] = nowtime->tm_year + 1900;
	today[1] = nowtime->tm_mon + 1;
	today[2] = nowtime->tm_mday;

	printf("<%d년 %d월 %d일> 좌석 버스 운행 시작합니다.\n", today[0], today[1], today[2]);
	while (1)
	{
		ExpressCityBusMenu();
		scanf("%d", &choice);
		if (choice == 5)
		{
			printf("\n<%d년 %d월 %d일> 좌석 버스 운행을 종료합니다. 이용해주셔서 감사합니다.^^*\n", today[0], today[1], today[2]);
			break;
		}

		switch (choice)
		{
		case 1:
			PrintExpressCityBusShape(head);
			if (busPassenger == MAX_PASSENGER)
			{
				printf(">>> 좌석 버스가 만석입니다.\n");
			}
			else
			{
				printf(">>> 탑승하실 좌석, 탑승객 이름, 체온을 입력하세요 : ");
				scanf("%d%s%lf", &seatNum, passenger, &temperature);
				checkSeatNum = CheckSeatNum(head, seatNum);
				if (checkSeatNum == 1)
				{
					printf(">>> 해당 좌석은 다른 승객이 탑승해있습니다.\n");
				}
				else if (temperature >= 35.9 && temperature < 37.5)
				{
					if (seatNum < 1 || seatNum > 30)
					{
						printf(">>> 좌석을 잘못 입력하셨습니다.\n");
					}
					else
					{
						BoardingTime(&pInformation, seatNum, temperature, passenger);
						if (seatNum == 1 || head == NULL)
						{
							head = InsertFirst(head, seatNum, temperature, passenger);
						}
						else
						{
							maxNum = CurrentMaxSeatNum(head);
							if (maxNum < seatNum)
							{
								head = InsertLast(head, seatNum, temperature, passenger);
							}
							else
							{
								beforeSeatNum = GetBeforeSeatNum(head, seatNum);
								before = GetBeforeLink(head, beforeSeatNum);
								if (beforeSeatNum > seatNum)
								{
									head = InsertFirst(head, seatNum, temperature, passenger);
								}
								else
								{
									head = InsertBetween(head, before, seatNum, temperature, passenger);
								}
							}
						}
						PrintExpressCityBusShape(head);
						PrintExpressCityBus(head);
					}
				}
				else
				{
					printf(">>> 정상 체온을 벗어났습니다. 좌석버스 탑승이 불가합니다.\n");
				}
			}
			break;
		case 2:
			PrintExpressCityBusShape(head);
			if (busPassenger == 0)
			{
				printf(">>> 하차할 승객이 없습니다.\n");
			}
			else
			{
				printf(">>> 하차할 좌석 번호를 입력하세요 : ");
				scanf("%d", &seatNum);
				checkSeatNum = CheckSeatNum(head, seatNum);
				int minSeatNum = MinSeatNum(head, seatNum);
				int maxSeatNum = MaxSeatNum(head, seatNum);

				if (checkSeatNum == 0)
				{
					printf(">>> 비어있는 좌석입니다.\n");
				}
				else
				{
					if (minSeatNum == seatNum)
					{
						head = DeleteFirst(head, seatNum);
					}
					else if (maxSeatNum == seatNum)
					{
						head = DeleteLast(head, seatNum);
					}
					else
					{
						head = DeleteBetween(head, seatNum);
					}

					PrintExpressCityBusShape(head);
					if (head != NULL)
					{
						PrintExpressCityBus(head);
					}
					else
					{
						printf(">>> 모든 승객이 하차하였습니다.\n");
					}
				}
			}
			break;
		case 3:
			if (busPassenger == 0)
			{
				printf(">>> 탑승객이 없습니다.\n");
			}
			else {
				printf("\n>>> 조회하고 싶은 승객 이름을 입력하세요 : ");
				scanf("%s", passenger);
				SearchPassenger(head, passenger);
			}
			break;
		case 4:
			if (busPassenger == 0)
			{
				printf(">>> 탑승객이 없습니다.\n");
			}
			else PrintAllPassenger(head);
			break;
		default:
			printf("잘못 입력하셨습니다.\n");
			break;
		}
		printf("\n");
	}

	ofp = fopen("BusVisitingList.txt", "w");
	if (ofp == NULL)
	{
		fprintf(stderr, "출력 파일을 열지 못했습니다.\n");
		exit(1);
	}
	for (int i = 0; i < boardingOrder; i++)
	{
		if (i == 0) fprintf(ofp, "<%d년 %d월 %d일> 좌석 버스 운행 시작\n", today[0], today[1], today[2]);
		fprintf(ofp, "%02d. [좌석:%3d 승객:%6s 체온:%3.1lf] %d년 %d월 %d일 %02d:%02d:%02d [탑승]\n",
			i + 1, pInformation[i].seatNum, pInformation[i].passenger, pInformation[i].temperature, today[0],
			today[1], today[2], (pInformation[i].time[0]), (pInformation[i].time[1]), (pInformation[i].time[2]));
		if (i == boardingOrder - 1) fprintf(ofp, "<%d년 %d월 %d일> 좌석 버스 운행 종료\n", today[0], today[1], today[2]);
	}

	fclose(ofp);
	free(pInformation);
	return 0;
}

ExpressCityBus* InsertFirst(ExpressCityBus* head, int seatNum, double temperature, char* passenger)
{
	ExpressCityBus* newPassenger = (ExpressCityBus*)malloc(sizeof(ExpressCityBus));
	if (newPassenger == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}

	newPassenger->seatNum = seatNum;
	newPassenger->temperature = temperature;
	strcpy(newPassenger->passenger, passenger);
	if (head == NULL)
	{
		newPassenger->link = newPassenger;
		head = newPassenger;
	}
	else
	{
		newPassenger->link = head->link;
		head->link = newPassenger;
	}
	busPassenger++;

	return head;
}

ExpressCityBus* InsertBetween(ExpressCityBus* head, ExpressCityBus* before, int seatNum, double temperature, char* passenger)
{
	ExpressCityBus* newPassenger = (ExpressCityBus*)malloc(sizeof(ExpressCityBus));
	if (newPassenger == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}

	newPassenger->seatNum = seatNum;
	newPassenger->temperature = temperature;
	strcpy(newPassenger->passenger, passenger);
	newPassenger->link = before->link;
	before->link = newPassenger;
	busPassenger++;

	return head;
}

ExpressCityBus* InsertLast(ExpressCityBus* head, int seatNum, double temperature, char* passenger)
{
	ExpressCityBus* newPassenger = (ExpressCityBus*)malloc(sizeof(ExpressCityBus));
	if (newPassenger == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}

	newPassenger->seatNum = seatNum;
	newPassenger->temperature = temperature;
	strcpy(newPassenger->passenger, passenger);
	if (head == NULL)
	{
		head = newPassenger;
		newPassenger->link = head;
	}
	else
	{
		newPassenger->link = head->link;
		head->link = newPassenger;
		head = newPassenger;
	}
	busPassenger++;

	return head;
}

ExpressCityBus* GetBeforeLink(ExpressCityBus* head, int beforeSeatNum)
{
	ExpressCityBus* before = NULL;
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		before = i;
		if (beforeSeatNum == i->seatNum) break;
	}

	return before;
}

ExpressCityBus* DeleteFirst(ExpressCityBus* head, int seatNum)
{
	ExpressCityBus* removed = NULL;
	if (head == NULL) return NULL;
	removed = head->link;
	if (removed->seatNum == seatNum)
	{
		head->link = removed->link;
	}
	busPassenger--;
	if (removed == head)
	{
		free(removed);
		return NULL;
	}
	free(removed);
	return head;
}

ExpressCityBus* DeleteBetween(ExpressCityBus* head, int seatNum)
{
	ExpressCityBus* before = NULL;
	ExpressCityBus* removed;
	if (head == NULL) return NULL;
	for (removed = head->link; removed != head; removed = removed->link)
	{
		if (removed->seatNum == seatNum) break;
		before = removed;
	}
	before->link = removed->link;
	busPassenger--;

	free(removed);
	return head;
}

ExpressCityBus* DeleteLast(ExpressCityBus* head, int seatNum)
{
	ExpressCityBus* before = NULL;
	ExpressCityBus* removed;
	if (head == NULL) return NULL;
	for (removed = head->link; removed != head; removed = removed->link)
	{
		if (seatNum == removed->seatNum) break;
		before = removed;
	}
	removed = head;

	before->link = removed->link;
	head = before;
	busPassenger--;

	free(removed);
	return head;
}

void SearchPassenger(ExpressCityBus* head, char* passenger)
{
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		if (strcmp(i->passenger, passenger) == 0)
		{
			printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
			return;
		}
	}
	if (strcmp(i->passenger, passenger) == 0)
	{
		printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
		return;
	}
	printf("해당 승객은 없습니다.\n");
}

void PrintAllPassenger(ExpressCityBus* head)
{
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
	}
	printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
}

int CurrentMaxSeatNum(ExpressCityBus* head)
{
	ExpressCityBus* i;
	int maxNum = 0;
	maxNum = head->link->seatNum;
	for (i = head->link->link; i != head; i = i->link)
	{
		if (maxNum < i->seatNum)
		{
			maxNum = i->seatNum;
		}
	}
	if (maxNum < i->seatNum)
	{
		maxNum = i->seatNum;
	}
	return maxNum;
}

int GetBeforeSeatNum(ExpressCityBus* head, int seatNum)
{
	int beforeSeatNum = head->link->seatNum;
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		if (seatNum < i->seatNum) break;
		beforeSeatNum = i->seatNum;
	}
	return beforeSeatNum;
}

int CheckSeatNum(ExpressCityBus* head, int seatNum)
{
	ExpressCityBus* i;
	if (head == NULL) return 0;
	for (i = head->link; i != head; i = i->link)
	{
		if (i->seatNum == seatNum) return 1;
	}
	if (i->seatNum == seatNum) return 1;
	return 0;
}

int MinSeatNum(ExpressCityBus* head, int seatNum)
{
	int minSeat = seatNum;
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		if (minSeat > i->seatNum)
		{
			minSeat = i->seatNum;
		}
	}
	if (minSeat > i->seatNum)
	{
		minSeat = i->seatNum;
	}
	return minSeat;
}

int MaxSeatNum(ExpressCityBus* head, int seatNum)
{
	int maxSeat = seatNum;
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		if (maxSeat < i->seatNum)
		{
			maxSeat = i->seatNum;
		}
	}
	if (maxSeat < i->seatNum)
	{
		maxSeat = i->seatNum;
	}
	return maxSeat;
}

void PrintExpressCityBus(ExpressCityBus* head)
{
	ExpressCityBus* i;
	int count = 0;
	for (i = head->link; i != head; i = i->link)
	{
		printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf] -> ", i->seatNum, i->passenger, i->temperature);
		count++;
		if (count % 2 == 0) printf("\n");
	}
	printf("[좌석:%3d, 탑승객:%7s, 체온:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
}

void PrintExpressCityBusShape(ExpressCityBus* head)
{
	ExpressCityBus* i;
	int j = 1;
	int k = 1;
	int l = 1;
	int m = 1;
	int n = 1;

	if (head == NULL)
	{
		printf("\n=====================================\n");
		printf("| 운전석 |\n\n");
		for (int a = 1; a <= 28; a += 4)
		{
			printf("|  %2d  ||  %2d  |     |  %2d  ||  %2d  |\n", a, a + 1, a + 2, a + 3);
			printf("|      ||      |     |      ||      |\n\n");
		}
		printf("|  29  ||  30  |\n");
		printf("|      ||      |");
		printf("\n=====================================\n\n");
		Event();
		return;
	}
	i = head->link;
	printf("\n=====================================\n");
	printf("| 운전석 |\n\n");
	while (j <= 28)
	{
		n = 1;
		for (j = k; j <= k + 3; j++)
		{
			printf("|  %2d  |", j);
			if (n == 2)
			{
				printf("     ");
			}
			n++;
		}
		n = 1;
		printf("\n");
		for (m = 1; m <= 4; m++)
		{
			if (l != i->seatNum)
			{
				printf("|      |");
				l++;
				if (n == 2)
				{
					printf("     ");
				}
				n++;
				continue;
			}
			printf("|%6s|", i->passenger);
			l++;
			i = i->link;
			if (n == 2)
			{
				printf("     ");
			}
			n++;
		}
		printf("\n\n");
		k += 4;
	}

	for (j = k; j <= k + 1; j++)
	{
		printf("|  %2d  |", j);
	}
	printf("\n");
	for (m = 1; m <= 2; m++)
	{
		if (l != i->seatNum)
		{
			printf("|      |");
			l++;
			continue;
		}
		printf("|%6s|", i->passenger);
		l++;
		i = i->link;
	}
	printf("\n=====================================\n\n");
	Event();
}

void ExpressCityBusMenu(void)
{
	printf(" ============================================\n");
	printf("│         좌석버스 이용 프로그램            │\n");
	printf(" ============================================\n");
	printf("│      1. 탑승(Boarding)                    │\n");
	printf("│      2. 하차(Get off)                     │\n");
	printf("│      3. 탑승객 조회(Search)               │\n");
	printf("│      4. 전체 탑승객 조회(All search)      │\n");
	printf("│      5. 운행 종료(Shutdown)               │\n");
	printf(" ============================================\n\n");
	printf(">>> 이용하실 번호를 입력해주세요: ");
}

void Event(void)
{
	char* degreeOfCongestion;
	int remainingSeats = MAX_PASSENGER - busPassenger;
	if (remainingSeats <= MAX_PASSENGER && remainingSeats > 20)
	{
		degreeOfCongestion = "여유";
	}
	else if (remainingSeats <= 20 && remainingSeats > 8)
	{
		degreeOfCongestion = "보통";
	}
	else if (remainingSeats <= 8 && remainingSeats > 0)
	{
		degreeOfCongestion = "혼잡";
	}
	else degreeOfCongestion = "만석";

	printf("==================\n");
	printf(" 남은 좌석 : %d\n", MAX_PASSENGER - busPassenger);
	printf(" 버스 혼잡도 : %s\n", degreeOfCongestion);
	printf("==================\n\n");
}

void BoardingTime(PassengerInformation** information, int seatNum, double temperature, char* passenger)
{
	time_t now = time(NULL);
	struct tm* nowtime = localtime(&now);
	*information = (PassengerInformation*)realloc(*information, sizeof(PassengerInformation) * (boardingOrder + 1));
	if (*information == NULL)
	{
		fprintf(stderr, "메모리가 부족해서 할당이 불가합니다.\n");
		exit(1);
	}
	(*information)[boardingOrder].seatNum = seatNum;
	strcpy((*information)[boardingOrder].passenger, passenger);
	(*information)[boardingOrder].temperature = temperature;
	((*information)[boardingOrder].time[0]) = nowtime->tm_hour;
	((*information)[boardingOrder].time[1]) = nowtime->tm_min;
	((*information)[boardingOrder].time[2]) = nowtime->tm_sec;
	boardingOrder++;
}