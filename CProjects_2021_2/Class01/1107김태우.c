#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDE 2  // 다리 폭 설정
#define LENGTH 18  // 다리 길이 설정
#define LIFE 16    // 목숨 설정

int bri[WIDE][LENGTH + 1];      // 다리를 넣을 배열
int dieposition[LENGTH + 1];        //죽는 위치 관련 배열
int life = LIFE;               // 목숨 설정
int a = 0, b = 96, c = 308, d = 62, e = 21, f = 453, g = 244, h = 151, i = 407, j = 101, k = 322, l = 212, m = 360, n = 17, o = 218, p = 67, q = 456;
int* person[LIFE + 1] = { &a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q };    // 실제 오징어 게임 참가자 번호 설정(포인터 배열 활용)


void SetBridge();                 // 다리 설정
void reset();                     // 다리 초기화
void PrintBridge(int s, int p);                  // 다리와 현재 위치 출력
void end(int l, int p);                          // 게임 종료 함수
void game();                                     // 게임 진행 함수
void printlife();                                // 목숨 출력 함수
void explain();                                  // 게임 설명 함수

int main()
{
    explain();    // 게임 설명
    SetBridge();    // 다리 설정
    game();     // 게임 진행
    return 0;
}

void explain()          // 게임 설명 함수
{
    // 오징어 게임 실제 대사 입력
    printf("○△□\n");
    Sleep(500);
    printf("오징어 게임\n");
    Sleep(1100);
    system("cls");
    printf("다섯 번째 게임에 오신 참가자 여러분을 환영합니다.\n");
    Sleep(500);
    printf("다섯 번째 게임은 징검다리 건너기 입니다.\n");
    Sleep(1100);
    system("cls");
    printf("앞에 보이는 한 쌍의 유리는 두 가지 유리\n");
    Sleep(500);
    printf("강화 유리와 일반 유리로 되어 있습니다.\n");
    Sleep(1100);
    system("cls");
    printf("강화 유리는 두 사람의 무게도 버틸 수 있을 만큼 튼튼하지만\n");
    Sleep(500);
    printf("일반 유리는 한 사람만 올라가도 깨져 버립니다.\n");
    Sleep(1100);
    system("cls");
    printf("참가자들은 앞에 놓인 한 쌍의 유리 중에\n");
    Sleep(500);
    printf("어느 쪽이 강화 유리인지를 판단해서\n");
    Sleep(500);
    printf("그것들을 밟고 열여덟 쌍의 다리를 지나\n");
    Sleep(500);
    printf("반대편까지 무사히 건너가면 통과입니다.\n");
    Sleep(1100);
    system("cls");
}

void SetBridge()            // 다리 설정 함수
{
    srand(time(NULL));          // 랜덤 함수 이용
    for (int i = 1; i <= LENGTH; i++)
        bri[rand() % WIDE][i] = 1;           // 0이면 강화 유리, 1이면 일반 유리
}

void reset()            // 다리 초기화 함수
{
    printlife();            // 목숨 출력 함수
    for (int i = 0; i < WIDE; i++)
    {
        if (i == 1)
            printf("↓");
        printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if ((dieposition[j] == 1) && (bri[i][j] == 1))
            {
                printf("□ ");
            }
            else
                printf("■ ");
        }
        printf("\n");
    }
}

void PrintBridge(int s, int p)          // 다리 출력 함수
{
    printlife();            // 목숨 출력 함수
    for (int i = 0; i < WIDE; i++)
    {
        if (s == i)
        {
            for (int i = 0; i < 2 * p - 2; i++)
                printf("  ");
            printf("  ↓\n%d", i + 1);
        }
        else
            printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if ((dieposition[j] == 1) && (bri[i][j] == 1))
            {
                printf("□ ");
            }
            else
                printf("■ ");
        }
        printf("\n");
    }
}

void printlife()            // 목숨 출력 함수
{
    for (int i = 1; i <= LIFE - life; i++)
        printf("♡");            // 없어진 목숨 출력
    for (int i = 1; i <= life; i++)
        printf("♥");            // 남은 목숨 출력
    printf("\n\n");
    for (int i = 1; i <= LENGTH; i++)
        printf("  %2d", i);
    printf("\n");
}

void end(int l, int p)          // 게임 종료 함수
{
    system("cls");
    printlife();            // 목숨 출력 함수
    for (int i = 0; i < WIDE; i++)
    {
        printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if (bri[i][j] == 0)
                printf("■ ");           // 강화유리인 경우 색칠된 사각형 출력
            else
                printf("□ ");           // 일반유리인 경우 비어있는 사각형 출력
        }
        printf("\n");
    }
    if (l == 0)
        printf("\n전원 탈락\n");            // 게임 실패한 경우 전원 탈락 출력
    else if (p == LENGTH)
    {
        printf("\n");
        for (int i = LIFE - life + 1; i <= LIFE; i++)
        {
            if (i != LIFE)
                printf("%d번, ", *person[i]);
            if (i == LIFE)
                printf("%d번 ", *person[i]);
        }
        printf("참가자 생존\n\n");           // 성공한 경우 생존한 참가자 번호 출력
    }
}

void game()         // 게임 진행 함수
{

    int position = 0;
    int select = 0;
    reset();
    while (1)
    {
        printf("\n\n어느 길로 가시겠습니까? : 1, 2\n");
        scanf("%d", &select);           // 사용자 입력 받기
        select--;
        while (select != 0 && select != 1)
        {
            printf("다시 입력하세요\n");           // 0,1이 아닌 숫자를 입력한 경우 다시 입력 받기
            scanf("%d", &select);
            select--;
        }
        if (bri[select][position + 1] == 1)             // 일반 유리를 선택한 경우
        {
            life--;
            dieposition[position + 1] = 1;
            position = 0;
            system("cls");
            reset();            // 목숨 1개 삭제, 처음 위치로 이동, 초기화
        }
        else                                           // 강화 유리를 선택한 경우
        {
            position++;
            system("cls");
            PrintBridge(select, position);          // 한 칸 앞으로 이동
        }
        if ((life == 0) || (position == LENGTH))            // 남은 목숨이 없거나 다리 끝까지 도달한 경우
            break;              // 게임 중지
    }
    end(life, position);            // 게임 종료 함수
    Sleep(2000);
    system("cls");
    printf("당신도 게임에 참가하시겠습니까?\n");
    Sleep(3000);
    system("cls");
    printf("○△□\n010-4092-6813\n");
}