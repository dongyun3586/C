#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 20        //가로
#define HEIGHT 10        //세로
#define TRUE 1
#define FALSE 0

//적(피할 것)
typedef struct
{
    int x;
    int y;
    //적의 상태 (TRUE, FALSE)로 컨트롤할 것
    int con;
}Enemy;
//플레이어
typedef struct
{
    int x;
}Player;

////지정된 위치로 커서를 이동시키는 함수////
void gotoxy(int x, int y)
{
    //COORD : window.h에 있는 구조체, {SHORT x, SHORT y} 로 구성되어 있다.
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Enemy enemy[WIDTH];
Player player;

//// 초기값 ////
void fvalue()
{
    int i;
    for (i = 0; i < WIDTH; i++)
        (*(enemy + i)).con = FALSE;//enemy[i].con
    //플레이어 처음 위치는 중앙으로
    player.x = WIDTH / 2;
}

//// 피할 적들 처리 ////
/* 적 생성 */
void CreateEnemy()
{
    int i;

    for (i = 0; i < WIDTH; i++)
    {
        //해당 인덱스[i]에 적이 없으면 (FALSE 이면 실행)
        if (!enemy[i].con)
        {
            //가로 (x축) 무작위로 적 출현, 세로(y축)은 출현 위치 항상 일치
            enemy[i].x = rand() % WIDTH;
            enemy[i].y = HEIGHT - 1;
            //적이 출현한 인덱스 [i]의 상태 = TRUE로 변경
            enemy[i].con = TRUE;
            return;
        }
    }
}
/* 적의 움직임 */
void FallEnemy()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //해당 인덱스 [i]에 적이 있으면 (TRUE라면) 움직임 실행
        if (enemy[i].con)
        {
            enemy[i].y--;
        }
    }
}
/* 피하기 성공한 적(바닥에 떨어진 적) 삭제 */
void DelEnemy()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con && enemy[i].y < 0)
            enemy[i].con = FALSE;
    }
}
/* 플레이어가 적에게 닿을 경우 (패배) */
int DamagedPlayer()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //적의 상태가 TRUE && 적의 위치가 y=0 즉 바닥 && 적의 x축 위치 = 플레이어의 x축 위치
        if ((enemy[i].con && enemy[i].y == 0) && (enemy[i].x == player.x))
            return TRUE;
    }
    //닿지 않았으면 FALSE 반환
    return FALSE;
}

//// 플레이어 처리 ////
/* 키 다운 처리 */
int isKeyDown(int key)
{
    //***GetAsyncKey는 키가 눌렸다면 최상위 비트를 1로 설정, 이전에 키가 눌렸다면 최하위 비트를 1로 설정
    //0x8000은 최상위 비트 -> 16진수는 2비트가 4개 모인 비트 -> 0x8000 = 1000 0000 0000 0000를 의미
    // 즉 최하위 비트는 0x0001 -> 0000 0000 0000 0001
    // 따라서 (GetAsyncKeyState(key) & 0x8000) != 0 은 현재 키가 눌려있다면 참(TRUE)--인터넷을 참조함
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

/* 플레이어 이동 (좌/우) */
void MovePlayer()
{
    //왼쪽 방향키 입력 시
    if (isKeyDown(VK_LEFT))
        player.x--;
    if (isKeyDown(VK_RIGHT))
        player.x++;
    //위치 범위 제한
    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
}

//// 게임 화면 출력 ////
void PrintGame()
{
    //모든 화면 clear
    system("cls");

    gotoxy((WIDTH / 2) - 7, HEIGHT + 2);
    printf("                      Made by JYLEE");

    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con)
        {
            //적 위치에 적군 출력
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
            printf("★");
        }
    }
    //플레이어 출력
    gotoxy(player.x, HEIGHT);
    printf("□");

    //바닥 출력
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("▩");
}

//// main 함수 ////
int main(void) {
    fvalue();
    int speed = 50;
    int score = 0;


    do {
        //매번 실행할 때마다 다른 값을 주기 위한 시드값 설정
        srand((int)malloc(NULL));

        CreateEnemy();
        FallEnemy();
        DelEnemy();

        MovePlayer();

        PrintGame();
        //게임의 속도 조절을 위해 Sleep 설정

        Sleep(250 - speed);
        if (speed <= 200) {
            speed += 5;
        }

        score++;
        gotoxy(WIDTH + 5, HEIGHT / 2);
        printf("SCORE:%d", score);
    } while (!(DamagedPlayer()));    //닿지 않으면 반복
}