#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#pragma region 구조체 정의와 함수 선언

typedef struct {        //사용자 구조체
    int score;          //점수
    int chk[15];        //각 체커의 위치를 기록, 1~24 : 해당 위치, 0/25:잡힌 말, -1 : 베어링 오프
} player;

player pl[2];       //index가 0이면 ○ 1이면 ●

typedef struct {          //보드판 구조체
    int num;              //해당 칸에 있는 체커 수
    int clr;              //해당 칸에 있는 체커 색 ○는 0, ●는 1, 빈 곳은 -1
} board;
board brd[25] = { 0 };


void gotoxy(int x, int y);      //x, y로 커서를 이동시키는 함수
void rule();                    //규칙 설명화면 출력함수
void start();                   //시작화면 출력함수
void frame();                   //보드판 출력함수
void prtchk(int pos, int num, int clr);                  //해당 위치에 체커 출력 함수, clr가 -1인 경우 공백 출력
void result(int rslt);            //승리 판정 및 결과화면 출력함수
void wincheck(int* clr);                        //우승 여부를 판정하고 경우에 따라 점수를 주는 함수  
void boff(int* clr, int dice);                //체커를 베어링오프 시키는 함수
void mvchk(int* clr, int dice);               //체커를 이동시키는 함수   
void turn(int* clr);    //매턴 주사위 굴려서 체커 이동 함수
void play();                    //게임 실행함수    
#pragma endregion

int main()
{
    srand(time(NULL));
    start();

    return 0;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void rule() {
    int key;
    system("cls");
#pragma region 설명
    printf("백개먼은 두 개의 주사위에서 나온 값만큼 체커(●,○)를 이동시키는 게임입니다.\n");
    printf("●은 24에서 1로, ○은 1에서 24로 이동합니다.\n");
    printf("예를 들어 주사위가 4, 6이 나왔다면 한 체커를 4만큼 이동시키고 또 한 체커(4만큼 이동한 것과 같아도 되고 달라도 됨)를 6만큼 이동시킵니다.\n");
    printf("주사위에서 같은 숫자가 2개 나온다면 해당 숫자 주사위 4개만큼 이동할 수 있습니다.\n");
    printf("이때 이동하려는 칸에 상대의 체커가 한 개 있다면 그 체커를 잡을 수 있고, 상대팀 체커가 2개이상 있다면 해당칸으로 이동할 수 없습니다.\n");
    printf("체커가 24번칸(○체커는 1번칸)을 넘어가면 베어링 오프라고 하며, 모든 체커를 베어링 오프 시키면 승리합니다.\n");
    printf("베어링 오프는 모든 체커를 홈보드(●의 경우 1~6번칸, ○의 경우 19~24번칸)로 옮겼을때부터 할 수 있습니다.\n");
    printf("엔터키를 입력하여 메인화면으로 나갈 수 있습니다.");
#pragma endregion
    while (1) {
        key = getch();
        if (key == 13)
            return;
    }
}

void start() {
    char a = 1; //시작화면에서 현재 선택된 버튼 표시
    char key;   //입력된 버튼 기억
    while (1) {
        system("cls");
        gotoxy(0, 0);
#pragma region 메인화면 출력
        gotoxy(30, 4);
        printf("C 백개먼");
        gotoxy(29, 6);
        printf(">시작하기");
        gotoxy(30, 7);
        printf("플레이 방법");
        gotoxy(30, 8);
        printf("그만하기");
#pragma endregion
        while (1) {
            key = getch();
            if (key == '\n')
                break;
            //위 아래 버튼으로 이동, 엔터키 입력으로 시작
            //down 80, up 72, left 75, right 77, enter 13
            if (key == 72) {
                if (a > 1) {
                    gotoxy(29, 5 + a);
                    printf(" ");
                    a--;
                    gotoxy(29, 5 + a);
                    printf(">");
                }
            }
            else if (key == 80) {
                if (a < 3) {
                    gotoxy(29, 5 + a);
                    printf(" ");
                    a++;
                    gotoxy(29, 5 + a);
                    printf(">");
                }
            }
            else if (key == 13) {
                system("cls");
                gotoxy(0, 0);
                switch (a) {
                case 1:
                    play();
                    break;
                case 2:
                    rule();
                    break;
                case 3:
                    system("cls");
                    exit(1);
                }
                a = 1;
                break;
            }
        }
    }
}

void frame() {
    gotoxy(0, 0);
    printf("┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐\n");
    printf("│13│14│15│16│17│18│19│20│21│22│23│24│\n");
    printf("├──┼──┼──┼──┼──┼──┼──┼──┼──┼──┼──┼──┤\n");
    printf("│●│  │  │  │○│  │○│  │  │  │  │●│\n");          //y축 3
    printf("│●│  │  │  │○│  │○│  │  │  │  │●│\n");
    printf("│●│  │  │  │○│  │○│  │  │  │  │  │\n");
    printf("│●│  │  │  │  │  │○│  │  │  │  │  │\n");
    printf("│●│  │  │  │  │  │○│  │  │  │  │  │\n");
    printf("│  │  │  │  │  │  │  │  │  │  │  │  │\n");
    printf("│○│  │  │  │  │  │●│  │  │  │  │  │\n");
    printf("│○│  │  │  │  │  │●│  │  │  │  │  │\n");
    printf("│○│  │  │  │●│  │●│  │  │  │  │  │\n");
    printf("│○│  │  │  │●│  │●│  │  │  │  │○│\n");
    printf("│○│  │  │  │●│  │●│  │  │  │  │○│\n");          //y축 14     
    printf("├──┼──┼──┼──┼──┼──┼──┼──┼──┼──┼──┼──┤\n");
    printf("│12│11│10│ 9│ 8│ 7│ 6│ 5│ 4│ 3│ 2│ 1│\n");
    printf("└──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┘");
}

void prtchk(int pos, int num, int clr) {
    if (num > 5)
        return;
    if (pos > 12) {
        gotoxy(3 * (pos - 12) - 2, 2 + num);
        switch (clr) {
        case -1:
            printf("  ");
            break;
        case 0:
            printf("○");
            break;
        case 1:
            printf("●");
            break;
        }
    }
    else {
        gotoxy(3 * (12 - pos) + 1, 14 - num);
        switch (clr) {
        case -1:
            printf("  ");
            break;
        case 0:
            printf("○");
            break;
        case 1:
            printf("●");
            break;
        }
    }
    return;
}

void result(int rslt) {
    system("cls");
    printf("게임 결과\n");
    int flag = 1;
    for (int i = 0; i < 15; i++)
        if (pl[1].chk[i] > 0) {
            flag = 0;
            break;
        }
    if (flag)
        printf("2번 사용자(●)가");
    else
        printf("1번 사용자(○)가");
    switch (rslt) {
    case 1:
        printf("싱글게임으로 1점 획득하였습니다.\n");
        break;
    case 2:
        printf("개먼으로 2점 획득하였습니다.\n");
        break;
    case 3:
        printf("백개먼으로 3점 획득하였습니다.\n");
        break;
    }
    pl[flag].score += rslt;
    printf("현재 점수 ● %d : ○ %d\n엔터키로 게임을 계속 하거나 백스페이스바로 게임을 종료합니다.", pl[1].score, pl[0].score);
    int key = 0;
    while (1) {
        key = getch();
        if (key == 13)
            exit(1);
        else if (key == 8)
            return;
    }

}

void wincheck(int* clr) {
    int flag = 1;
    for (int i = 0; i < 15; i++)
        if (pl[*clr].chk[i] != -1) {
            flag = 0;
            break;
        }
    if (!flag)
        return;
    int isgmn = 1;      //개먼(상대방이 한개도 베어링오프 하지 못한경우)인지 확인하는 변수
    int isbgm = 0;      //백개먼(개먼에서 상대방이 잡힌 체커가 있거나, 승자의 홈보드에 상대방 체커가 있는 경우)인지 확인하는 변수
    for (int i = 0; i < 15; i++) {
        if (pl[!*clr].chk[i] == 0 || pl[!*clr].chk[i] == 25) {
            isgmn = 0;
            break;
        }
        else if (pl[!*clr].chk[i] == -1)
            isbgm = 1;
        if (*clr) {
            if (pl[!*clr].chk[i] > 0 && pl[!*clr].chk[i] < 7)
                isbgm = 1;
        }
        else {
            if (pl[!*clr].chk[i] > 17 && pl[!*clr].chk[i] < 25)
                isbgm = 1;
        }
    }
    *clr = isgmn ? (isbgm ? -3 : -2) : -1;     //경우에 따른 점수를 음수로 해서 iswin변수(현재clr변수)에 저장한다. 색깔구분으로 0, 1을 사용하기 때문에 음수 값을 보낸다.
    return;
}

void boff(int* clr, int dice) {
    int flag = 1;
    int able[25] = { 0 };
    if (*clr)
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] > 0 && pl[*clr].chk[i] - dice < 1)
                able[pl[*clr].chk[i]]++;
        }
    else
        for (int i = 0; i < 15; i++)
            if (pl[*clr].chk[i] > 0 && pl[*clr].chk[i] + dice > 24)
                able[pl[*clr].chk[i]]++;

    for (int i = 1; i < 25; i++)
        if (able[i]) {
            if (flag) {
                gotoxy(0, 19);
                printf("                                                               \n                                                                    ");
                gotoxy(0, 19);
                printf("베어링 오프 가능한 체커 : ");
                flag = 0;
            }
            printf("%d번칸 %d개, ", i, able[i]);
        }
    if (flag) {         //이동시킬 수 있는 체커도 없고 베어링오프 가능한 체커도 없는 경우
        gotoxy(0, 19);
        printf("                                                               \n                                                                    ");
        gotoxy(0, 19);
        printf("이동시킬 수 있는 체커가 없습니다! 3초 후 턴을 상대에게 넘깁니다.");
        Sleep(3000);
        return;
    }
    printf("\n이동시킬 체커가 있는 칸을 입력해 주세요 : ");
    int sel;
    while (1) {
        scanf("%d", &sel);
        if (able[sel])
            break;
        gotoxy(0, 20);
        printf("값이 잘못되었습니다. 이동가능한 체커가 있는 칸을 입력해 주세요 : ");
    }
    for (int i = 0;; i++) {
        if (pl[*clr].chk[i] == sel) {
            prtchk(sel, brd[sel].num, -1);
            brd[sel].num--;
            if (!brd[sel].num)
                brd[sel].clr = -1;
            pl[*clr].chk[i] = -1;
        }
        else {
            prtchk(sel, brd[sel].num, -1);
            brd[sel].num--;
            if (!brd[sel].num)
                brd[sel].clr = -1;
            pl[*clr].chk[i] = -1;
        }
        wincheck(*clr);
        break;
    }
    return;
}

void mvchk(int* clr, int dice) {
    int able[25] = { 0 };
    if (*clr)
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] > dice && !(brd[i - dice].num > 1 && !brd[i - dice].clr))
                able[pl[*clr].chk[i]]++;
        }
    else
        for (int i = 0; i < 15; i++) {
            if (pl[*clr].chk[i] < 25 - dice && !(brd[i + dice].num > 1 && brd[i + dice].clr))
                able[pl[*clr].chk[i]]++;
        }
    int flag = 1;
    for (int i = 0; i < 25; i++)
        if (able[i]) {
            if (flag) {
                gotoxy(0, 19);
                printf("                                                               \n                                                                    ");
                gotoxy(0, 19);
                printf("%d만큼 이동 가능한 체커 : ", dice);
                flag = 0;
            }
            printf("%d번칸 %d개, ", i, able[i]);
        }
    if (flag) {
        boff(clr, dice);
        return;
    }
    printf("\n이동시킬 체커가 있는 칸을 입력해 주세요 : ");
    int sel;
    while (1) {
        scanf("%d", &sel);
        if (able[sel])
            break;
        gotoxy(0, 20);
        printf("값이 잘못되었습니다. 이동가능한 체커가 있는 칸을 입력해 주세요 : ");
    }
    for (int i = 0;; i++) {
#pragma region 흰색체커 이동방식
        if (pl[*clr].chk[i] == sel) {
            if (*clr) {
                if (brd[sel - dice].num > 0 && !brd[sel - dice].clr) {  //이동하는 칸에 상대 체커가 있는 경우
                    for (int j = 0;; j++) {
                        if (pl[!*clr].chk[j] == sel - dice) {
                            pl[!*clr].chk[j] = 0;
                            prtchk(sel, able[sel], -1);
                            brd[sel].num--;
                            prtchk(sel - dice, 1, 1);
                            brd[sel - dice].clr = *clr;

                            break;
                        }
                    }
                }
                else {      //이동하는 칸에 상대 체커가 없는 경우
                    prtchk(sel, brd[sel].num, -1);
                    brd[sel].num--;
                    brd[sel - dice].num++;
                    brd[sel - dice].clr = *clr;
                    prtchk(sel - dice, brd[sel - dice].num, 1);
                }
                pl[*clr].chk[i] -= dice;
            }
#pragma endregion
#pragma region 검은색 체커 이동방식
            else {
                if (brd[sel + dice].num > 0 && !brd[sel + dice].clr) {
                    for (int j = 0;; j++) {
                        if (pl[!*clr].chk[j] == sel + dice) {
                            pl[!*clr].chk[j] = 25;
                            prtchk(sel, able[sel], -1);
                            brd[sel].num--;
                            if (!brd[sel].num)
                                brd[sel].clr = -1;
                            prtchk(sel + dice, 1, 1);
                            brd[sel + dice].clr = *clr;
                            break;
                        }
                    }
                }
                else {
                    prtchk(sel, brd[sel].num, -1);
                    brd[sel].num--;
                    if (!brd[sel].num)
                        brd[sel].clr = -1;
                    brd[sel + dice].num++;
                    brd[sel + dice].clr = *clr;
                    prtchk(sel + dice, brd[sel + dice].num, 0);
                }
                pl[*clr].chk[i] += dice;
            }
#pragma endregion

            break;
        }
    }
}

void turn(int* clr) {
    gotoxy(0, 17);
    printf("                   \n                                                               \n                                                               \n                                                                 ");
    gotoxy(0, 17);
    printf("%d번 사용자(", *clr + 1);
    if (*clr)
        printf("●");
    else
        printf("○");
    printf(")의 차례\n");
    int d1, d2;
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    printf("나온 주사위 값:%d, %d\n", d1, d2);
    if (d1 == d2)
        for (int i = 0; i < 4; i++) {
            mvchk(clr, d1);
        }
    else {
        mvchk(clr, d1);
        mvchk(clr, d2);
    }
}

void play() {
    frame();
    pl[0].score = 0;
    pl[1].score = 0;    //점수 초기화
    while (1) {         //여러번 게임을 진행하기 위한 반복문
#pragma region 사용자 체커 위치 초기화
        //○위치 초기화
        for (int j = 0; j < 2; j++)
            pl[0].chk[j] = 1;
        for (int j = 2; j < 7; j++)
            pl[0].chk[j] = 12;
        for (int j = 7; j < 10; j++)
            pl[0].chk[j] = 17;
        for (int j = 10; j < 15; j++)
            pl[0].chk[j] = 19;
        //●위치 초기화
        for (int j = 0; j < 2; j++)
            pl[1].chk[j] = 24;
        for (int j = 2; j < 7; j++)
            pl[1].chk[j] = 13;
        for (int j = 7; j < 10; j++)
            pl[1].chk[j] = 8;
        for (int j = 10; j < 15; j++)
            pl[1].chk[j] = 6;
#pragma endregion
#pragma region 보드판 초기화
        for (int i = 0; i < 25; i++)
            brd[i].clr = -1;
        brd[1].num = 2;
        brd[1].clr = 0;
        brd[6].num = 5;
        brd[6].clr = 1;
        brd[8].num = 3;
        brd[8].clr = 1;
        brd[12].num = 5;
        brd[12].clr = 0;
        brd[13].num = 5;
        brd[13].clr = 1;
        brd[17].num = 3;
        brd[17].clr = 0;
        brd[19].num = 5;
        brd[19].clr = 0;
        brd[24].num = 2;
        brd[24].clr = 1;
#pragma endregion
        int iswin = rand() % 2;
        while (iswin > -1) {
            iswin = !iswin;
            turn(&iswin);
        }
        result(-iswin);
    }
    return;
}

