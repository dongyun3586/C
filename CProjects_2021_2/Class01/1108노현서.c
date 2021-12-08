#include<stdio.h>
#include<windows.h>
#include<conio.h> //kbhit
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#define GEOY 12
#define OBSY 20
#define OBSX 45

//콘솔을 정하는 함수
void SetConsoleView()
{
    system("mode con:cols=100 lines=25"); //콘솔 크기(100이 가로, 25가 세로)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);//글자 색을 지정
    system("title Ceometry Dash. By RoHyeonseo.");//콘솔에 뜨는 프로그램명 지정
}

//커서의 위치 이동 함수
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//누른 키를 반환
int key()
{
    if (_kbhit() != 0) //만약 어떤 키를 눌렀으면
    {
        return _getch(); //getch()로 입력받아서 반환
    }
    return 0;
}

//캐릭터 생성
void character(int y)
{
    gotoxy(0, y);
    printf(" \n");
    printf("\n");
    printf("\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("    &&&&&&&&    \n");
    printf("    && && &&    \n");
    printf("    &&&&&&&&    \n");
    printf("    &&    &&    \n");
    printf("    &&&&&&&&    \n");
}

//장애물 생성
void obstacle(int x)
{
    srand(time(NULL)); //시간에 따라서 윗부분이 출력되고 안되고 설정해봄
    int i = rand() % 3 + 1;
    gotoxy(x, OBSY);
    if (i == 3 || i == 2 || i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 1);
    if (i == 2 || i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 2);
    if (i == 1)printf("\n");
    else printf(" !! ");
    gotoxy(x, OBSY + 3);
    printf(" !! ");
    gotoxy(x, OBSY + 4);
    printf(" !! ");

}


//게임오버 함수
void  gameover(const int score)
{
    system("cls"); //콘솔을 깨끗하게 해줌
    int x = 18;
    int y = 8;
    gotoxy(x, y);
    printf("---------------------------");
    gotoxy(x, y + 1);
    printf("*****G A M E O V E R*******");
    gotoxy(x, y + 2);
    printf("---------------------------");
    gotoxy(x, y + 5);
    printf("점수 : %d", score);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

int bump(const int obsx, const int geoy)
{
    gotoxy(0, 0);
    printf("obsx : %d, geoy : %d", obsx, geoy);
    if (obsx <= 8 && obsx >= 4 && geoy > 8)
        //장애물의 x좌표가 4에서 8 사이(거의 왼쪽 끝) 일때 y좌표가 8보다 크면(8 위치보다 아래 있으면)
    {
        return 1;//충돌했다 o
    }
    return 0; //충돌 안했다
}

int jumpup(int* score, int* jumpscore) //jump 할때마다 score,jumpscore 모두에 점수를 더해줌
//두 변수를 한번에 바꾸기 위해 포인터 사용
{
    *score += 10; *jumpscore += 10;
}

int main()
{
    SetConsoleView();

    while (1)
    {
        int status = 0; //점프에 대한 변수(점프 중이면 1, 아니면 0)
        int geoy = GEOY; //캐릭터의 초기 y값
        int obsx = OBSX; //장애물의 초기 x값(오른쪽)

        int score = 0, jumpscore = 0;//점수
        clock_t start, now;  //1초마다 점수 줄 때 필요한 변수  
        start = clock();

        while (1)  //gameover창을 띄우려고 루프를 하나 더 만들어줌
        {
            if (bump(obsx, geoy))
                break;
            character(geoy);        //캐릭터 생성(매번 루프마다 생성해줘야함! 커서의 위치가 매번 바뀌니까)
            obstacle(obsx);        //장애물 생성

            if (key() == ' ')//스페이스바를 누르면
            {
                status = 1;    //점프를 함        
            }

            if (status) //만약 점프 중이면
            {
                geoy -= 3; //캐릭터를 위로 올려줌(y값이 작아질수록 위쪽임)
                jumpup(&score, &jumpscore);
            }
            else
            {
                geoy += 3; //점프 중이 아니면 아래로 내려주기
            }
            if (geoy >= GEOY)
            {
                geoy = GEOY; //근데 만약 초기 상태보다 아래 있으면 초기값으로 계속 이동시켜주기
            }

            //장애물
            obsx -= 2; //장애물을 왼쪽으로 이동(x 커질수록 왼쪽)
            if (obsx <= 0)
            {
                obsx = OBSX;
            }

            if (geoy <= 3)
            {
                status = 0;
            }

            now = clock();            //현재시간 받아오기
            if (((now - start) / 1000) >= 1)    // 방금 기록했던 시간과 지금 시간의 차이가 1초가 넘으면
            {
                score++;    //점수 추가
                now = clock();    //시작시간 초기화
            }
            Sleep(60);
            system("cls");    //출력해준 거 없애주기

            gotoxy(11, 0);
            printf("Score : %d ", score);
        }
        gameover(score + jumpscore);
    }
    return 0;
}