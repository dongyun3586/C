/*   이 게임의 아이디어는 1209 염예찬이 고안해낸게 절대 아니라는 사실을 밝힙니다   */


//만든 헤더파일을 통해 코드의 가독성을 높힘
#include "snakeheader.h"

//좌표값을 간편하게 저장하기 위한 구조체 생성
typedef struct {
    int x;
    int y;
}Point;

Point* snakebody;

int foodlocationx, foodlocationy; //food의 좌표값을 저장 
int snakelength; //몸길이를 기억 
int speed; //게임 속도 (Sleep()함수 속에 넣어서 속도를 저장)
int score; //점수 저장
int dir; //이동방향 저장 (direction)
int key; //입력받은 키 저장

void startTitle(void);
void reset(void);
void drawmap(void);
void move(int dir);
int checkbodycrash(void);
void gameoverTitle(void);
void food(void);
int crashmap(void);
void printsnake(void);


int main(void) {

    CursorView(); //캐럿 없에기
    snakebody = (Point*)malloc(100 * sizeof(Point));

    startTitle();

    while (1) {
        if (_kbhit()) do {
            key = _getch();
        } while (key == 224); //키 입력받음
        Sleep(speed);

        switch (key) { //입력받은 키를 파악하고 실행  
        case LEFTKEY:
        case RIGHTKEY:
        case TOPKEY:
        case DOWNKEY:
            if ((dir == LEFTKEY && key != RIGHTKEY) || (dir == RIGHTKEY && key != LEFTKEY) || (dir == TOPKEY && key != DOWNKEY) || (dir == DOWNKEY && key != TOPKEY)) {//180회전이동을 방지하기 위해 필요 (머리가 갑자기 몸통에 충동하는 일이 없도록
                dir = key;
            }
            key = 0; // 키값을 저장하는 함수를 reset 
            break;
        }

        move(dir);
    }
}

void startTitle(void) {

    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림

    drawmap();    //맵 테두리를 그림 
    for (int i = MAPY + 1; i < MAPY + MAPHEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
        for (int j = MAPX + 1; j < MAPX + MAPWIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 5, "   +--------------------------+");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 6, "   |       스네이크 게임      |");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 7, "   +--------------------------+");

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "       < PRESS ANY KEY >");

    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 11, "   () ←,→,↑,↓ : Move    ");
    gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 12, "   () ESC : Quit              ");

    while (1) {
        if (_kbhit()) { //키입력받음 
            key = _getch();
            if (key == 27) exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        }
        gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "       < PRESS ANY KEY > ");
        Sleep(400);
        gotoxy(MAPX + (MAPWIDTH / 2) - 7, MAPY + 9, "                            ");
        Sleep(400);

    }
    reset(); // 게임을 초기화  
}

void reset(void) {
    int i;
    system("cls");
    drawmap(); //맵 테두리를 그림 
    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버려야함 (눌려져 있던 키로 인해 게임이 시작하자마자 이상한 방향으로 흘러가는것을 방지)

    snakelength = 5; //뱀 길이 초기화 
    score = 0; //점수 초기화 

    dir = LEFTKEY;
    speed = 100; // 속도를 100으로 초기화 (화면이 깜빡거리는 속도를 0.1초로 기본설정)

    for (i = 0; i < snakelength; i++) {
        snakebody[i].x = MAPWIDTH / 2 + i;
        snakebody[i].y = MAPHEIGHT / 2;
        gotoxy(MAPX + snakebody[i].x, MAPY + snakebody[i].y, "몸"); //뱀 몸통 그림
    }
    gotoxy(MAPX + snakebody[0].x, MAPY + snakebody[0].y, "뱀"); //뱀 머리 그림 (머리는 1개이다)
    food(); // food 생성  
}

void drawmap(void) { //맵 테두리 그리는 함수 
    int i, j;
    for (i = 0; i < MAPWIDTH; i++) {
        gotoxy(MAPX + i, MAPY, "■");
    }
    for (i = MAPY + 1; i < MAPY + MAPHEIGHT - 1; i++) {
        gotoxy(MAPX, i, "■");
        gotoxy(MAPX + MAPWIDTH - 1, i, "■");
    }
    for (i = 0; i < MAPWIDTH; i++) {
        gotoxy(MAPX + i, MAPY + MAPHEIGHT - 1, "■");
    }
}

int checkbodycrash(void) {
    int flag = 0;
    for (int i = 1; i < snakelength; i++) {
        if (snakebody[0].x == snakebody[i].x && snakebody[0].y == snakebody[i].y) {
            flag = 1;
        }
    }
    return flag;
}

int crashmap(void) {
    int flag = 0;
    if (snakebody[0].x == 0 || snakebody[0].x == MAPWIDTH - 1 || snakebody[0].y == 0 || snakebody[0].y == MAPHEIGHT - 1) { //벽과 충돌했을 경우 
        flag = 1;
    }
    return flag;
}

void printsnake(void) {
    int i;
    gotoxy(MAPX + snakebody[snakelength - 1].x, MAPY + snakebody[snakelength - 1].y, "  "); //몸통 마지막을 지움 
    for (i = snakelength - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
        snakebody[i].x = snakebody[i - 1].x;
        snakebody[i].y = snakebody[i - 1].y;
    }
    gotoxy(MAPX + snakebody[0].x, MAPY + snakebody[0].y, "몸"); //머리가 있던곳을 몸통으로 고침 
    if (dir == LEFTKEY) --snakebody[0].x; //방향에 따라 새로운 머리좌표([0].,y[0])값을 변경 
    if (dir == RIGHTKEY) ++snakebody[0].x;
    if (dir == TOPKEY) --snakebody[0].y;
    if (dir == DOWNKEY) ++snakebody[0].y;
    gotoxy(MAPX + snakebody[i].x, MAPY + snakebody[i].y, "뱀"); //새로운 머리좌표값에 머리를 그림 
}

void move(int dir) {
    int i;
    if (snakebody[0].x == foodlocationx && snakebody[0].y == foodlocationy) { //food와 충돌했을 경우 
        score += 10; //점수 증가 
        food(); //새로운 food 추가 
        snakelength++; //길이증가 
        snakebody[snakelength - 1].x = snakebody[snakelength - 2].x; //새로만든 몸통에 값 입력 
        snakebody[snakelength - 1].y = snakebody[snakelength - 2].y;
    }
    if (crashmap() == 1) { //벽과 충돌했을 경우 
        gameoverTitle();
        return;
    }

    if (checkbodycrash() == 1) { //몸과 충돌했을 경우
        gameoverTitle();
        return;
    }

    printsnake();
}

void gameoverTitle(void) { //게임종료 함수 
    system("cls");
    gotoxy(MAPX + (MAPWIDTH / 2) - 6, MAPY + 7, "  게임 오버\n                    점수 : ");
    printf("%d", score);
    gotoxy(MAPX + (MAPWIDTH / 2) - 9, MAPY + 12, " 아무 키나 누르면 게임이 다시 시작됩니다... ");
    Sleep(500);
    while (_kbhit()) _getch(); //키를 누를때까지 기다리는 과정
    key = _getch();
    startTitle();
}

void food(void) {

    int flag = 0;//food가 뱀 몸통좌표에 생길 경우
    gotoxy(MAPX, MAPY + MAPHEIGHT, " YOUR SCORE: "); //점수표시 
    printf("%d", score);
    while (1) {
        flag = 0;
        srand((unsigned)time(NULL)); //난수표생성 
        foodlocationx = (rand() % (MAPWIDTH - 2)) + 1;
        foodlocationy = (rand() % (MAPHEIGHT - 2)) + 1;
        for (int i = 0; i < snakelength; i++) { //food가 뱀 몸통과 겹치는지 확인하는 과정
            if (foodlocationx == snakebody[i].x && foodlocationy == snakebody[i].y) {
                flag = 1; //겹치면 flag를 통해 저장
                break;
            }
        }
        if (flag == 1) {
            continue; //겹쳤을 경우 while문을 다시 시작 
        }
        int randnum = rand() % 100 + 1;
        if (randnum > 0 && randnum <= 70) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "ㅋ"); //안겹쳤을 경우 좌표값에 food를 찍고 
            speed -= 3; //속도 3 증가
            break;
        }
        if (randnum > 70 && randnum <= 95) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "ㅎ"); //안겹쳤을 경우 좌표값에 food를 찍고 
            speed -= 5; //속도 5 증가
            break;
        }
        if (randnum > 95 && randnum <= 100) {
            gotoxy(MAPX + foodlocationx, MAPY + foodlocationy, "ㅌ"); //안겹쳤을 경우 좌표값에 food를 찍고 
            speed += 10; //속도 감소
            break;
        }
    }
}