#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void SizeWarning();
void CursorView(void);
void mainscreen(int* flag);
int cntletter = 0;
int letter_place[150][70] = { 0 };

//미로 생성
int Rendertime = 1;
void GotoXY(int x, int y);
void createmaze(void);
void printsq(void);
void generateent(void);
int mazeallow(int x, int y);
int mazeline[60][60] = { 0 };
int genmazeX = 7;
int genmazeY = 3;
void fullfillr(int x, int y);
void fullfillc(int x, int y);
int movelog[2000] = { 0 };
int movelogstate = -1;
int usualstack = 0;
int logline = 0;
int surrounded(int x, int y);
int cnt = 0;
int checkprocess(int cnt);
void finishmaze(void);
int finX = 53;
int finY = 49;

//미로 풀기
int Movingtime = 1;
void solvemazemode(void);
int GetKeyDown(void);
int caricX = 7;
int caricY = 3;
void caricmove(void);
int movingallowed(int x, int y);
void printcaric(int x, int y);
void afterimagedeleter(int x, int y);
int mazesolved(void);
void timebar(double nowtime, double finaltime);
clock_t start = 0;
clock_t end = 0;
double timepassed;
void timerstart();
double timerend();
char conamicommand[11] = { 0 };
char keylog[20] = { 'a','a','a','a','a','a','a','a','a','a' };
int kln = 0;
void conamicommandsetting();
void conamicommandactive();
int  checkconamicommand();

void credit();
void wave(int x, int y);

int main() {
    srand(time(NULL));
    CursorView();
    int flag = 1;
    SizeWarning();
    mainscreen(&flag);
    if (flag != 1)
        return 0;
    system("cls");
    createmaze();
    solvemazemode();
}

void CursorView(void) {//커서(캐럿) 숨기는 함수
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void GotoXY(int x, int y) {//커서의 위치를 x, y로 이동하는 함수
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void SizeWarning() {
    GotoXY(55, 25);
    printf("전체화면으로 변경하세요!!");
    Sleep(5000);
    GotoXY(55, 25);
    printf("                                                        ");
}
void mainscreen(int* flag) {//게임 시작 전 메인화면 표시
    GotoXY(55, 25);
    printf("Maze Generator");
    GotoXY(54, 27);
    printf("Start");
    GotoXY(61, 27);
    printf("Exit");
    GotoXY(53, 27);
    printf(">");
#pragma region 조작설명출력
    int infomaX = 75;//조작 설명 출력
    int infomaY = 25;
    GotoXY(infomaX, infomaY);
    printf("┌───┐");
    GotoXY(infomaX, infomaY + 1);
    printf("│ a │");
    GotoXY(infomaX, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("│ d │");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 3, infomaY + 3);
    printf(" -->");
    GotoXY(infomaX + 6, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("│ e │");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 6, infomaY + 3);
    printf("enter");
#pragma endregion
    while (1) {//Start와 Exit을 선택할 수 있게 함
        int gkdf = GetKeyDown();
        if (gkdf == 'd') {
            GotoXY(53, 27);
            printf(" ");
            GotoXY(60, 27);
            printf(">");
            *flag = 0;
        }
        else if (gkdf == 'a') {
            GotoXY(60, 27);
            printf(" ");
            GotoXY(53, 27);
            printf(">");
            *flag = 1;
        }
        else if (gkdf == 'e') {
            break;
        }
    }

}

//void background() {
//    int x = 105, y = 50;
//    x = rand() % 105;
//    y = rand() % 50;
//    GotoXY(x, y);
//    int letter;
//    letter = rand() % 3;
//    if (cntletter <= 20) {
//        if (letter == 0)
//            printf("Maze");
//        else if (letter == 1)
//            printf("C");
//        else if (letter == 2)
//            printf("Generater");
//        cntletter += 1;
//        letter_place[x][y] = 1;
//    }
//    else {
//        while (1) {
//            int findx, findy;
//            findx = rand() % 105;
//            findy = rand() % 50;
//            if (letter_place[findx][findy] == 1) {
//                letter_place[findx][findy] = 0;
//                GotoXY(findx, findy);
//                printf("         ");
//                cntletter -= 1;
//                break;
//            }
//        }
//    }
//}

void createmaze(void) {//미로 만들기
    /*
    왼쪽 위에서 시작해서 4방향 중 랜덤한 위치로 이동함
    만약 네 방향 모두 막혀있다면 이동 방향이 저장된 배열을 반대로 읽어가며 하나씩 돌아감
    */
    printsq();//미로의 테두리인 사각형 출력
    int genderection = -1;//랜덤으로 지정될 4방향이 저장되는 변수 설정
    GotoXY(genmazeX, genmazeY);//미로 시작지점으로 이동
    mazeline[genmazeX][genmazeY] = 1;//미로의 정보가 저장되는 배열 - 길인 부분을 1로 설정
    int flag = 0;
    printf("■");
    while (1) {
        /*
                0
              3 P 1   현재 위치를 기준으로 시계방향으로 설정 수가 증가함
                2
        */
        checkprocess(cnt);//총 575개의 칸 중 몇개가 채워졌는지를 프로세스 바 형태로 나타내줌
        GotoXY(60, 4);//현재상태 표시 부분으로 이동
        if (!surrounded(genmazeX, genmazeY))//만약 현재 위치가 둘러싸인 상태라면
            printf("The way is blocked");//막혔다고 출력
        else
            printf("Making                      ");//안 막혔으면 만드는 중이라고 표시
        if (surrounded(genmazeX, genmazeY) == 0) {//만약 막혔다면
            int movement = -1;//마지막 움직인 방향을 불러올 변수를 설정한 뒤
            movement = movelog[movelogstate];//이동 방향을 저장하는 배열로부터 가장 마지막 이동 방향을 불러옴
            movelogstate -= 1;//마지막 이동 위치를 한칸 앞으로 이동 시킴
#pragma region 왔던 길로 돌아가기
            if (movement == 0) {
                genmazeY += 2;
            }
            else if (movement == 1) {
                genmazeX -= 2;
            }
            else if (movement == 2) {
                genmazeY -= 2;
            }
            else if (movement == 3) {
                genmazeX += 2;
            }
#pragma endregion
            //GotoXY(60, 5);
            //printf("Considering");
            //Sleep(Rendertime * 3);
            //GotoXY(60, 5);
            //printf("Suceed!     ");
        }
        if (cnt >= 575) {//총 개수 575개 중 채워진 개수가 575개 이상이면 미로의 길이 모두 정해졌다고 생각하고
            GotoXY(60, 7);
            printf("Maze Renderd!!");//미로가 모두 만들어졌다고 출력
            break;
        }
#pragma region 미로 생성
        /*
        먼저 네가지 방향중 랜덤한 방향을 rnad()함수를 통해 정한다. 그 뒤에 미로를 두 칸씩 놔눠서 격자를 만들고 미로 만들기 알고리즘인 Recursive Backtracking을 사용한다.
        */
        genderection = rand() % 4;//방향 정하기
        if (genderection == 0) {//만약 0(윗 방향이라면)이고
            if (mazeallow(genmazeX, genmazeY - 2)) {//현재 위치에서 위로 2칸이 미로의 벽이 아니며
                if (mazeline[genmazeX][genmazeY - 2] == 0) {//이미 길이 만들어진 곳이 아니라면
                    fullfillr(genmazeX, genmazeY - 2);//2칸 위에 사각형을 출력하고
                    fullfillc(genmazeX, genmazeY - 1);//현재위치와 2칸 위 사각형 사이에도 다른 모양의 사각형을 출력한다.
                    cnt += 1;//채워진 격자의 개수를 한개 늘리고
                    genmazeY -= 2;//미로를 생성하는 변수의 위치를 2칸 위로 바꾼뒤
                    mazeline[genmazeX][genmazeY] = 1;//이 부분이 길이라고 배열에 저장하고
                    mazeline[genmazeX][genmazeY + 1] = 2;//그 사이에 있던 사각형은 2라고 저장한다.(사용되지는 않음)
                    movelogstate += 1;//길이 막혔을 때 돌아가기 위해 배열에 저장할 때 가장 마지막 요소의 수를 1개 늘리고
                    movelog[movelogstate] = 0;//움직인 방향을 기록한다.
                    usualstack = 0;//사용하지 않는 변수
                }
            }
        }
        if (genderection == 1) {
            if (mazeallow(genmazeX + 2, genmazeY)) {
                if (mazeline[genmazeX + 2][genmazeY] == 0) {
                    fullfillr(genmazeX + 2, genmazeY);
                    fullfillc(genmazeX + 1, genmazeY);
                    cnt += 1;
                    genmazeX += 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX - 1][genmazeY] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 1;
                    usualstack = 0;
                }
            }
        }
        if (genderection == 2) {
            if (mazeallow(genmazeX, genmazeY + 2)) {
                if (mazeline[genmazeX][genmazeY + 2] == 0) {
                    fullfillr(genmazeX, genmazeY + 2);
                    fullfillc(genmazeX, genmazeY + 1);
                    cnt += 1;
                    genmazeY += 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX][genmazeY - 1] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 2;
                    usualstack = 0;
                }
            }
        }

        if (genderection == 3) {
            if (mazeallow(genmazeX - 2, genmazeY)) {
                if (mazeline[genmazeX - 2][genmazeY] == 0) {
                    fullfillr(genmazeX - 2, genmazeY);
                    fullfillc(genmazeX - 1, genmazeY);
                    cnt += 1;
                    genmazeX -= 2;
                    mazeline[genmazeX][genmazeY] = 1;
                    mazeline[genmazeX + 1][genmazeY] = 2;
                    movelogstate += 1;
                    movelog[movelogstate] = 3;
                    usualstack = 0;
                }
            }
        }
#pragma endregion
    }
    finishmaze();//미로가 모두 만들어지면 길을 제외한 부분을 벽으로 만들고 시작점과 종료지점을 출력한다. 시작, 종료지점은 고정되어있다.
    GotoXY(60, 55);
}
void printsq(void) {//미로의 기본적인 틀인 사각형을 출력하는 함수이다.
    for (int i = 1; i < 51; i++) {
        GotoXY(5, i);
        printf("■");
        mazeline[5][i] = 1;
        Sleep(Rendertime);
    }
    for (int i = 0; i < 51; i++) {
        GotoXY(i + 5, 51);
        printf("■");
        mazeline[i + 5][51] = 1;
        Sleep(Rendertime);
    }
    for (int i = 51; i > 0; i--) {
        GotoXY(55, i);
        printf("■");
        mazeline[55][i] = 1;
        Sleep(Rendertime);
    }
    for (int i = 50; i > 0; i--) {
        GotoXY(i + 5, 1);
        printf("■");
        mazeline[i + 5][1] = 1;
        Sleep(Rendertime);
    }
    GotoXY(0, 55);
}
void generateent(void) {//테스트용 함수
    GotoXY(7, 0);
    printf("  ");
    Sleep(Rendertime);
    GotoXY(53, 51);
    printf("  ");
    Sleep(Rendertime);
    GotoXY(0, 55);
}

int mazeallow(int x, int y) {//랜덤으로 지정된 방향이 미로의 내부인지 확인하는 함수
    if (x >= 55 || x <= 6 || y <= 1 || y >= 51)
        return 0;
    else
        return 1;
}
void fullfillr(int x, int y) {//2칸 격자로 나눴을 때 방향을 바꾸는 격자점을 출력하는 함수
    GotoXY(x, y);
    printf("■");
    Sleep(Rendertime);
}
void fullfillc(int x, int y) {//void fullfillr함수로 채워진 격자 사이를 채워 길이 연결되게 하는 함수
    GotoXY(x, y);
    printf("□");
}
int surrounded(int x, int y) {//랜덤한 방향으로 이동했을 때 4방향 모두 막혀있는지를 검사하는 함수
    if (mazeline[x + 2][y] == 1 && mazeline[x - 2][y] == 1 && mazeline[x][y + 2] == 1 && mazeline[x][y - 2] == 1)
        return 0;
    else
        return 1;
}
int checkprocess(int cnt) {//얼마나 완료되었는지를 프로세스 바 형식으로 표시해주는 함수
    //full : 575
    GotoXY(60, 3);
    if (0 <= cnt && cnt < 57.5)
        printf("[ □□□□□□□□□□ ]");
    else if (57 <= cnt && cnt < 115)
        printf("[ ■□□□□□□□□□ ]");
    else if (115 <= cnt && cnt < 172)
        printf("[ ■■□□□□□□□□ ]");
    else if (172 <= cnt && cnt < 230)
        printf("[ ■■■□□□□□□□ ]");
    else if (230 <= cnt && cnt < 287)
        printf("[ ■■■■□□□□□□ ]");
    else if (287 <= cnt && cnt < 345)
        printf("[ ■■■■■□□□□□ ]");
    else if (345 <= cnt && cnt < 402)
        printf("[ ■■■■■■□□□□ ]");
    else if (402 <= cnt && cnt < 460)
        printf("[ ■■■■■■■□□□ ]");
    else if (460 <= cnt && cnt < 517)
        printf("[ ■■■■■■■■□□ ]");
    else if (517 <= cnt && cnt < 575)
        printf("[ ■■■■■■■■■□ ]");
    else if (cnt == 575)
        printf("[ ■■■■■■■■■■ ]");
}
void finishmaze(void) {//만들어진 미로의 길을 제외한 벽 부분을 출력하는 함수, 고정된 시작점, 종료지점도 출력한다.
    for (int rendery = 1; rendery < 52; rendery++) {
        for (int renderx = 5; renderx < 56; renderx++) {
            GotoXY(renderx, rendery);
            if (mazeline[renderx][rendery] != 0)
                printf("  ");
            else
                printf("■");
            Sleep(0);
        }
    }
    GotoXY(7, 3);
    printf("S");
    GotoXY(53, 49);
    printf("E");
    GotoXY(60, 9);
    printf("Maze Generate Finisd!!");
}

void solvemazemode(void) {//사용자가 미로를 풀도록해주는 함수
#pragma region 설명출력
    /*
    미로를 풀 때 케릭터를 이동시킬수 있는 방식은 2가지가 있다.
    첫번쨰는 wasd를 이용하는 방식으로 한칸씩 움직인다.
    두번쨰는 ijkl를 이용하는 방식으로 직선으로 연결된 길의 끝부분으로 바로 이동할 수 있다.
    */
    int infomaX = 75;
    int infomaY = 30;
    GotoXY(infomaX + 3, infomaY - 3);
    printf("┌───┐");
    GotoXY(infomaX + 3, infomaY + 1 - 3);
    printf("│ w │");
    GotoXY(infomaX + 3, infomaY + 2 - 3);
    printf("└───┘");
    GotoXY(infomaX + 6, infomaY - 2);
    printf("↑");
    GotoXY(infomaX, infomaY);
    printf("┌───┐");
    GotoXY(infomaX, infomaY + 1);
    printf("│ a │");
    GotoXY(infomaX, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("│ s │");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 3, infomaY + 3);
    printf("  ↓");
    GotoXY(infomaX + 6, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("│ d │");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 6, infomaY + 3);
    printf(" -->");

    infomaX = 75;
    infomaY = 40;
    GotoXY(infomaX + 1, infomaY - 4);
    printf("Fast Movement");
    GotoXY(infomaX + 3, infomaY - 3);
    printf("┌───┐");
    GotoXY(infomaX + 3, infomaY + 1 - 3);
    printf("│ i │");
    GotoXY(infomaX + 3, infomaY + 2 - 3);
    printf("└───┘");
    GotoXY(infomaX + 6, infomaY - 2);
    printf("↑");
    GotoXY(infomaX, infomaY);
    printf("┌───┐");
    GotoXY(infomaX, infomaY + 1);
    printf("│ j │");
    GotoXY(infomaX, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX, infomaY + 3);
    printf(" <--");
    GotoXY(infomaX + 3, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 3, infomaY + 1);
    printf("│ k │");
    GotoXY(infomaX + 3, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 3, infomaY + 3);
    printf("  ↓");
    GotoXY(infomaX + 6, infomaY);
    printf("┌───┐");
    GotoXY(infomaX + 6, infomaY + 1);
    printf("│ l │");
    GotoXY(infomaX + 6, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX + 6, infomaY + 3);
    printf(" -->");

    infomaX = 90;
    infomaY = 30;
    GotoXY(infomaX, infomaY);
    printf("┌───┐");
    GotoXY(infomaX, infomaY + 1);
    printf("│ 0 │");
    GotoXY(infomaX, infomaY + 2);
    printf("└───┘");
    GotoXY(infomaX - 1, infomaY + 3);
    printf("Speed up");
    GotoXY(infomaX, infomaY + 4);
    printf("┌───┐");
    GotoXY(infomaX, infomaY + 5);
    printf("│ 9 │");
    GotoXY(infomaX, infomaY + 6);
    printf("└───┘");
    GotoXY(infomaX - 1, infomaY + 7);
    printf("Speed down");
#pragma endregion

    timerstart();//미로를 푸는데 걸린 시간을 측정하는 타이머를 시작시키는 함수 - 정확히는 함수가 호출된 시간을 변수에 저장하는 방식이다.
    while (1) {
        end = clock();//현재시간을 end라는 변수에 가져옴
        timepassed = (double)(end - start) / CLOCKS_PER_SEC;//타이머가 시작된 뒤 시간이 얼마나 지났는지를 두 변수를 뺴서 timepassed변수에 넣음
        GotoXY(60, 15);
        printf("%0.3f", timepassed);//지난 시간을 출력 - 시간이 소수점 셋째 자리까지만 나오므로 0.3f로 출력
        //if ((int)timepassed % 30 == 29.999) {//미로가 30초마다 바뀌도록하려고 했으나 이 프로그램에 사용한 알고리즘 특성상 도착지점에 가까워도 미로를 풀기 위해서 한참 돌아가야해서 빼게 되었다. 또한 현재지점이 길 부분이 아닌 벽부분일 수도 있다.
        //    Rendertime = 0;
        //    for(int i=0;i<60;i++)
        //        for(int j=0;i<60;j++)
        //            mazeline[i][j] =  0 ;
        //    createmaze();
        //}
        caricmove();//캐릭터를 움직이는 함수
        if (mazesolved()) {//캐릭터가 도착지점에 도착했는지 확인
            GotoXY(63, 47);
            printf("success!! record : %0.3f", timepassed);//도착했다고 출력하고 얼마나 걸렸는지 출력함
            break;
        }
    }
}
int GetKeyDown() {//어떤 키가 눌렸는지 반환하는 함수 - 엔터를 치지 않아도 바로 반환함
    if (_kbhit() != 0)
        return _getch();
    return 0;
}
void conamicommandsetting() {
    conamicommand[0] = 'w';
    conamicommand[1] = 'w';
    conamicommand[2] = 's';
    conamicommand[3] = 's';
    conamicommand[4] = 'a';
    conamicommand[5] = 'd';
    conamicommand[6] = 'a';
    conamicommand[7] = 'd';
    conamicommand[8] = 'b';
    conamicommand[9] = 'a';
    conamicommand[10] = '\0';
}
void caricmove(void) {//케릭터가 움직이게 하는 함수
    conamicommandsetting();
    int gkd = GetKeyDown();//어떤 키가 눌렸는지 return 받음
    if (gkd == 'a') {//a키 : 왼쪽
        if (movingallowed(caricX - 1, caricY)) {//벽이 아닌지 확인하고
            afterimagedeleter(caricX, caricY);//현재 위치에 있는 캐릭터를 지움
            caricX -= 1;//왼쪽으로 1 이동
            printcaric(caricX, caricY);//캐릭터의 현재 위치 출력
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'a';
        //GotoXY(60, 25);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 's') {
        if (movingallowed(caricX, caricY + 1)) {
            afterimagedeleter(caricX, caricY);
            caricY += 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 's';
        //GotoXY(60, 26);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'd') {
        if (movingallowed(caricX + 1, caricY)) {
            afterimagedeleter(caricX, caricY);
            caricX += 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'd';
        //GotoXY(60, 27);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'w') {
        if (movingallowed(caricX, caricY - 1)) {
            afterimagedeleter(caricX, caricY);
            caricY -= 1;
            printcaric(caricX, caricY);
        }
        strcpy(keylog, keylog + 1);
        keylog[9] = 'w';
        //GotoXY(60, 28);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'b') {
        strcpy(keylog, keylog + 1);
        keylog[9] = 'b';
        //GotoXY(60, 29);
        //printf("%s", keylog);
        //Sleep(3);
    }
    else if (gkd == 'j') {
        int i = 0;
        for (i = 0; movingallowed(caricX - i, caricY); i++) {
            //계속진행
        }
        for (int j = 0; j < i - 1; j++) {
            caricX -= 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX + j, caricY);
            Sleep(Movingtime);
        }

    }
    else if (gkd == 'k') {
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY + i); i++) {
            //계속진행
        }
        for (int j = 0; j < i - 1; j++) {
            caricY += 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX, caricY - j);
            Sleep(Movingtime);
        }
    }
    else if (gkd == 'l') {
        int i = 0;
        for (i = 0; movingallowed(caricX + i, caricY); i++) {
            //계속진행
        }
        for (int j = 0; j < i - 1; j++) {
            caricX += 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX - j, caricY);
            Sleep(Movingtime);
        }
    }
    else if (gkd == 'i') {
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY - i); i++) {
            //계속진행
        }
        for (int j = 0; j < i - 1; j++) {
            caricY -= 1;
            printcaric(caricX, caricY);
            Sleep(Movingtime);
        }
        for (int j = i - 1; j > 0; j--) {
            afterimagedeleter(caricX, caricY + j);
            Sleep(Movingtime);
        }
    }
    else if (gkd == '9') {//ijkl키의 애니메이션을 느리게 한다.
        if (Movingtime - 10 > 0) {
            Movingtime -= 10;
        }

    }
    else if (gkd == '0') {//ijkl키의 애니메이션을 빠르게 한다.
        Movingtime += 10;
    }
    /*
     else if (gkd == 'i') {//이 코드가 수정되기 전의 이동 코드이다. 움직일때의 모션이 없다.
        int i = 0;
        for (i = 0; movingallowed(caricX, caricY - i); i++) {
            //계속진행
        }
        afterimagedeleter(caricX, caricY);
        caricY -= i-1;
        printcaric(caricX, caricY);
    }
    */
    else if (gkd == 'g') {//테스트용 키 : 미로를 꺨필요없이 바로 도착지점으로 이동하는 키이다.
        afterimagedeleter(caricX, caricY);
        caricX = finX;
        caricY = finY;
        printcaric(caricX, caricY);
    }
    //GotoXY(60,17);
    //printf("(%d , %d)        ", caricX, caricY);//테스트용 캐릭터 위치 출력

    GotoXY(60, 20);
    printf("%s                    ", keylog);
    GotoXY(60, 21);
    printf("%s", conamicommand);
    keylog[10] = '\0';
    checkconamicommand();

}

int  checkconamicommand() {
    if (!strcmp(conamicommand, keylog)) {
        conamicommandactive();
    }
    return 0;
}
void conamicommandactive() {
    int** randomblank;
    randomblank = (int**)malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++)
        randomblank[i] = (int*)malloc(sizeof(int) * 100);
    int randx, randy;
    for (int i = 0; i < 2601; i++) {
        randx = rand() % 51 + 5;
        randy = rand() % 51 + 1;
        if (randomblank[randx] + randy != 1) {
            randomblank[randx][randy] = 1;
            GotoXY(randx, randy);
            printf("■");
        }
        else
            i++;
    }
    credit();
}//    □  ■
void credit() {
    GotoXY(6, 2);
    printf("Credit");
    Sleep(1000);
    GotoXY(6, 4);
    printf("Maze Generator.");
    GotoXY(6, 5);
    printf("Made by 1208 신동민");
    GotoXY(6, 7);
    printf("Conami command : w w s s a d a d b a ");
    GotoXY(6, 8);
    printf("< Game over >");
    GotoXY(6, 53);
    exit(0);
}
int movingallowed(int x, int y) {//움직일 수 있는 곳인지 반환한다.
    if (mazeline[x][y] == 1 || mazeline[x][y] == 2)
        return 1;
    else
        return 0;
}
void printcaric(int x, int y) {//캐릭터를 출력한다. 캐릭터는 언더테일과 같은 하트이다.
    GotoXY(x, y);
    printf("♥");
}
void afterimagedeleter(int x, int y) {//캐릭터의 예전자리를 지우기 위한 함수
    GotoXY(x, y);
    printf("  ");
}
int mazesolved(void) {//캐릭터가 도착지점에 도착했는지 확인하는 함수 - 캐릭터의 좌표와 도착지점의 좌표(고정)가 같은지 확인한다.
    if (caricX == finX && caricY == finY)
        return 1;
    else
        return 0;
}
//타이머 함수
double betweentime;
void timerstart() {
    betweentime = 0;
    start = clock();
}//타이머 시작 시간 저장
double timerend() {
    end = clock();//타이머 종료시간 저장
    timepassed = (double)(end - start) / CLOCKS_PER_SEC; //초단위 변환
    return timepassed;//시간 간격 반환
}