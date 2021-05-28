#include <stdio.h>
#include <stdbool.h>

int in[2][31][6] = {0, };

int Leap_year(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

void SET()
{
    int year, month, i;
    int start_date=0;
    int sum=365;
    int total_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("년도를 입력하세요(숫자만 입력) : ");
    scanf("%d", &year);
    printf("원하는 달을 입력하세요(숫자만 입력) : ");
    scanf("%d", &month);
    
    if (Leap_year(year))
    {
        total_days[1]++;
    }
    for (i=1; i<year; i++)
    {
        if (Leap_year(i))
            sum += 366;
        else
            sum += 365;
    }
    for (i=0; i<month-1;i++)
    {
        sum += total_days[i];
    }
    start_date = sum % 7;
    printf("\nSUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
 
    printf("===================================================\n");
 
    for (i = 0; i < start_date; i++)
    {
        printf("\t");
    }
 
    for (i = 1; i <= total_days[month - 1]; i++)
    {
 
        printf("%d\t",i);
 
        if (start_date == 6)
        {
            printf("\n");
            start_date = 0;
        }
        else
            start_date++;
    }
    printf("\n");
}

void INPUT()
{
    int day, si, num, cost, go;
    printf("날짜 입력: ");
    scanf("%d", &day);
    printf("지출->0 수입->1 입력: ");
    scanf("%d", &si);
    if (si == 0) {
            printf("1.식비 2.교통비 3.문화비 4.카페비용 5.생필품 6.기타\n지출 카테고리 번호 입력: ");
            scanf("%d", &num);
            printf("지출 금액 입력: ");
            scanf("%d", &cost);
            in[0][day-1][num-1] = cost;
    }
    else {
            printf("수입 금액 입력: ");
            scanf("%d", &cost);
            in[1][day-1][0] = cost;
    }
    printf("입력 종료->0 추가입력->1\n");
    scanf("%d", &go);
    if (go == 1)
        INPUT();
}

void A_WEEK()
{
    int fir, wn;
    printf("1일이 일주일의 몇번째 날입니까? ");
    scanf("%d", &fir);
    printf("확인할 주차를 입력: ");
    scanf("%d", &wn);
    if (wn == 1) {
        for (int i = 0; i <= 7 - fir; i++) {
            printf("%d일: ", i+1);
            for (int j = 0; j <= 5; j++) {
                switch (j)
                {
                    case 0:
                        printf("식비->%d ", in[0][i][j]);
                        break;
                    case 1:
                        printf("교통비->%d ", in[0][i][j]);
                        break;
                    case 2:
                        printf("문화비->%d ", in[0][i][j]);
                        break;
                    case 3:
                        printf("카페비용->%d ", in[0][i][j]);
                        break;
                    case 4:
                        printf("생필품->%d ", in[0][i][j]);
                        break;
                    case 5:
                        printf("기타->%d ", in[0][i][j]);
                        break;
                }
            }
            printf("\n");
            printf("수입->%d ", in[1][i][0]);
            printf("\n");
        }
    }
    else {
            for (int i = 1-fir+(wn-1)*7; i <= 7-fir+(wn-1)*7; i++) {
            printf("%d일: ", i+1);
            for (int j = 0; j <= 5; j++) {
                switch (j)
                {
                    case 0:
                        printf("식비->%d ", in[0][i][j]);
                        break;
                    case 1:
                        printf("교통비->%d ", in[0][i][j]);
                        break;
                    case 2:
                        printf("문화비->%d ", in[0][i][j]);
                        break;
                    case 3:
                        printf("카페비용->%d ", in[0][i][j]);
                        break;
                    case 4:
                        printf("생필품->%d ", in[0][i][j]);
                        break;
                    case 5:
                        printf("기타->%d ", in[0][i][j]);
                        break;
                }
            }
            printf("\n");
            printf("수입->%d ", in[1][i][0]);
            printf("\n");
        }
    }
}

void CATE()
{
    int sum;
    sum = 0;
    for (int j = 0; j <= 5; j++) {
        for (int i = 0; i <= 30; i++) {
            sum = sum + in[0][i][j];
        }
        switch(j)
        {
            case 0:
                printf("식비->%d원 ", sum);
                sum = 0;
                break;
            case 1:
                printf("교통비->%d원 ", sum);
                sum = 0;
                break;
            case 2:
                printf("문화비->%d원 ", sum);
                sum = 0;
                break;
            case 3:
                printf("카페비용->%d원 ", sum);
                sum = 0;
                break;
            case 4:
                printf("생필품->%d원 ", sum);
                sum = 0;
                break;
            case 5:
                printf("기타->%d원 ", sum);
                sum = 0;
                break;
        }
    }
    printf("\n");
}

void ALL()
{
    int si, sum;
    printf("지출->0 수입->1 입력: ");
    scanf("%d", &si);
    if (si == 0) {
        sum = 0;
        for (int i = 0; i <= 30; i++) {
            for (int j = 0; j <= 5; j++) {
                sum += in[0][i][j];
            }
        }
        printf("총 지출은 %d원입니다.\n", sum);
    }
    else {
        sum = 0;
        for (int i = 0; i <= 30; i++) {
            sum += in[1][i][0];
        }
        printf("총 수입은 %d원입니다.\n", sum);
    }
}

void A_DAY()
{
    int day;
    printf("확인할 날짜 입력: ");
    scanf("%d", &day);
    printf("지출: ");
    for (int i = 0; i <= 5; i++) {
        switch(i)
        {
            case 0:
                printf("식비->%d원 ", in[0][day-1][i]);
                break;
            case 1:
                printf("교통비->%d원 ", in[0][day-1][i]);
                break;
            case 2:
                printf("문화비->%d원 ", in[0][day-1][i]);
                break;
            case 3:
                printf("카페비용->%d원 ", in[0][day-1][i]);
                break;
            case 4:
                printf("생필품->%d원 ", in[0][day-1][i]);
                break;
            case 5:
                printf("기타->%d원 ", in[0][day-1][i]);
                break;
        }
    }
    printf("\n");
    printf("수입: %d원", in[1][day-1][0]);
    printf("\n");
}

int main(void)
{
    int mode;
    
    while (1) {
        printf("0. 가계부 내용 입력\n1. 달력 출력\n2. 1주일 단위 내역 확인\n3. 지출 카테고리 확인\n4. 총 수입/지출 확인\n5. 일일 내역 확인\n6. 종료\n");
        scanf("%d", &mode);
        switch (mode)
        {
            case 0:
                INPUT();
                break;
            case 1:
                SET();
                break;
            case 2:
                A_WEEK();
                break;
            case 3:
                CATE();
                break;
            case 4:
                ALL();
                break;
            case 5:
                A_DAY();
                break;
            case 6:
                return 0;
        }
    }
}
