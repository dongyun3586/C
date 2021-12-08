#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



typedef struct dal {
    int speed;
    int space[60];
}dal;

void help();
void game(int* cash);
void g(dal a, dal b, dal c);
void printcardresult(int a);
int cardresult(int a, int b);
void sutgame(int* cash);

void printstring(dal a, dal b, dal c) {
    printf("달팽이 1: ");
    for (int i = 0; i < 60; i++) {
        if (a.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    printf("달팽이 2: ");
    for (int i = 0; i < 60; i++) {
        if (b.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    printf("달팽이 3: ");
    for (int i = 0; i < 60; i++) {
        if (c.space[i] == 0) {
            printf(" ");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}



int main() {
    int a;//메뉴 선택
    int cash = 0;
    cash += 1000000;
    while (1) {
        system("cls");
        printf("도박장\n\n");
        printf("현재 보유 금액 : %d\n\n", cash);
        printf("1.달팽이\n2.섯다\n3.도움말\n4.게임종료\n\n");
        printf("메뉴 선택: ");
        scanf("%d", &a);
        switch (a) {
        case 1:
            system("cls");
            if (cash == 0) {
                printf("돈이 부족해 게임을 진행하실 수 없습니다.");
                Sleep(2000);
                break;
            }
            game(&cash);
            break;
        case 2:
            system("cls");
            sutgame(&cash);
            break;
        case 3:
            system("cls");
            help();
            break;
        case 4:
            system("cls");
            printf("게임 종료");
            return 0;
            break;
        }
    }
}


void game(int* cash) {
    system("cls");
    printf("달팽이 게임에 오신 것을 환영합니다 참가비는 100000원입니다 달팽이들의 순서를 맞춰주세요!");
    printf("\n달팽이 1, 달팽이 2, 달팽이 3");
    printf("\n당신의 선택은? : ");
    int x;
    scanf("%d", &x);
    printf("\n2초 후 시작합니다");
    Sleep(2000);
    system("cls");
    dal a;
    dal b;
    dal c;
    srand(time(NULL));
    int peed[3] = { 0,0,0 };
    for (int i = 0; i < 3; i++) {
        peed[i] = rand() % 5 + 1;
        for (int j = 0; j < i; j++) {
            if (peed[i] == peed[j]) {
                i--;
            }
        }
    }
    for (int i = 0; i < 60; i++) {
        a.space[i] = 0;
    }
    for (int i = 0; i < 60; i++) {
        b.space[i] = 0;
    }
    for (int i = 0; i < 60; i++) {
        c.space[i] = 0;
    }

    a.speed = peed[0];
    b.speed = peed[1];
    c.speed = peed[2];

    g(a, b, c);

    if (a.speed > b.speed && a.speed > c.speed) {
        printf("1번 달팽이가 이김");
        if (x == 1) {
            printf("\n이겼습니다.\n100000을 얻었습니다.");
            (*cash) += 100000;
        }
        else {
            printf("\n졌어요 100000을 잃었습니다.");
            (*cash) -= 100000;
        }
    }
    else if (b.speed > a.speed && b.speed > c.speed) {
        printf("2번 달팽이가 이김");
        if (x == 2) {
            printf("\n이겼습니다.\n100000을 얻었습니다.");
            (*cash) += 100000;
        }
        else {
            printf("\n졌어요 100000을 잃었습니다.");
            (*cash) -= 100000;
        }
    }
    else {
        printf("3번 달팽이가 이김");
        if (x == 2) {
            printf("\n이겼습니다.\n100000을 얻었습니다.");
            (*cash) += 100000;
        }
        else {
            printf("\n졌어요 100000을 잃었습니다.");
            (*cash) -= 100000;
        }
    }
    Sleep(2000);
    return;

}

void g(dal a, dal b, dal c) {
    system("cls");
    int x = 0, y = 0, z = 0;
    printstring(a, b, c);
    while (1) {

        a.space[x] = 0;
        a.space[x + a.speed] = 1;
        x += a.speed;

        b.space[y] = 0;
        b.space[y + b.speed] = 1;
        y += b.speed;

        c.space[z] = 0;
        c.space[z + c.speed] = 1;
        z += c.speed;

        Sleep(400);
        system("cls");
        printstring(a, b, c);
        if (x > 25 || y > 25 || z > 25) {
            break;
        }
    }

}


void help() {
    printf("게임을 진행하고 건 돈만큼 딸 수 있습니다.");
    Sleep(2000);
    return;
}

void sutgame(int* cash) {
    //int usercard[2] = { 0,0 }; //카드족보
    //int com1card[2] = { 0,0 };
    //int com2card[2] = { 0,0 };
    int card[6] = { 0,0,0,0,0,0 };//카트족보
    int usercardresult; //카드족보 2개를 통해서 패 결과
    int com1cardresult;
    int com2cardresult;
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        card[i] = rand() % 20 + 1;
        for (int j = 0; j < i; j++) {
            if (card[i] == card[j]) {
                i--;
            }
        }
    }//n월 : (n,10+n) 3은 삼광 1은 일광 8은 팔광임
    usercardresult = cardresult(card[0], card[1]);
    com1cardresult = cardresult(card[2], card[3]);
    com2cardresult = cardresult(card[4], card[5]);
    printf("당신의 패는 ");
    printcardresult(usercardresult);
    printf("배팅하시겠습니까?\n1. 베팅 2. 다이\n");
    printf("선택 : \n");
    int t;//뭐할지 결정
    int r;//얼마나 배팅할지 결정
    scanf("%d", &t);
    if (t == 1) {
        printf("얼마나 거시겠습니까  :");
        scanf("%d", &r);
        if (usercardresult < com1cardresult && usercardresult < com2cardresult) {
            printf("\ncom1의 패는 ");
            printcardresult(com1cardresult);
            printf("\ncom2의 패는 ");
            printcardresult(com2cardresult);
            printf(" 입니다.");
            printf("\n 이기셨습니다.!");
            printf("%d원을 얻으셨습니다.", r);
            (*cash) += r;
            Sleep(6000);
            return;
        }
        else {
            printf("\ncom1의 패는");
            printcardresult(com1cardresult);
            printf("\ncom2의 패는");
            printcardresult(com2cardresult);
            if (com1cardresult < com2cardresult) {
                printf("\ncom1이 이겼습니다.\n");
            }
            else {
                printf("\ncom2이 이겼습니다.\n");
            }
            printf("\n지셨습니다.!");
            printf("\n%d원을 잃으셨습니다.", r);
            (*cash) -= r;
            Sleep(6000);
            return;
        }
    }
    else {
        printf("\n다이를 선택함에 따라 50000원이 차감됩니다.");
        (*cash) -= 50000;
        Sleep(3000);
        return;
    }
}

int cardresult(int a, int b) {
    if ((a == 3 && b == 8) || (a == 8 && b == 3))//38광땡
        return 1;
    else if ((a == 1 && b == 8) || (a == 8 && b == 1))//18광땡
        return 2;
    else if ((a == 1 && b == 3) || (a == 3 && b == 1))//13광땡
        return 3;
    else if ((a == 10 && b == 20) || (a == 20 && b == 10))//장땡
        return 4;
    else if ((a == 9 && b == 19) || (a == 19 && b == 9))//구땡
        return 5;
    else if ((a == 8 && b == 18) || (a == 18 && b == 8))//팔땡
        return 6;
    else if ((a == 7 && b == 17) || (a == 17 && b == 7))//칠땡
        return 7;
    else if ((a == 6 && b == 16) || (a == 16 && b == 6))//육땡
        return 8;
    else if ((a == 5 && b == 15) || (a == 15 && b == 5))//오땡
        return 9;
    else if ((a == 4 && b == 14) || (a == 14 && b == 4))//사땡
        return 10;
    else if ((a == 3 && b == 13) || (a == 13 && b == 3))//삼땡
        return 11;
    else if ((a == 2 && b == 12) || (a == 12 && b == 2))//이땡
        return 12;
    else if ((a == 1 && b == 11) || (a == 11 && b == 1))//일땡
        return 13;
    else if ((a % 10 == 1 && b % 10 == 2) || (a % 10 == 2 && b % 10 == 1))//알리
        return 14;
    else if ((a % 10 == 4 && b % 10 == 1) || (a % 10 == 1 && b % 10 == 4))//독사
        return 15;
    else if ((a % 10 == 1 && b % 10 == 9) || (a % 10 == 9 && b % 10 == 1))//구삥
        return 16;
    else if ((a % 10 == 1 && b % 10 == 0) || (a % 10 == 0 && b % 10 == 1))//장삥
        return 17;
    else if ((a % 10 == 0 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 0))//장사
        return 18;
    else if ((a % 10 == 0 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 0))//세륙
        return 19;
    else if ((a + b) % 10 == 9)//갑오
        return 20;
    else if ((a + b) % 10 == 8)//팔끗
        return 21;
    else if ((a + b) % 10 == 7)//칠끗
        return 22;
    else if ((a + b) % 10 == 6)//육끗
        return 23;
    else if ((a + b) % 10 == 5)//오끗
        return 24;
    else if ((a + b) % 10 == 4)//사끗
        return 25;
    else if ((a + b) % 10 == 3)//삼끗
        return 26;
    else if ((a + b) % 10 == 2)//이끗
        return 27;
    else if ((a + b) % 10 == 1)//일끗
        return 28;
    else if ((a + b) % 10 == 0)//망통
        return 29;
}


void printcardresult(int a) {
    switch (a) {
    case 1:
        printf("38광땡입니다.");
        break;
    case 2:
        printf("18광땡입니다.");
        break;
    case 3:
        printf("13광땡입니다.");
        break;
    case 4:
        printf("장땡입니다.");
        break;
    case 5:
        printf("9땡입니다.");
        break;
    case 6:
        printf("8땡입니다.");
        break;
    case 7:
        printf("7땡입니다.");
        break;
    case 8:
        printf("6땡입니다.");
        break;
    case 9:
        printf("5땡입니다.");
        break;
    case 10:
        printf("4땡입니다.");
        break;
    case 11:
        printf("3땡입니다.");
        break;
    case 12:
        printf("2땡입니다.");
        break;
    case 13:
        printf("1땡입니다.");
        break;
    case 14:
        printf("독사입니다.");
        break;
    case 15:
        printf("구삥입니다.");
        break;
    case 16:
        printf("장삥입니다.");
        break;
    case 17:
        printf("장사입니다.");
        break;
    case 18:
        printf("세륙입니다.");
        break;
    case 19:
        printf("갑오입니다.");
        break;
    case 20:
        printf("9끗입니다.");
        break;
    case 21:
        printf("8끗입니다.");
        break;
    case 22:
        printf("7끗입니다.");
        break;
    case 23:
        printf("6끗입니다.");
        break;
    case 24:
        printf("5끗입니다.");
        break;
    case 25:
        printf("4끗입니다.");
        break;
    case 26:
        printf("3끗입니다.");
        break;
    case 27:
        printf("2끗입니다.");
        break;
    case 28:
        printf("1끗입니다.");
        break;
    case 29:
        printf("망통입니다.");
        break;
    }

}