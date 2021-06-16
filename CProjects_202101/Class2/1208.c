#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include"resource.h"

static HWND hWnd;
static HINSTANCE hInst;
int x = 24, y = 17;
int health = 5;
int attackarr[30][30] = { 153 };
int deletevisited[100][100] = { 3 };
int gkd;
double timertime;
int buf[100] = { 0, };
float afwtime = 0.6;
void Render(int x, int y);
void Render2(int x, int y);
void undertale();
void deleteundertale();
void SetConsoleView();

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y);
void printsqure();
//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown();
void printoheart(int  y);
void printgameheart(int x, int y);
void printdamagedgameheart(int x, int y);
void deletegameheart(int x, int y);
void gameover();
//TEST GEAR
void printXY();
//남은 hp출력
void printhealth(int healthk);
void CursorView();
int barrier(x, y);
void heartcheck();

//공격
void waitwhileattack();
//패턴 1관련
void attacklow();
void attackright();
void attackhigh();
void attackleft();
void attackcross();
void attack4();
//패턴 2 관련
void attackrandom(int n);
void printattackarea();
void attack1();
//패턴 3 관련
void attackfourwayup();
void attackfourwaydown();
void attackfourwayright();
void attackfourwayleft();

//이동 명령어
void move();
void qjmove();
//타이머 함수
void timebar(double nowtime, double finaltime);
clock_t start = 0;
clock_t end = 0;
double betweentime;
void timerstart();
double timerend();

//score 책정
int scorevisited[30][30] = { 0 };
int score = 0;
void scorecalculate();

int main() {
RESTART://재시작을 위한 앵커
    hWnd = GetConsoleWindow();
    hInst = GetModuleHandle(NULL);
    printgameheart(x, y);
    srand(time(NULL));//랜덤 시드 설정
    SetConsoleView();//콘솔 크기 제한
    CursorView();//캐럿 숨기기
    undertale();//언더테일 로고 표시
    Sleep(1000);//1초 정지
    deleteundertale();//언더테일 로고 랜덤으로 지우기
    system("cls");//콘솔 모두 지우기
    int timeofscript = 200;//대사 사이 시간
    timerstart(); timertime = timerend(); while (timertime < 2) { Render(350, 100); timertime = timerend(); } timertime = 0; system("cls");
    //샌즈 대사
    GotoXY(18, 11); printf("정"); Sleep(timeofscript); printf("말 "); Sleep(timeofscript * 2); printf("아"); Sleep(timeofscript); printf("름"); Sleep(timeofscript); printf("다"); Sleep(timeofscript); printf("운 "); Sleep(timeofscript); printf("날"); Sleep(timeofscript); printf("이"); Sleep(timeofscript); printf("야"); Sleep(timeofscript); printf("."); Sleep(timeofscript * 3); system("cls");
    GotoXY(18, 11); printf("새"); Sleep(timeofscript); printf("들"); Sleep(timeofscript); printf("은 "); Sleep(timeofscript * 2); printf("지"); Sleep(timeofscript); printf("저"); Sleep(timeofscript); printf("귀"); Sleep(timeofscript); printf("고"); Sleep(timeofscript); printf(","); Sleep(timeofscript * 4); system("cls");
    GotoXY(18, 11); printf("꽃"); Sleep(timeofscript); printf("들"); Sleep(timeofscript); printf("은 "); Sleep(timeofscript * 2); printf("피"); Sleep(timeofscript); printf("어"); Sleep(timeofscript); printf("나"); Sleep(timeofscript); printf("고"); Sleep(timeofscript); printf(" . "); Sleep(timeofscript); printf(". "); Sleep(timeofscript); printf("."); Sleep(timeofscript * 3); system("cls");
    GotoXY(18, 11); printf("이"); Sleep(timeofscript); printf("런"); Sleep(timeofscript); printf("날"); Sleep(timeofscript); printf("엔 "); Sleep(timeofscript * 3); printf("너 "); Sleep(timeofscript * 1.5); printf("같"); Sleep(timeofscript); printf("은 "); Sleep(timeofscript * 2); printf("꼬"); Sleep(timeofscript); printf("마"); Sleep(timeofscript); printf("들"); Sleep(timeofscript); printf("은"); Sleep(timeofscript); printf(" . "); Sleep(timeofscript); printf(". "); Sleep(timeofscript); printf("."); Sleep(timeofscript * 5); timerstart(); timertime = timerend(); while (timertime < 1) { Render(70, 100); timertime = timerend(); } timertime = 0; system("cls");
    GotoXY(18, 11); Sleep(3000);
    GotoXY(18, 11); printf("지"); Sleep(timeofscript * 2); printf("옥"); Sleep(timeofscript * 2); printf("에"); Sleep(timeofscript * 2); printf("서 "); Sleep(timeofscript * 4); printf("불"); Sleep(timeofscript * 3); printf("타"); Sleep(timeofscript * 3); printf("야"); Sleep(timeofscript * 3); printf("해"); Sleep(timeofscript * 3); printf("."); Sleep(timeofscript * 1.5);
    //샌즈 대사 종료
    printsqure();//캐릭터가 움직이는 공간 만들기
    printhealth(health);//기본 hp출력
    GotoXY(3, 3); printf("score:%d", score);//점수 출력-처음 설정--공격이 시작되면 사라짐
    //Gameroop-게임 패턴 반복
    printgameheart(x, y);
    move();//키보드 입력 받고 움직이기
    //attack start-공격 함수 시작 부분
    //first attack-첫번째 공격-언더테일 샌즈전 첫번째 공격
    attack4(); printgameheart(x, y);//4방향 공격 후 하트 다시 출력 -공격 이팩트에 가려졌을 수도 있어서
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0; system("cls");//0.3초 타이머 후 콘솔 초기화
    attackcross(); printgameheart(x, y);//대각선 방향 공격 후 하트 다시 출력 -공격 이팩트에 가려졌을 수도 있어서
    timerstart(); timertime = timerend(); while (timertime < 1) { move(); timertime = timerend(); } timertime = 0; system("cls");//1초 타이머 후 콘솔 초기화
    attack4(); printgameheart(x, y);//4방향 공격 후 하트 다시 출력 -공격 이팩트에 가려졌을 수도 있어서
    timerstart(); timertime = timerend(); while (timertime < 1) { move(); timertime = timerend(); } timertime = 0;//1초 타이머
    //second attack-두번쨰 공격-랜덤 위치 공격
    attackrandom(84);//공격범위 169칸 중 84칸-중복허용
    attackrandom(100);//공격범위 169칸 중 100칸-중복허용
    attackrandom(120);//공격범위 169칸 중 120칸-중복허용
    attackrandom(140);//공격범위 169칸 중 140칸-중복허용
    attackrandom(160);//공격범위 169칸 중 160칸-중복허용
    attackrandom(168);//공격범위 169칸 중 168칸-중복허용
    attackrandom(168);//공격범위 169칸 중 168칸-중복허용
    attackrandom(168);//공격범위 169칸 중 168칸-중복허용
    attackrandom(168);//공격범위 169칸 중 168칸-중복허용
    attackrandom(168);//공격범위 169칸 중 168칸-중복허용
    system("title 당신은 죄악이 등을 타고 오르는 것을 느꼈다.");
    system("cls");
    GotoXY(15, 11);
    printf("언젠가는... 포기하는 법을 배워야 할거야...");
    Sleep(3500);
    system("title UnderTale_Sans By S");
    system("cls");
    //third attack-랜덤 방향으로 이동해야하는 패턴-샌즈전 마지막 패턴
    printsqure();
    for (int i = 0; i < 32; i++) {//32번 공격
        int attackderec = rand() % 4;//0~3중 하나를 랜덤으로 골라 그 방향으로 움직여야함
        if (attackderec == 0) attackfourwayup();//위로 움직여야함
        if (attackderec == 1) attackfourwaydown();//아래로 움직여야함
        if (attackderec == 2) attackfourwayright();//오른쪽으로 움직여야함
        if (attackderec == 3) attackfourwayleft();//왼쪽으로 움직여야함
    }
    afwtime = 1;
    for (int i = 0; i < 10; i++)
    {
        int attackderec = rand() % 4;//0~3중 하나를 랜덤으로 골라 그 방향으로 움직여야함
        if (attackderec == 0) attackfourwayup();//위로 움직여야함
        if (attackderec == 1) attackfourwaydown();//아래로 움직여야함
        if (attackderec == 2) attackfourwayright();//오른쪽으로 움직여야함
        if (attackderec == 3) attackfourwayleft();//왼쪽으로 움직여야함
    }
    system("cls");
    GotoXY(18, 11); printf("그"); Sleep(timeofscript); printf("래"); Sleep(timeofscript * 2); printf(" . "); Sleep(timeofscript); printf(". "); Sleep(timeofscript); printf("."); Sleep(timeofscript * 5); system("cls"); GotoXY(18, 11); printf("결"); Sleep(timeofscript); printf("국 "); Sleep(timeofscript * 2); printf("이"); Sleep(timeofscript); printf("렇"); Sleep(timeofscript); printf("게 "); Sleep(timeofscript * 2); printf("되"); Sleep(timeofscript); printf("는 "); Sleep(timeofscript * 2); printf("건"); Sleep(timeofscript); printf("가"); Sleep(timeofscript * 2); printf("?"); Sleep(timeofscript * 5); system("cls");
    GotoXY(18, 11); printf(" . "); Sleep(timeofscript); printf(". "); Sleep(timeofscript); printf("."); Sleep(timeofscript * 4); system("cls"); GotoXY(18, 11); printf("그"); Sleep(timeofscript); printf("냥 "); Sleep(timeofscript * 3); printf("경"); Sleep(timeofscript); printf("고 "); Sleep(timeofscript * 2); printf("안 "); Sleep(timeofscript); printf("했"); Sleep(timeofscript); printf("다"); Sleep(timeofscript); printf("고"); Sleep(timeofscript); printf("만 "); Sleep(timeofscript * 2); printf("하"); Sleep(timeofscript); printf("지"); Sleep(timeofscript); printf("말"); Sleep(timeofscript); printf("아"); Sleep(timeofscript); printf("줘"); Sleep(timeofscript); printf(" . "); Sleep(timeofscript); printf(". "); Sleep(timeofscript); printf("."); Sleep(timeofscript); system("cls");
    GotoXY(18, 11); printf("뭐"); Sleep(timeofscript); printf(" . "); Sleep(timeofscript * 3); system("cls"); GotoXY(18, 11); printf("그"); Sleep(timeofscript); printf("릴"); Sleep(timeofscript); printf("비"); Sleep(timeofscript); printf("나 "); Sleep(timeofscript * 2); printf("가"); Sleep(timeofscript); printf("야"); Sleep(timeofscript); printf("겠"); Sleep(timeofscript); printf("군"); Sleep(timeofscript); printf("."); Sleep(timeofscript * 5); system("cls");
    undertale();
    Sleep(2000);
    GotoXY(22, 2);
    printf("YOU WIN");
    while (1) {
        int gkd = 0;
        gkd = GetKeyDown();//입력을 변수에 저장
        if (gkd != 0) if (gkd == 'p') { x = 24, y = 17; health = 5; score = 0; goto RESTART; }//p키를 눌렀을 때 다시시작
    }
}
void undertale() {//언더테일 로고 출력
    int xofundertale = 12, yofundertale = 11;
    GotoXY(xofundertale, yofundertale - 7); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□");
    GotoXY(xofundertale, yofundertale - 6); printf("□■□■□■□□□■□■■■□□■■■■□■■■■□□");
    GotoXY(xofundertale, yofundertale - 5); printf("□■□■□■■■□■□■■■■□■■■■□■■■■□□");
    GotoXY(xofundertale, yofundertale - 4); printf("□■□■□■■■■■□■□□■□■■□□□■♥■□□□");
    GotoXY(xofundertale, yofundertale - 3); printf("□■□■□■□■■■□■□□■□■■□□□■■■■□□");
    GotoXY(xofundertale, yofundertale - 2); printf("□■□■□■□□■■□■■■■□■■■■□■□■■□□");
    GotoXY(xofundertale, yofundertale - 1); printf("□□■□□■□□■■□■■■□□■■■■□■□□□■□");
    GotoXY(xofundertale, yofundertale + 0); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□");
    GotoXY(xofundertale, yofundertale + 1); printf("□□□□■■■■■□□■□□□■□□□■■■■□□□□");
    GotoXY(xofundertale, yofundertale + 2); printf("□□□□□□■□□□■□■□□■□□□■■■■□□□□");
    GotoXY(xofundertale, yofundertale + 3); printf("□□□□□□■□□□■■■□□■□□□■■□□□□□□");
    GotoXY(xofundertale, yofundertale + 4); printf("□□□□□□■□□□■□■□□■□□□■■□□□□□□");
    GotoXY(xofundertale, yofundertale + 5); printf("□□□□□□■□□□■□■□□■□□□■■■■□□□□");
    GotoXY(xofundertale, yofundertale + 6); printf("□□□□□□■□□□■□■□□■■■□■■■■□□□□");
    GotoXY(xofundertale, yofundertale + 7); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}
void deleteundertale() {//언더테일 로고를 랜덤으로 지움
    for (int i = 0; i < 3000; i++) {//3000번 정도 반복해서 로고를 지움
        int xdel = rand() % 27 + 12, ydel = rand() % 15 + 4;//랜덤 위치 지정
        if (deletevisited[xdel][ydel] != 1) {//방문 배열을 통해 지우는 횟수를 줄이고 모든 칸이 다 지워지게 함
            GotoXY(xdel, ydel); printf("  "); Sleep(10); deletevisited[xdel][ydel] = 1;
        }
    }
}
void SetConsoleView() {//콘솔 설정:열:100,줄:25/콘솔 이름 설정
    system("mode con:cols=100 lines=25");
    system("title UnderTale_Sans By S");
}
void GotoXY(int x, int y) {//커서의 위치를 x, y로 이동하는 함수
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void printsqure() {//캐릭터 이동가능 공간 출력
    GotoXY(18, 10);
    printf("■■■■■■■■■■■■■■");
    GotoXY(18, 11);
    printf("■                        ■");
    GotoXY(18, 12);
    printf("■                        ■");
    GotoXY(18, 13);
    printf("■                        ■");
    GotoXY(18, 14);
    printf("■                        ■");
    GotoXY(18, 15);
    printf("■                        ■");
    GotoXY(18, 16);
    printf("■                        ■");
    GotoXY(18, 17);
    printf("■                        ■");
    GotoXY(18, 18);
    printf("■                        ■");
    GotoXY(18, 19);
    printf("■                        ■");
    GotoXY(18, 20);
    printf("■                        ■");
    GotoXY(18, 21);
    printf("■                        ■");
    GotoXY(18, 22);
    printf("■                        ■");
    GotoXY(18, 23);
    printf("■■■■■■■■■■■■■■");
}
int GetKeyDown() { if (_kbhit() != 0) return _getch(); return 0; }//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
void printoheart(int y) {//맨 처음 출력되는 하트
    GotoXY(0, y);
    printf("  $$  $$  \n");
    printf(" $$$$$$$$ \n");
    printf("  $$$$$$  \n");
    printf("    $$    \n");
}
void printgameheart(int x, int y) { GotoXY(x, y); if (attackarr[x][y] != 0) printf("♥"); else if (attackarr[x][y] == 0) printf("♡"); }//실제 게임시 출력되는 하트//공격 영역과 캐릭터 중복시 출력 설정
void deletegameheart(int x, int y) { GotoXY(x, y); printf("  "); }//기존에 캐릭터가 있던 위치의 캐릭터를 지우기 위한 함수
void gameover() {
    SetConsoleView();
    printf("\n\n\n");
    printf("           ■■■■  ■■■  ■      ■  ■■■■   \n");
    printf("         ■          ■  ■  ■■  ■■  ■         \n");
    printf("         ■   ■■   ■■■  ■  ■  ■  ■■■■   \n");
    printf("         ■      ■  ■  ■  ■      ■  ■         \n");
    printf("           ■■■■  ■  ■  ■      ■  ■■■■   \n");
    printf("                                                    \n");
    printf("           ■■■■    ■  ■  ■■■■  ■■       \n");
    printf("         ■        ■  ■  ■  ■        ■  ■     \n");
    printf("         ■        ■  ■  ■  ■■■■  ■■■     \n");
    printf("         ■        ■  ■  ■  ■        ■  ■     \n");
    printf("           ■■■■      ■    ■■■■  ■    ■   \n");
}
void printXY() { GotoXY(40, 5); printf("%d %d", x, y); }//TEST GEAR-테스트를 하기위한 캐릭터 좌표 출력 함수
void printhealth(int healthk) {//남은 hp출력
    GotoXY(19, 24);
    if (healthk == 5) printf("[ ■■■■■■■■■■ ]");
    if (healthk == 4) printf("[ ■■■■■■■■     ]");
    if (healthk == 3) printf("[ ■■■■■■         ]");
    if (healthk == 2) printf("[ ■■■■             ]");
    if (healthk == 1) printf("[ ■■                 ]");
    if (healthk == 0) printf("[                      ]");
}
void CursorView() {//커서(캐럿) 숨기는 함수
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
int barrier(x, y) {//캐릭터가 이동가능 영역을 못나가게 하기 위한 배리어(결계) 함수
    if (18 >= x) { x += 1; printgameheart(x, y); printsqure(); return 0; }//X방향
    else if (30 < x) { x = 30; printgameheart(x, y); printsqure(); return 0; }
    if (10 >= y) { y += 1; printgameheart(x, y); printsqure(); return 0; }//Y 방향
    else if (22 < y) { y -= 1; printgameheart(x, y); printsqure(); return 0; }
    else return 1;
    printXY();
}
//공격 함수
void printattackarea() {//second attack-공격할 장소를 출력하는 함수
    GotoXY(18, 10);
    for (int i = 11; i <= 22; i++)
        for (int j = 19; j <= 30; j++) {
            GotoXY(19, i);
            if (attackarr[j][i] == 0 && (i != y || j != x)) { GotoXY(j, i); printf("□"); }//미리 설정된 공격범위의 위치를 스캔해서 출력
            else if (attackarr[j][i] == 0 && i == y && j == x) { GotoXY(j, i); printf("♡"); }//캐릭터와 겹치는 경우 캐릭터의 외관 변경-기존:❤ 겹치는 경우:♡
        }
}
void attack1() {//second attack-실제 공격하는 함수
    GotoXY(18, 10);
    for (int i = 11; i <= 22; i++) {
        GotoXY(19, i);
        for (int j = 19; j <= 30; j++) {
            if (attackarr[j][i] == 0 && (i != y || j != x)) { GotoXY(j, i); printf("■"); }//미리 설정된 공격범위의 위치를 스캔해서 출력
            if (attackarr[j][i] == 0 && i == y && j == x) { GotoXY(j, i); printf("X"); heartcheck(); printhealth(health); }//캐릭터와 겹치는 경우 health(체력)이 1 감소-heartcheck함수가 체력을 1 감소시키며 체력이 0이여서 게임이 끝나야하는지를 확인-->이후 게임이 끝나지 않는다면 남은 체력을 표시하는 '바([ ■■■■■■      ])'를 출력
        }
    }
}
void attackhigh() {//first attack의 윗부분 공격 버전
    GotoXY(12, 12); printf("■"); GotoXY(12, 13); printf("■"); GotoXY(12, 14); printf("■"); GotoXY(12, 15); printf("■");
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0;
    GotoXY(12, 12); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 13); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 14); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 15); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}
void attacklow() {//first attack의 아랫부분 공격 버전
    GotoXY(12, 18); printf("■"); GotoXY(12, 19); printf("■"); GotoXY(12, 20); printf("■"); GotoXY(12, 21); printf("■");
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0;
    GotoXY(12, 18); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 19); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 20); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 21); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}
void attackright() {//first attack의 오른쪽부분 공격 버전
    GotoXY(26, 3); printf("■■■■");
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0;
    GotoXY(26, 3); printf("■■■■"); GotoXY(26, 4); printf("■■■■"); GotoXY(26, 5); printf("■■■■"); GotoXY(26, 6); printf("■■■■"); GotoXY(26, 7); printf("■■■■"); GotoXY(26, 8); printf("■■■■"); GotoXY(26, 9);    printf("■■■■");   GotoXY(26, 10);    printf("■■■■");    GotoXY(26, 11);    printf("■■■■");    GotoXY(26, 12);    printf("■■■■");    GotoXY(26, 13);    printf("■■■■");    GotoXY(26, 14);    printf("■■■■");    GotoXY(26, 15);    printf("■■■■");    GotoXY(26, 16);    printf("■■■■");    GotoXY(26, 17);    printf("■■■■");    GotoXY(26, 18);    printf("■■■■");    GotoXY(26, 19);    printf("■■■■");   GotoXY(26, 20);   printf("■■■■");   GotoXY(26, 21);   printf("■■■■");   GotoXY(26, 22);   printf("■■■■");   GotoXY(26, 23);   printf("■■■■");
}
void attackleft() {//first attack의 왼쪽부분 공격 버전
    GotoXY(20, 3); printf("■■■■");
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0;
    GotoXY(20, 3); printf("■■■■"); GotoXY(20, 4); printf("■■■■"); GotoXY(20, 5); printf("■■■■"); GotoXY(20, 6); printf("■■■■"); GotoXY(20, 7); printf("■■■■"); GotoXY(20, 8); printf("■■■■"); GotoXY(20, 9);    printf("■■■■");   GotoXY(20, 10);    printf("■■■■");    GotoXY(20, 11);    printf("■■■■");    GotoXY(20, 12);    printf("■■■■");    GotoXY(20, 13);    printf("■■■■");    GotoXY(20, 14);    printf("■■■■");    GotoXY(20, 15);    printf("■■■■");    GotoXY(20, 16);    printf("■■■■");    GotoXY(20, 17);    printf("■■■■");    GotoXY(20, 18);    printf("■■■■");    GotoXY(20, 19);    printf("■■■■");   GotoXY(20, 20);   printf("■■■■");   GotoXY(20, 21);   printf("■■■■");   GotoXY(20, 22);   printf("■■■■");   GotoXY(20, 23);   printf("■■■■");
}
void attack4() {//first attack의 4방향 전체 공격 버전
    printgameheart(x, y);
    printsqure();
    GotoXY(12, 12); printf("■"); GotoXY(12, 13); printf("■"); GotoXY(12, 14); printf("■"); GotoXY(12, 15); printf("■");
    GotoXY(12, 18); printf("■"); GotoXY(12, 19); printf("■"); GotoXY(12, 20); printf("■"); GotoXY(12, 21); printf("■");
    GotoXY(26, 3); printf("■■■■");
    GotoXY(20, 3); printf("■■■■");
    timerstart(); timertime = timerend(); while (timertime < 0.3) { move(); timertime = timerend(); } timertime = 0;
    GotoXY(12, 12); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 13); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 14); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 15); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    GotoXY(12, 18); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 19); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 20); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); GotoXY(12, 21); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    GotoXY(26, 3); printf("■■■■"); GotoXY(26, 4); printf("■■■■"); GotoXY(26, 5); printf("■■■■"); GotoXY(26, 6); printf("■■■■"); GotoXY(26, 7); printf("■■■■"); GotoXY(26, 8); printf("■■■■"); GotoXY(26, 9);    printf("■■■■");   GotoXY(26, 10);    printf("■■■■");    GotoXY(26, 11);    printf("■■■■");    GotoXY(26, 12);    printf("■■■■");    GotoXY(26, 13);    printf("■■■■");    GotoXY(26, 14);    printf("■■■■");    GotoXY(26, 15);    printf("■■■■");    GotoXY(26, 16);    printf("■■■■");    GotoXY(26, 17);    printf("■■■■");    GotoXY(26, 18);    printf("■■■■");    GotoXY(26, 19);    printf("■■■■");   GotoXY(26, 20);   printf("■■■■");   GotoXY(26, 21);   printf("■■■■");   GotoXY(26, 22);   printf("■■■■");   GotoXY(26, 23);   printf("■■■■");
    GotoXY(20, 3); printf("■■■■"); GotoXY(20, 4); printf("■■■■"); GotoXY(20, 5); printf("■■■■"); GotoXY(20, 6); printf("■■■■"); GotoXY(20, 7); printf("■■■■"); GotoXY(20, 8); printf("■■■■"); GotoXY(20, 9);    printf("■■■■");   GotoXY(20, 10);    printf("■■■■");    GotoXY(20, 11);    printf("■■■■");    GotoXY(20, 12);    printf("■■■■");    GotoXY(20, 13);    printf("■■■■");    GotoXY(20, 14);    printf("■■■■");    GotoXY(20, 15);    printf("■■■■");    GotoXY(20, 16);    printf("■■■■");    GotoXY(20, 17);    printf("■■■■");    GotoXY(20, 18);    printf("■■■■");    GotoXY(20, 19);    printf("■■■■");   GotoXY(20, 20);   printf("■■■■");   GotoXY(20, 21);   printf("■■■■");   GotoXY(20, 22);   printf("■■■■");   GotoXY(20, 23);   printf("■■■■");
}
void attackcross() {//대각선 공격 방향 표시 후 공격
    printgameheart(x, y); printsqure();
    GotoXY(17, 9);
    printf("■■");
    GotoXY(25, 9);
    printf("■■");
    GotoXY(17, 10);
    printf("■■■■■■■■■■■■■■■■");
    GotoXY(18, 11);
    printf("■                        ■");
    GotoXY(18, 12);
    printf("■                        ■");
    GotoXY(18, 13);
    printf("■                        ■");
    GotoXY(18, 14);
    printf("■                        ■");
    GotoXY(18, 15);
    printf("■                        ■");
    GotoXY(18, 16);
    printf("■                        ■");
    GotoXY(18, 17);
    printf("■                        ■");
    GotoXY(18, 18);
    printf("■                        ■");
    GotoXY(18, 19);
    printf("■                        ■");
    GotoXY(18, 20);
    printf("■                        ■");
    GotoXY(18, 21);
    printf("■                        ■");
    GotoXY(18, 22);
    printf("■                        ■");
    GotoXY(18, 23);
    printf("■■■■■■■■■■■■■■");
    timerstart(); timertime = timerend(); while (timertime < 1) { move(); timertime = timerend(); } timertime = 0; //1초 타이머
    GotoXY(18, 10);
    printf("■■■■■■■■■■■■■■");
    GotoXY(18, 11);
    printf("■■■                ■■■");
    GotoXY(18, 12);
    printf("■■■■            ■■■■");
    GotoXY(18, 13);
    printf("■  ■■■        ■■■  ■");
    GotoXY(18, 14);
    printf("■    ■■■    ■■■    ■");
    GotoXY(18, 15);
    printf("■      ■■■■■■      ■");
    GotoXY(18, 16);
    printf("■         ■■■         ■");
    GotoXY(18, 17);
    printf("■         ■■■         ■");
    GotoXY(18, 18);
    printf("■      ■■■■■■      ■");
    GotoXY(18, 19);
    printf("■    ■■■    ■■■    ■");
    GotoXY(18, 20);
    printf("■  ■■■        ■■■  ■");
    GotoXY(18, 21);
    printf("■■■■            ■■■■");
    GotoXY(18, 22);
    printf("■■■                ■■■");
    GotoXY(18, 23);
    printf("■■■■■■■■■■■■■■");
}
void attackrandom(int n) {//랜덤 공격 함수
    for (int i = 12; i < 24; i++)
        for (int j = 19; j < 41; j++)
            attackarr[j][i] = 153;//공격좌표 2차원 배열을 153으로 초기화
    for (int j = 0; j < n; j++) { int attx; int atty; atty = rand() % 12 + 11; attx = rand() % 12 + 19; attackarr[attx][atty] = 0; }//랜덤 공격위치를 함수에 들어온 값만큰 설정
    system("cls");//콘솔 초기화
    printsqure();//이동 가능 구역 표시
    printattackarea();//공격할 구역 표시
    printgameheart(x, y);//공격할 구역에 가려졌을 수도 있는 캐릭터 재출력
    timerstart(); double timertime = timerend(); while (timertime < 0.7) { move(); printattackarea(); timertime = timerend(); timebar(timertime, 0.7); } timertime = 0;//0.7초 타이머
    printsqure();//이동 가능 구역 표시
    attack1();//공격 구역 표시
    printgameheart(x, y);//공격한 구역에 가려졌을 수도 있는 캐릭터 재출력
    timerstart(); timertime = timerend(); while (timertime < 2) { move(); scorecalculate(); timertime = timerend(); timebar(timertime, 2); } timertime = 0;//2초 타이머-->점수를 얻기 위해 공격했던 부분을 지나가며 점수를 먹을 수 있는 시간
    printsqure();
}
void attackfourwayup() {//이동가능 구역의 윗부분으로 가면 체력이 닳지 않는 공격
    GotoXY(10, 3); printf("^^^^^^^^^^");
    timerstart(); timertime = timerend(); while (timertime < afwtime) { qjmove(); scorecalculate(); timertime = timerend(); timebar(timertime, afwtime); } timertime = 0;//afwtime(attack four way공격의 제한 시간) 타이머
    if (y != 11) { heartcheck();  printhealth(health); }//이동가능 구역의 윗부분이 아니라면 체력 감소
}
void attackfourwaydown() {//이동가능 구역의 아랫부분으로 가면 체력이 닳지 않는 공격
    GotoXY(10, 3); printf("DDDDDDDDDD");
    timerstart(); timertime = timerend(); while (timertime < afwtime) { qjmove(); scorecalculate(); timertime = timerend(); timebar(timertime, afwtime); } timertime = 0;//afwtime(attack four way공격의 제한 시간) 타이머
    if (y != 22) { heartcheck();  printhealth(health); }//이동가능 구역의 아랫부분이 아니라면 체력 감소
}
void attackfourwayright() {//이동가능 구역의 오른쪽 부분으로 가면 체력이 닳지 않는 공격
    GotoXY(10, 3); printf(">>>>>>>>>>");
    timerstart(); timertime = timerend(); while (timertime < afwtime) { qjmove(); scorecalculate(); timertime = timerend(); timebar(timertime, afwtime); } timertime = 0;//afwtime(attack four way공격의 제한 시간) 타이머
    if (x != 30) { heartcheck(); printhealth(health); }//이동가능 구역의 오른쪽 부분이 아니라면 체력 감소
}
void attackfourwayleft() {//이동가능 구역의 왼쪽 부분으로 가면 체력이 닳지 않는 공격
    GotoXY(10, 3); printf("<<<<<<<<<<");
    timerstart(); timertime = timerend(); while (timertime < afwtime) { qjmove(); scorecalculate(); timertime = timerend(); timebar(timertime, afwtime); } timertime = 0;//afwtime(attack four way공격의 제한 시간) 타이머
    if (x != 19) { heartcheck(); printhealth(health); }//이동가능 구역의 왼쪽 부분이 아니라면 체력 감소
}
//이동 명령어
void move() {
    printXY();
    gkd = GetKeyDown();//키입력
    if (gkd != 0) {
        if (gkd == 'w') { deletegameheart(x, y); if (barrier(x, y - 1)) { y -= 1; printgameheart(x, y); } else printgameheart(x, y); gkd = 0; }//w키 눌린경우 캐릭터 y축좌표 감소(아랫방향이 y축 증가방향임)
        if (gkd == 's') { deletegameheart(x, y); if (barrier(x, y + 1)) { y += 1; printgameheart(x, y); } else printgameheart(x, y); gkd = 0; }//s키 눌린경우 캐릭터 y축좌표 증가(아랫방향이 y축 증가방향임)
        if (gkd == 'a') { deletegameheart(x, y); if (barrier(x - 1, y)) { x -= 1; printgameheart(x, y); } else printgameheart(x, y); gkd = 0; }//a키 눌린경우 캐릭터 x축좌표 감소(오른쪽 방향이 x축 증가방향임)
        if (gkd == 'd') { deletegameheart(x, y); if (barrier(x + 1, y)) { x += 1; printgameheart(x, y); } else printgameheart(x, y); gkd = 0; }//d키 눌린경우 캐릭터 x축좌표 증가(오른쪽 방향이 x축 증가방향임)
        printXY();
    }
}
void qjmove() {
    printXY();
    gkd = GetKeyDown();
    if (gkd != 0) {
        if (gkd == 'w') { deletegameheart(x, y); y = 11;  printgameheart(x, y);  gkd = 0; GotoXY(36, 12); printf("■■■■■■"); Sleep(100); GotoXY(36, 12); printf("            "); }//w키 눌린경우 캐릭터 이동가능 거리의 가장 위로 이동 + 윗 방향으로 갔다는 표시 출력
        if (gkd == 's') { deletegameheart(x, y); y = 22;  printgameheart(x, y);  gkd = 0; GotoXY(36, 19); printf("■■■■■■"); Sleep(100); GotoXY(36, 19); printf("            "); }//s키 눌린경우 캐릭터 이동가능 거리의 가장 아래로 이동 + 아랫 방향으로 갔다는 표시 출력
        if (gkd == 'a') { deletegameheart(x, y); x = 19;  printgameheart(x, y);  gkd = 0; for (int i = 0; i < 6; i++) { GotoXY(35, i + 13); printf("■"); } Sleep(100); for (int i = 0; i < 6; i++) { GotoXY(35, i + 13); printf("  "); } }//a키 눌린경우 캐릭터 이동가능 거리의 가장 오른쪽으로 이동 + 오른쪽 방향으로 갔다는 표시 출력
        if (gkd == 'd') { deletegameheart(x, y); x = 30;  printgameheart(x, y);  gkd = 0; for (int i = 0; i < 6; i++) { GotoXY(42, i + 13); printf("■"); } Sleep(100); for (int i = 0; i < 6; i++) { GotoXY(42, i + 13); printf("  "); } }//d키 눌린경우 캐릭터 이동가능 거리의 가장 왼쪽으로 이동 + 왼쪽 방향으로 갔다는 표시 출력
        printXY();
    }
}
//타이머 함수
void timebar(double nowtime, double finaltime) {//타이머 진행 현황 출력-->현재시간과 최종적으로 타이머가 끝나는 시간을 입력받아 백분율로 표시
    int timebarx = 19, timebary = 9;
    double persentage = (double)(nowtime / finaltime);
    if (persentage < 0.05) { GotoXY(timebarx, timebary);                            printf("[--------------------]"); }
    else if (persentage >= 0.05 && persentage < 0.15) { GotoXY(timebarx, timebary); printf("[▶------------------]"); }
    else if (persentage >= 0.15 && persentage < 0.25) { GotoXY(timebarx, timebary); printf("[▶▶----------------]"); }
    else if (persentage >= 0.25 && persentage < 0.35) { GotoXY(timebarx, timebary); printf("[▶▶▶--------------]"); }
    else if (persentage >= 0.35 && persentage < 0.45) { GotoXY(timebarx, timebary); printf("[▶▶▶▶------------]"); }
    else if (persentage >= 0.45 && persentage < 0.55) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶----------]"); }
    else if (persentage >= 0.55 && persentage < 0.65) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶▶--------]"); }
    else if (persentage >= 0.65 && persentage < 0.75) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶▶▶------]"); }
    else if (persentage >= 0.75 && persentage < 0.85) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶▶▶▶----]"); }
    else if (persentage >= 0.85 && persentage < 0.95) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶▶▶▶▶--]"); }
    else if (persentage >= 0.95 && persentage <= 1) { GotoXY(timebarx, timebary); printf("[▶▶▶▶▶▶▶▶▶▶]"); }
}
double betweentime;
void timerstart() { betweentime = 0; start = clock(); }//타이머 시작 시간 저장
double timerend() {
    end = clock();//타이머 종료시간 저장
    betweentime = (double)(end - start) / CLOCKS_PER_SEC; //초단위 변환
    return betweentime;//시간 간격 반환
}
void scorecalculate() {//score 책정
    if (attackarr[y][x] == 0 && scorevisited[x][y] == 0) {
        score += 1;
        scorevisited[x][y] = 1;
        GotoXY(3, 3);
        printf("score:%d", score);
    }
}
void heartcheck() {//남은 체력 확인
    health -= 1;
    printhealth(health);
    if (health < 0) {
        GotoXY(x, y);
        printf("💔");
        Sleep(1000);
        gameover();
        system("pause");
    }
}
void Render(int x, int y) {
    HDC hDC, hMemDC;
    static HDC hBackDC;
    HBITMAP hBitmap, hOldBitmap, hBackBitmap;
    BITMAP Bitmap; RECT WindowRect; GetWindowRect(hWnd, &WindowRect); hDC = GetDC(hWnd); hBackDC = CreateCompatibleDC(hDC); hMemDC = CreateCompatibleDC(hDC); hBackBitmap = CreateCompatibleBitmap(hDC, WindowRect.right, WindowRect.bottom); hOldBitmap = (HBITMAP)SelectObject(hBackDC, hBackBitmap); hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1)); GetObject(hBitmap, sizeof(BITMAP), &Bitmap); SelectObject(hMemDC, hBitmap); BitBlt(hBackDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, hMemDC, 0, 0, SRCCOPY); BitBlt(hDC, x, y, x + Bitmap.bmWidth, y + Bitmap.bmHeight, hBackDC, 0, 0, SRCCOPY); DeleteObject(SelectObject(hBackDC, hBackBitmap)); DeleteObject(hBitmap); DeleteDC(hBackDC); DeleteDC(hMemDC); ReleaseDC(hWnd, hDC);
}