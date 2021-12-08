#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

void rule(void);
void draw_check02(int c, int r);
void reel_series(int r[][3]);
void gotoxy(int x, int y);
int game_progress(int money);
void display_reel(char rc[][3], int r[][3], int index);
void game_control(char reel[][3], int reel_num[][3], int* money);
int return_money(int r[], int betting, int* case_n);



int main(void) {
    char reel[6][3] = { "★", "♠", "◆", "♥", "♣", "○" };
    int i, reel_num[3][3];
    int money = 10000;
    srand((unsigned)time(NULL));
    rule();
    gotoxy(1, 6);
    draw_check02(3, 3);
    for (i = 0; i < 3; i++)
        reel_num[0][i] = rand() % 5;
    reel_series(reel_num);

    do {
        game_control(reel, reel_num, &money);
    } while (money);

    gotoxy(3, 20);

    if (money <= 0) {
        gotoxy(2, 19);
        printf("파산했습니다.");
        exit(0);
    }

    return 0;
}

//커서 위치를 옮기는 함수(인터넷 참고)
void gotoxy(int x, int y) {
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//슬롯 머신 그리기
void draw_check02(int c, int r)

{
    int i, j;
    unsigned char a = 0xa6;
    unsigned char b[12];

    for (i = 1; i < 12; i++)
        b[i] = 0xa0 + i;
    //전체 큰 틀
    gotoxy(1, 4);
    printf("%c%c", a, b[3]);
    for (i = 0; i < 30; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);

    for (i = 1; i < 12; i++) {
        gotoxy(1, i + 4);
        printf("%c%c", a, b[2]);
        gotoxy(32, i + 4);
        printf("%c%c", a, b[2]);
    }

    gotoxy(1, 15);
    printf("%c%c", a, b[6]);
    for (i = 0; i < 30; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);

    //안에 작은 틀
    gotoxy(5, 6);
    printf("%c%c", a, b[3]);
    for (i = 0; i < 20; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);


    gotoxy(5, 12);
    printf("%c%c", a, b[6]);
    for (i = 0; i < 20; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
}



//점수표
void rule(void) {
    gotoxy(35, 4);
    printf("\t\t<점수표>\n");
    gotoxy(35, 5);
    printf("----------------------------------\n");
    gotoxy(35, 6);
    printf("1:\t 모두 같은 경우 *10\n");
    gotoxy(35, 8);
    printf("2:\t 2개가 같은 경우 *3\n");
    gotoxy(35, 10);
    printf("3:\t 모두 다른 경우 - 꽝");
}



//게임 설명 및 베팅하고 게임 진행하는 함수
int game_progress(int money) {
    gotoxy(25, 18);
    printf("               ");

    int bet;
    gotoxy(3, 17);
    printf("현재 남은 금액: %d원", money);
    gotoxy(1, 1);
    printf("***배팅금액을 입력하고 Enter키를 누르면 게임이 시작됩니다.*** ");
    gotoxy(1, 2);
    printf("***0을 입력하면 종료합니다.***");

    gotoxy(2, 18);
    printf(" 금액을 입력해주세요 > ");
    scanf("%d", &bet);

    if (bet == 0) {
        printf("게임을 종료합니다");
        exit(0);
    }
    if (bet > money) {
        printf("잔액이 부족합니다.");
        gotoxy(25, 17);
        printf("                 ");
        game_progress(money);
    }
    gotoxy(2, 21);
    printf("아무키나 한번만 키를 누르면 릴이 멈춥니다.");

    return bet;
}





//각 슬롯 머신의 결과에 대한 기호의 순서를 결정하는 함수 
void reel_series(int r[][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            r[j][i] = (r[0][i] + j) % 6; //세개의 릴에 대한 기호 순서
}




//회전 순서에 따라 결과를 화면에 출력하는 함수
void display_reel(char rc[][3], int r[][3], int index) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = index; j < 3; j++) {
            gotoxy(11 + j * 4, 7 + i * 2);
            printf("%s", rc[r[i][j]]);
        }
}




//슬롯 머신 게임을 제어하는 함수 game_control (인터넷 참고)
void game_control(char reel[][3], int reel_num[][3], int* money) {
    int i, j, bet, case_num = 0, thank, num[3];
    double pst;
    clock_t start, end;

    display_reel(reel, reel_num, 0);
    bet = game_progress(*money);

    for (i = 0; i < 3; i++) {
        start = clock();
        do {
            for (j = i; j < 3; j++)
                reel_num[0][j] = reel_num[1][j];
            reel_series(reel_num);
            display_reel(reel, reel_num, i);

            end = clock();
            pst = (double)(end - start) / CLK_TCK;

        } while (!kbhit() || (pst < 1)); //1초안에 혹은 키를 누를경우

        num[i] = reel_num[1][i]; //가운데만 보기때문에

    }
    getch();
    thank = return_money(num, bet, &case_num);
    if (thank == 0) {
        *money -= bet;
        thank = -bet;
    }
    else
        *money += thank;
    if (case_num) {
        gotoxy(2, 20);
        printf("베팅:%d원, 사례금:%d", bet, thank);
        gotoxy(25, 18);
        printf("                                      ");
    }

}




//배팅 금액과 사례금을 계산하는 함수 
int return_money(int r[], int betting, int* case_num) {
    int total = 0;
    if (r[0] == r[1] && r[1] == r[2] && r[0] == r[2])      //문양이 세개 동일할경우(★, ♠, ◆)
    {
        if (r[0] == 0)
        {
            total = betting * 10;
            *case_num = 1;
        }
        else if (r[0] == 1) {
            total = betting * 10;
            *case_num = 2;
        }
        else if (r[0] == 2) {
            total = betting * 10;
            *case_num = 3;
        }
    }

    //그 외 두개가 동일할 경우
    else if ((r[0] == 0 && r[1] == 0) || (r[1] == 0 && r[2] == 0) || (r[0] == 0 && r[2] == 0)) {
        total = betting * 3;
        *case_num = 4;
    }
    else if ((r[0] == 1 && r[1] == 1) || (r[1] == 1 && r[2] == 1) || (r[0] == 1 && r[2] == 1)) {
        total = betting * 3;
        *case_num = 5;
    }
    else if ((r[0] == 2 && r[1] == 2) || (r[1] == 2 && r[2] == 2) || (r[0] == 2 && r[2] == 2)) {
        total = betting * 3;
        *case_num = 6;
    }
    else if ((r[0] == 3 && r[1] == 3) || (r[1] == 3 || r[2] == 3) || (r[0] == 3 && r[2] == 3)) {
        total = betting * 3;
        *case_num = 7;
    }
    else if ((r[0] == 4 && r[1] == 4) || (r[1] == 4 && r[2] == 4) || (r[0] == 4 && r[2] == 4)) {
        total = betting * 3;
        *case_num = 8;
    }
    else if ((r[0] == 5 && r[1] == 5) || (r[1] == 5 && r[2] == 5) || (r[0] == 5 && r[2] == 5)) {
        total = betting * 3;
        *case_num = 9;
    }
    else //3개가 다 다른 경우
    {
        *case_num = 0;
        total -= betting;
    }
    return total;

}

