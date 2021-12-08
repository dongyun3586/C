#include <stdio.h>
#include <memory.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define height 60
#define width 140
#define TOTALENEMYNUMBER 5
#define StructLength 25
#define StructHeight 7
typedef struct
{
    int x;
    int y;
} enemy;
int gun[2] = { 30, 70 }; //조준점 좌표: gun[0]: x좌표, gun[1]: y좌표
int enemynum = 1;// 만들어진 적 수
int score = 0; // 얻은 점수를 저장하는 변수
void printMap(int(*arr)[width], enemy* enemyinfo); // Map 출력하는 함수
void MapInfo(int(*arr)[width], enemy* enemyinfo);//맵 정보를 바꾸는 함수: 이 함수는 arr 배열의 값을 바꿈으로서
void respondEnemy(int(*arr)[width], enemy* enemyinfo);// 적을 만들어 내는 함수
void enemymove(enemy* enemyinfo);//적을 움직이게 하는  함수: 적의 위치정보가 들                    어있는 enemyinfo 구조체 배열의 값을 바꿈으로서 적의 위치를 바꾼다.
void gotoxy(int x, int y) //이 함수는 네이버 블로그를 참고해서 만들었습니다.
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void GunInfo(int(*arr)[width], enemy* enemyinfo);
int main()
{
    enemy enemyinfo[TOTALENEMYNUMBER]; // 적의 위치 정보를 담은 배열의 크기
    enemyinfo[0].x = 9;
    enemyinfo[0].y = 9;
    for (int i = 1; i < TOTALENEMYNUMBER; i++)
    {
        enemyinfo[i].x = 0;
        enemyinfo[i].y = 0;
    }
    int arr[height][width];
    while (enemynum <= TOTALENEMYNUMBER && !(enemyinfo[TOTALENEMYNUMBER - 1].x == 135 && enemyinfo[TOTALENEMYNUMBER - 1].y == 55))
    {
        respondEnemy(arr, enemyinfo);
        MapInfo(arr, enemyinfo);
        printMap(arr, enemyinfo);
        system("cls");
        enemymove(enemyinfo);
    }
    system("cls");
    Sleep(1);
    while (1)
    {
        printf("점수: %d\n", score);//만약 점수가 굉장히 빠른 시간 동안만 보이면 while(1)로 점수를 확인하세요.
    }    Sleep(1);
    return 0;
}
void printMap(int(*arr)[width], enemy* enemyinfo)   // MAP을 출력하는 함수
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arr[i][j] == 1)
            {
                printf("*"); // 적의 그림을 *로 했다.
            }
            else if (arr[i][j] == 4)
            {
                printf("@");// 조준점의 그림을 @로 했다.
            }
            else
            {
                printf(" ");// 아무것도 없는 곳에서 출력하는 정보
            }
        }
        printf("\n");
    }
    gotoxy(0, 0);


}
void MapInfo(int(*arr)[width], enemy* enemyinfo)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = 0;// arr 배열의 값을 0으로 초기화
        }
    }
    for (int i = 0; i < enemynum; i++)
    {
        if (enemyinfo[i].x != 55 && enemyinfo[i].y != 135)
        {
            for (int j = enemyinfo[i].y - 4; j < enemyinfo[i].y + 4; j++)
            {
                for (int p = enemyinfo[i].x - 4; p < enemyinfo[i].x + 4; p++)
                {
                    arr[j][p] = 1;// 적의 중심으로부터 위 4, 아래 3, 왼쪽 4, 오른쪽 3만큼을 적의 크기로 했다.
                }
            }
        }
    }
    GunInfo(arr, enemyinfo);// 총 움직임을 담당하는 함수.
    arr[gun[0]][gun[1]] = 4;// 조준점의 좌표는 arr 배열에서 4로 처리한다.

}

void respondEnemy(int(*arr)[width], enemy* enemyinfo) // 적 생성하는 함수
{
    srand(time(NULL));
    if (rand() % 2 == 1 && enemyinfo[enemynum - 1].x > 10 && enemynum < TOTALENEMYNUMBER)// rand 함수의 값을
    {
        enemyinfo[enemynum].x = 5;
        enemyinfo[enemynum].y = rand() % 50 + 5;
        enemynum++;
    }
}
void enemymove(enemy* enemyinfo)// 적 이동하는 함수
{
    for (int i = 0; i < enemynum; i++)
    {
        if (enemyinfo[i].x != 135)  enemyinfo[i].x++;
        else
        {
            enemyinfo[i].y = 55;
            enemyinfo[i].x = 135;
        }
    }
}
void GunInfo(int(*arr)[width], enemy* enemyinfo)
{

    int n;//_getch를 위한 변수4
    n = _getch();
    if (n == 'A' || n == 'a') // 왼쪽으로  이동하는 방향키;
    {
        gun[1]--;

        if (gun[1] <= 0)
            gun[1] = 0;
    }
    if (n == 'W' || n == 'w') // 위로 이동하는 방향키;
    {
        gun[0]--;
        if (gun[0] <= 0)
            gun[0] = 0;
    }
    if (n == 'D' || n == 'd') //D(d): 오른쪽으로 이동하는 방향키
    {
        gun[1]++;
        if (gun[1] >= 139)
        {
            gun[1] = 139;
        }
    }
    if (n == 'S' || n == 's')//S(s): 아래로 이동하는  방향키
    {
        gun[0]++;
        if (gun[0] >= 59)
        {
            gun[0] = 59;
        }
    }
    if (n == 'F' || n == 'f') //F: 사격키(
    {
        if (arr[gun[0]][gun[1]] == 1)
            score++;
    }

}
