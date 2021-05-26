#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item {
    const char* name;
    int price;
    int quantity;
}item;

typedef struct list {
    item* itemlist;
    int top;
    int maxcapacity;
}list;

typedef struct shop {
    const char* name;
    list itemlist;
}shop;

typedef struct level {
    const char* name;
    int level;
    shop* shoplist;
}level;

typedef struct user {
    int cash;
    list inventory;
    list checklist;
    int level;
}user;

void createitem(item* i, const char* name, int price, int qtt) {
    i->name = name;
    i->price = price;
    i->quantity = qtt;
}

void createlist(list* l, int maxcapacity) {
    l->top = 0;
    l->maxcapacity = maxcapacity;
    l->itemlist = (item*)malloc(sizeof(item) * maxcapacity);
}

int islistfull(list* l) {
    if (l->top == l->maxcapacity) {
        //printf("장바구니가 가득찼습니다.\n");
        return 1;
    }
    else
        return 0;
}

int islistempty(list* l) {
    if (l->top == 0) {
        //printf("더 이상 뺄 것이 없습니다. \n");
        return 1;
    }
    else
        return 0;
}

void pushlist(list* l, item* i, int qtt) {
    if (islistfull(l) == 1) {
        printf("장바구니가 가득찼습니다.\n");
        return;
    }
    if (i->quantity - qtt < 0) {
        printf("재고가 없습니다\n");
        return;
    }


    for (int j = 0; j < l->top; j++) {
        if (l->itemlist[j].name == i->name) {
            l->itemlist[j].quantity += qtt;
            i->quantity -= qtt;
            return;
        } // 중복 아이템의 경우

    }l->itemlist[l->top].name = i->name;
    l->itemlist[l->top].price = i->price;
    l->itemlist[l->top].quantity = qtt;
    i->quantity -= qtt;
    l->top++;

}

void poplist(list* l) {
    if (islistempty(l) == 1) {
        return;
    }
    else
        l->top--;
}

void createshop(shop* s, const char* n, list l) {
    s->name = n;
    s->itemlist = l;
}

void createlevel(level* l, int level, const char* n, shop* slist) {
    l->name = n;
    l->level = level;
    l->shoplist = slist;
}

void createuser(user* u, int money, list inventory, list checklist) {
    u->cash = money;
    u->checklist = checklist;
    u->inventory = inventory;
    u->level = 1;
}

void print_() {
    for (int i = 0; i < 50; i++)
        printf("_");
    printf("\n");
}

void printlist(list l) {
    for (int i = 0; i < l.top; i++) {
        printf("   -%d. %s         가격: %d          수량: %d\n", i + 1, l.itemlist[i].name, l.itemlist[i].price, l.itemlist[i].quantity);
    }
    printf("\n");
}

void printshop(level l) {
    printf("내 위치   %d 층: %s\n", l.level, l.name);
    for (int i = 0; i < sizeof(l.shoplist) - 1; i++) {
        printf("%d. %s      ", i + 1, l.shoplist[i]);
    }
    printf("\n");
    print_();
}

void elevator(user* u) {
    int level;
    print_();
    printf("엘레베이터를 이용합니다.\n");
    printf("현재 층: %d\n", u->level);
    printf("몇 층으로 가시겠습니까?1. 1층      2. 2층      3. 3층 1\->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%d", &level);
    print_();
    if (level > 3) {
        printf("존재하지 않는 층입니다.\n다시 선택해주세요.\n");
        return;
    }
    printf("%d층으로 이동합니다...\n", level);
    u->level = level;
    printf("%d층으로 이동했습니다\n", level);
}

void escalator(user* u) {
    print_();
    printf("에스컬레이터를 이용합니다.\n");
    printf("현재 층: %d\n", u->level);
    int up;
    if (u->level == 1) {
        printf("2층으로 올라갑니다...\n");
        u->level++;
        printf("%d층으로 이동했습니다\n", u->level);
    }
    else if (u->level == 2) {
        printf("1. 올라간다      2. 내려간다\n->");
        fseek(stdin, 0, SEEK_END);
        scanf_s("%d", &up);
        if (up == 1) {
            printf("3층으로 올라갑니다...\n");
            u->level++;
            printf("%d층으로 이동했습니다\n", u->level);
        }
        else {
            printf("1층으로 내려갑니다...\n");
            u->level--;
            printf("%d층으로 이동했습니다\n", u->level);
        }
    }
    else {
        printf("2층으로 내려갑니다...\n");
        u->level--;
        printf("%d층으로 이동했습니다\n", u->level);
    }
}

int move() {
    int m = 0;
    printf("1. 1번 매장 가기   2. 2번 매장 가기   3. 3번 매장 가기      4. 에스컬레이터");
    printf("\n5. 엘레베이터      6. 장바구니 확인   7. 체크리스트 확인      8. 계산하기 ");
    printf("\n->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%d", &m);
    return m;
}

void selector(shop* s, user* u) {
    int selector;
    int qtt;

    printf("%s 가는 중...\n...\n...\n도착!\n", s->name);
    printf("%s 에는,,,\n", s->name);
    printlist(s->itemlist);
    printf("가 있다! 뭘 담을까?\n->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%d", &selector);
    selector--;
    printf("몇 개를 담을까?\n->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%d", &qtt);
    pushlist(&u->inventory, &s->itemlist.itemlist[selector], qtt);
}

int compare(list* list1, list* list2) {
    for (int i = list1->top - 1; i > -1; i--) {
        for (int j = list2->top - 1; j > -1; j--) {
            if (list1->itemlist[i].name == list2->itemlist[j].name) {
                if (list1->itemlist[i].quantity - list2->itemlist[j].quantity < 1) {
                    for (int k = i; k < list1->top - 1; k++) {
                        list1->itemlist[k].name = list1->itemlist[k + 1].name;
                        list1->itemlist[k].price = list1->itemlist[k + 1].price;
                        list1->itemlist[k].quantity = list1->itemlist[k + 1].quantity;
                    }
                    poplist(list1);
                }
                else
                    list1->itemlist[i].quantity -= list2->itemlist[j].quantity;
            }
        }
    }
    if (list1->top == 0) {
        return 1; //성공
    }
    else return 0; //실패
}

void counter(user* u) {
    int total = 0;
    int change = 0;
    int result = 0;

    for (int i = 0; i < u->inventory.top; i++) {
        total += u->inventory.itemlist[i].price * u->inventory.itemlist[i].quantity;
    }
    change = u->cash - total;

    result = compare(&u->checklist, &u->inventory);

    printf("바코드 찍는 중..\n");
    printlist(u->inventory);
    print_();
    printf("            total: %d\n", total);
    if (change < 0) {
        printf("잔액이 부족합니다.\n");
    }
    if (result == 0) {
        printf("구매하지 않은 물품이 있습니다!\n");
        print_();
        printf("구매하지 않은 물품: \n");
        printlist(u->checklist);
        print_();
        printf("쇼핑에 실패하였습니다!\n");
    }
    if (change >= 0 && result == 1)
        printf("쇼핑에 성공하였습니다!\n 즐거운 쇼핑이었어!\n");
}

int main() {
    item i111, i112, i113, i121, i122, i123, i131, i132, i133;
    item i211, i212, i213, i221, i222, i223, i231, i232, i233;
    item i311, i312, i313, i321, i322, i323, i331, i332, i333;

    list l11, l12, l13;
    list l21, l22, l23;
    list l31, l32, l33;

    list checklist, inventory;

    shop s11, s12, s13;
    shop s21, s22, s23;
    shop s31, s32, s33;

    level l1, l2, l3;

    user u;

    int money, input, random, r1, r2;
    int exit = 0;

    char c;

    createitem(&i111, "닭고기", 30000, 100);
    createitem(&i112, "소고기", 10000, 100);
    createitem(&i113, "돼지고기", 20000, 100);

    createitem(&i121, "양파", 10000, 100);
    createitem(&i122, "마늘", 10000, 100);
    createitem(&i123, "왕감자", 5000, 100);

    createitem(&i131, "우유", 50000, 100);
    createitem(&i132, "요거트", 30000, 100);
    createitem(&i133, "치즈", 40000, 100);

    createlist(&l11, 5);
    createlist(&l12, 5);
    createlist(&l13, 5);

    pushlist(&l11, &i111, 5);
    pushlist(&l11, &i112, 5);
    pushlist(&l11, &i113, 5);

    pushlist(&l12, &i121, 5);
    pushlist(&l12, &i122, 5);
    pushlist(&l12, &i123, 5);

    pushlist(&l13, &i131, 5);
    pushlist(&l13, &i132, 5);
    pushlist(&l13, &i133, 5);

    createshop(&s11, "정육 코너", l11);
    createshop(&s12, "싱싱 코너", l12);
    createshop(&s13, "유제품 코너", l13);
    shop sl1[3] = { s11,s12,s13 };

    createlevel(&l1, 1, "식료품 매장", sl1);


    createitem(&i211, "LG 랩탑", 30000, 100);
    createitem(&i212, "ASUS 랩탑", 10000, 100);
    createitem(&i213, "Dell 랩탑", 20000, 100);

    createitem(&i221, "아이폰", 10000, 100);
    createitem(&i222, "갤럭시", 10000, 100);
    createitem(&i223, "노키아", 5000, 100);

    createitem(&i231, "캐리어 에어컨", 50000, 100);
    createitem(&i232, "딤채 냉장고", 30000, 100);
    createitem(&i233, "다이슨 청소기", 40000, 100);

    createlist(&l21, 5);
    createlist(&l22, 5);
    createlist(&l23, 5);

    pushlist(&l21, &i211, 5);
    pushlist(&l21, &i212, 5);
    pushlist(&l21, &i213, 5);

    pushlist(&l22, &i221, 5);
    pushlist(&l22, &i222, 5);
    pushlist(&l22, &i223, 5);

    pushlist(&l23, &i231, 5);
    pushlist(&l23, &i232, 5);
    pushlist(&l23, &i233, 5);

    createshop(&s21, "랩탑 코너", l21);
    createshop(&s22, "스마트폰 코너", l22);
    createshop(&s23, "가전제품 코너", l23);
    shop sl2[3] = { s21,s22,s23 };
    createlevel(&l2, 2, "전자제품 매장", sl2);

    createitem(&i311, "반팔", 30000, 100);
    createitem(&i312, "바지", 10000, 100);
    createitem(&i313, "신발", 20000, 100);

    createitem(&i321, "니트", 10000, 100);
    createitem(&i322, "양말", 10000, 100);
    createitem(&i323, "가디건", 5000, 100);

    createitem(&i331, "블레이저", 50000, 100);
    createitem(&i332, "코트", 30000, 100);
    createitem(&i333, "슬랙스", 40000, 100);

    createlist(&l31, 5);
    createlist(&l32, 5);
    createlist(&l33, 5);

    pushlist(&l31, &i311, 5);
    pushlist(&l31, &i312, 5);
    pushlist(&l31, &i313, 5);

    pushlist(&l32, &i321, 5);
    pushlist(&l32, &i322, 5);
    pushlist(&l32, &i323, 5);

    pushlist(&l33, &i331, 5);
    pushlist(&l33, &i332, 5);
    pushlist(&l33, &i333, 5);

    createshop(&s31, "나이키", l31);
    createshop(&s32, "에잇 세컨즈", l32);
    createshop(&s33, "H&M", l33);
    shop sl3[3] = { s31,s32,s33 };
    createlevel(&l3, 3, "의류 매장", sl3);



    item itemlist[27] = { i111, i112, i113, i121, i122, i123, i131, i132, i133,
                     i211, i212, i213, i221, i222, i223, i231, i232, i233,
                       i311, i312, i313, i321, i322, i323, i331, i332, i333 };

    createlist(&checklist, 10);
    srand(time(NULL));
    random = rand() % 10 + 1;
    for (int i = 0; i < random; i++) {
        r1 = rand() % 26, r2 = rand() % 5+1;
        pushlist(&checklist, &itemlist[r1], r2);
    }

    print_();
    printf("장 보기 목록: \n");
    printlist(checklist);
    print_();
   
    printf("장바구니를 챙길까? y/n\n->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%c", &c);
    
    if (c == 'y') {
        createlist(&inventory, 10);
    }
    else
        createlist(&inventory, 2);
    printf("%d 가지 물품을 담을 수 있게 되었다!\n",inventory.maxcapacity);
    print_();
    print_();
    printf("얼마를 챙길까?\n->");
    fseek(stdin, 0, SEEK_END);
    scanf_s("%d", &money);
    printf("%d원 챙겼다!\n", money);

    //이동중 인터페이스 추가

    createuser(&u, money, inventory, checklist);

    while (exit == 0) {
        if (u.level == 1) {
            printshop(l1);
            input = move();
            while (input == 1) {
                selector(&s11, &u);
                printf("더 담을까? y/n \n->");
                fseek(stdin, 0, SEEK_END);
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 2) {
                selector(&s12, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 3) {
                selector(&s13, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 4) {
                escalator(&u);
                break;
            }
            while (input == 5) {
                elevator(&u);
                break;
            }
            while (input == 6) {
                printf("장바구니를 확인합니다\n");
                printlist(u.inventory);
                break;
            }
            while (input == 7) {
                printf("뭘 사야하지?\n");
                printlist(u.checklist);
                break;
            }
            while (input == 8) {
                counter(&u);
                exit = 1;
                break;
            }
        }
        else if (u.level == 2) {
            printshop(l2);
            input = move();
            while (input == 1) {
                selector(&s21, &u);
                printf("더 담을까? y/n \n->");
                fseek(stdin, 0, SEEK_END);
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 2) {
                selector(&s22, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 3) {
                selector(&s23, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 4) {
                escalator(&u);
                break;
            }
            while (input == 5) {
                elevator(&u);
                break;
            }
            while (input == 6) {
                printf("장바구니를 확인합니다\n");
                printlist(u.inventory);
                break;
            }
            while (input == 7) {
                printf("뭘 사야하지?\n");
                printlist(u.checklist);
                break;
            }
            while (input == 8) {
                counter(&u);
                exit = 1;
                break;
            }

        }
        else {
            printshop(l3);
            input = move();
            while (input == 1) {
                selector(&s31, &u);
                printf("더 담을까? y/n \n->");
                fseek(stdin, 0, SEEK_END);
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 2) {
                selector(&s32, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 3) {
                selector(&s33, &u);
                fseek(stdin, 0, SEEK_END);
                printf("더 담을까? y/n \n->");
                scanf_s("%c", &c);
                if (c == 'n')
                    input = move();
            }
            while (input == 4) {
                escalator(&u);
                break;
            }
            while (input == 5) {
                elevator(&u);
                break;
            }
            while (input == 6) {
                printf("장바구니를 확인합니다\n");
                printlist(u.inventory);
                break;
            }
            while (input == 7) {
                printf("뭘 사야하지?\n");
                printlist(u.checklist);
                break;
            }
            while (input == 8) {
                counter(&u);
                exit = 1;
                break;
            }
        }
    }
    return 1;
}
