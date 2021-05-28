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
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �Ұ��մϴ�.\n");
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

	printf("<%d�� %d�� %d��> �¼� ���� ���� �����մϴ�.\n", today[0], today[1], today[2]);
	while (1)
	{
		ExpressCityBusMenu();
		scanf("%d", &choice);
		if (choice == 5)
		{
			printf("\n<%d�� %d�� %d��> �¼� ���� ������ �����մϴ�. �̿����ּż� �����մϴ�.^^*\n", today[0], today[1], today[2]);
			break;
		}

		switch (choice)
		{
		case 1:
			PrintExpressCityBusShape(head);
			if (busPassenger == MAX_PASSENGER)
			{
				printf(">>> �¼� ������ �����Դϴ�.\n");
			}
			else
			{
				printf(">>> ž���Ͻ� �¼�, ž�°� �̸�, ü���� �Է��ϼ��� : ");
				scanf("%d%s%lf", &seatNum, passenger, &temperature);
				checkSeatNum = CheckSeatNum(head, seatNum);
				if (checkSeatNum == 1)
				{
					printf(">>> �ش� �¼��� �ٸ� �°��� ž�����ֽ��ϴ�.\n");
				}
				else if (temperature >= 35.9 && temperature < 37.5)
				{
					if (seatNum < 1 || seatNum > 30)
					{
						printf(">>> �¼��� �߸� �Է��ϼ̽��ϴ�.\n");
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
					printf(">>> ���� ü���� ������ϴ�. �¼����� ž���� �Ұ��մϴ�.\n");
				}
			}
			break;
		case 2:
			PrintExpressCityBusShape(head);
			if (busPassenger == 0)
			{
				printf(">>> ������ �°��� �����ϴ�.\n");
			}
			else
			{
				printf(">>> ������ �¼� ��ȣ�� �Է��ϼ��� : ");
				scanf("%d", &seatNum);
				checkSeatNum = CheckSeatNum(head, seatNum);
				int minSeatNum = MinSeatNum(head, seatNum);
				int maxSeatNum = MaxSeatNum(head, seatNum);

				if (checkSeatNum == 0)
				{
					printf(">>> ����ִ� �¼��Դϴ�.\n");
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
						printf(">>> ��� �°��� �����Ͽ����ϴ�.\n");
					}
				}
			}
			break;
		case 3:
			if (busPassenger == 0)
			{
				printf(">>> ž�°��� �����ϴ�.\n");
			}
			else {
				printf("\n>>> ��ȸ�ϰ� ���� �°� �̸��� �Է��ϼ��� : ");
				scanf("%s", passenger);
				SearchPassenger(head, passenger);
			}
			break;
		case 4:
			if (busPassenger == 0)
			{
				printf(">>> ž�°��� �����ϴ�.\n");
			}
			else PrintAllPassenger(head);
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
		printf("\n");
	}

	ofp = fopen("BusVisitingList.txt", "w");
	if (ofp == NULL)
	{
		fprintf(stderr, "��� ������ ���� ���߽��ϴ�.\n");
		exit(1);
	}
	for (int i = 0; i < boardingOrder; i++)
	{
		if (i == 0) fprintf(ofp, "<%d�� %d�� %d��> �¼� ���� ���� ����\n", today[0], today[1], today[2]);
		fprintf(ofp, "%02d. [�¼�:%3d �°�:%6s ü��:%3.1lf] %d�� %d�� %d�� %02d:%02d:%02d [ž��]\n",
			i + 1, pInformation[i].seatNum, pInformation[i].passenger, pInformation[i].temperature, today[0],
			today[1], today[2], (pInformation[i].time[0]), (pInformation[i].time[1]), (pInformation[i].time[2]));
		if (i == boardingOrder - 1) fprintf(ofp, "<%d�� %d�� %d��> �¼� ���� ���� ����\n", today[0], today[1], today[2]);
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
		fprintf(stderr, "�޸𸮰� �����մϴ�.\n");
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
		fprintf(stderr, "�޸𸮰� �����մϴ�.\n");
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
		fprintf(stderr, "�޸𸮰� �����մϴ�.\n");
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
			printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
			return;
		}
	}
	if (strcmp(i->passenger, passenger) == 0)
	{
		printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
		return;
	}
	printf("�ش� �°��� �����ϴ�.\n");
}

void PrintAllPassenger(ExpressCityBus* head)
{
	ExpressCityBus* i;
	for (i = head->link; i != head; i = i->link)
	{
		printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
	}
	printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
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
		printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf] -> ", i->seatNum, i->passenger, i->temperature);
		count++;
		if (count % 2 == 0) printf("\n");
	}
	printf("[�¼�:%3d, ž�°�:%7s, ü��:%5.1lf]\n", i->seatNum, i->passenger, i->temperature);
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
		printf("| ������ |\n\n");
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
	printf("| ������ |\n\n");
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
	printf("��         �¼����� �̿� ���α׷�            ��\n");
	printf(" ============================================\n");
	printf("��      1. ž��(Boarding)                    ��\n");
	printf("��      2. ����(Get off)                     ��\n");
	printf("��      3. ž�°� ��ȸ(Search)               ��\n");
	printf("��      4. ��ü ž�°� ��ȸ(All search)      ��\n");
	printf("��      5. ���� ����(Shutdown)               ��\n");
	printf(" ============================================\n\n");
	printf(">>> �̿��Ͻ� ��ȣ�� �Է����ּ���: ");
}

void Event(void)
{
	char* degreeOfCongestion;
	int remainingSeats = MAX_PASSENGER - busPassenger;
	if (remainingSeats <= MAX_PASSENGER && remainingSeats > 20)
	{
		degreeOfCongestion = "����";
	}
	else if (remainingSeats <= 20 && remainingSeats > 8)
	{
		degreeOfCongestion = "����";
	}
	else if (remainingSeats <= 8 && remainingSeats > 0)
	{
		degreeOfCongestion = "ȥ��";
	}
	else degreeOfCongestion = "����";

	printf("==================\n");
	printf(" ���� �¼� : %d\n", MAX_PASSENGER - busPassenger);
	printf(" ���� ȥ�⵵ : %s\n", degreeOfCongestion);
	printf("==================\n\n");
}

void BoardingTime(PassengerInformation** information, int seatNum, double temperature, char* passenger)
{
	time_t now = time(NULL);
	struct tm* nowtime = localtime(&now);
	*information = (PassengerInformation*)realloc(*information, sizeof(PassengerInformation) * (boardingOrder + 1));
	if (*information == NULL)
	{
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �Ұ��մϴ�.\n");
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