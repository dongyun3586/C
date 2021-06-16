#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define W 119 // 방향키 및 각 키보드의 아스키 코드
void PrintStartBoard();//시작 화면 출력
void PlayGame();//게임 시작
void GameRule();//게임 룰 설명
void PrintPicture();//화살표 그림 출력
void gotoxy(int x, int y); //블로그에서 따온 이동 함수
void GameOver();//게임 오버
void CleanPicture();//화살표 그림 지우기
int main() {
    PrintStartBoard();
    while (1) {
        if (_kbhit())
        {
            if (_getch() == W) {
                system("cls");//W 누르면 화면 모두 지우고 게임 시작
                PlayGame();
                return 0;
                exit(1); // 프로그램 종료
            }
        }
    }
}
void PrintStartBoard() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                                    ■\n");
    printf("■  ■  ■  ■        ■■           ■       ■■■■■■■    ■■■■     ■ ■        ■        ■■■■■■■    ■\n");
    printf("■  ■  ■  ■      ■    ■       ■  ■     ■                ■           ■ ■        ■        ■                ■\n");
    printf("■  ■■■  ■■    ■    ■     ■      ■   ■                ■           ■ ■      ■  ■      ■                ■\n");
    printf("■  ■  ■  ■        ■■           ■       ■                ■           ■ ■    ■      ■    ■■■■■■■    ■\n");
    printf("■  ■■■  ■                   ■■■■■   ■■■■■■■    ■■■■   ■■ ■  ■          ■  ■                ■\n");
    printf("■                 ■■■■■                                   ■           ■ ■                  ■                ■\n");
    printf("■  ■                           ■■■■■         ■          ■           ■ ■                  ■■■■■■■    ■\n");
    printf("■  ■                ■■               ■         ■          ■           ■ ■  ■■■■■■■                    ■\n");
    printf("■  ■              ■    ■             ■   ■■■■■■■    ■■■■     ■ ■                                    ■\n");
    printf("■  ■■■■■      ■    ■             ■                                  ■ ■                  ■■■■■■■    ■\n");
    printf("■                    ■■                                                                                            ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                             PRESS W TO START!!!                =                                   ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void gotoxy(int x, int y)

{

    COORD pos = { x, y / 2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void PlayGame() {
    GameRule();
    int random;
    int score = 0;
    clock_t StartClock, EndClock;//시간 측정하는 방법
    float record;
    StartClock = clock();//시작 시각
    while (1) {
        srand(time(NULL));
        random = rand() % 4;//0:up, 1:down, 2:left, 3: right
        PrintPicture(random);//random 값 나온 것에 맞는 화살표 그림
        switch (random) {
        case 0://up
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        goto EXIT;//맞게 눌렀으므로 다음 진행
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 1://down
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        goto EXIT;//맞게 눌렀으므로 다음 진행
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 2://left
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        goto EXIT;//맞게 눌렀으므로 다음 진행
                    case RIGHT:
                        GameOver();
                        break;
                    }
                }
            }
            break;
        case 3://right
            while (1) {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case UP:
                        GameOver();
                        break;
                    case DOWN:
                        GameOver();
                        break;
                    case LEFT:
                        GameOver();
                        break;
                    case RIGHT:
                        goto EXIT;//맞게 눌렀으므로 다음 진행
                    }
                }
            }
            break;

        }
    EXIT://중첩 반복문을 빠져나가야 해서 어쩔 수 없이 사용했습니다.
        score++;
        CleanPicture();
        gotoxy(30, 0);
        printf("%d/30회", score);//오른쪽으로 가서 화살표 누른 횟수 표시
        gotoxy(0, 0);//원래 화살표 출력 위치로 복귀
        if (score == 30) break;
    }
    EndClock = clock();//종료 시각
    record = (float)(EndClock - StartClock) / CLOCKS_PER_SEC;//기록=(종료 시각-처음시각)/(초로 환산)
    system("cls");
    printf("%.3f초 걸렸습니다.", record);//기록은 셋째자리까지 출력
}
void GameRule() {
    printf("<GAME RULE>\n");
    printf("1. 좌측 상단 화면에 화살표 네 방향 중 한 방향이 나옵니다!\n");
    printf("2. 화살표 그림에 맞추어 방향키를 눌러주시면 됩니다!\n");
    printf("3. 만약 잘못 누르면 게임 종료입니다~\n");
    printf("4. 올바른 키를 누르신다면 다음 그림이 즉시 나오고, 바로 다음 화면 키를 누르시면 됩니다.\n");
    printf("5. 총 그림은 30번 나오고, 전부 제대로 누르신다면 마지막에 기록이 나올 겁니다.\n");
    printf("6. 그럼 행운을 빕니다.\n");
    Sleep(3000);//3초 지연
    gotoxy(0, 20);
    printf("[COUNT DOWN]\n");//아래쪽으로 내려가서 카운트다운 5초 시작
    for (int i = 5; i >= 0; i--) {
        gotoxy(0, 24);
        printf("%d", i);
        Sleep(1000);
    }
    system("cls");//전부 지우고 게임 시작
}
void PrintPicture(picture) {
    switch (picture) {
    case 0:
        printf("    ■\n");
        printf("  ■■■\n");
        printf("■  ■  ■\n");
        printf("    ■\n");
        printf("    ■\n");
        break;
    case 1:
        printf("    ■\n");
        printf("    ■\n");
        printf("■  ■  ■\n");
        printf("  ■■■\n");
        printf("    ■\n");
        break;
    case 2:
        printf("    ■\n");
        printf("  ■\n");
        printf("■■■■■\n");
        printf("  ■\n");
        printf("    ■\n");
        break;
    case 3:
        printf("    ■\n");
        printf("      ■\n");
        printf("■■■■■\n");
        printf("      ■\n");
        printf("    ■\n");
        break;
    }
}
void GameOver() {
    int x;
    system("cls");
    srand(time(NULL));
    x = rand() % 5;//랜덤하게 게임종료 대사 출력(심심해서 넣었습니다)
    switch (x) {
    case 0:
        printf("잘못 누르셨습니다.. 이걸 지금 클릭이라고 하신 겁니까?\nㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ\n");
        break;
    case 1:
        printf("잘못 누르셨네요! 대단하십니다!!\n축하드려요~~~\n");
        break;
    case 2:
        printf("잘못 누르셨습니다.. 참으로 놀랍군요!!\n");
        break;
    case 3:
        printf("잘못 누르셨습니다. 한 번 더 시도하시면 좋은 결과가 있을 거에요~~\n화이팅!!!\n");
        break;
    case 4:
        printf("잘못 누르셨네요.. 저런..... ㅋ\n");
        break;
    }
    Sleep(2000);
    printf("■■■■■    ■  ■    ■    ■  ■■■■■  ■■■■■  \n");
    printf("        ■    ■  ■  ■  ■  ■      ■              ■  \n");
    printf("        ■    ■  ■  ■  ■  ■    ■  ■    ■■■■■  \n");
    printf("        ■    ■  ■  ■  ■  ■              ■          \n");
    printf("        ■    ■  ■    ■    ■      ■      ■■■■■  \n");
    printf("        ■■■■  ■              ■■■■■              \n");
    printf("        ■    ■  ■     ■■■                 ■  ■    \n");
    printf("        ■    ■  ■     ■  ■       ■        ■  ■    \n");
    printf("        ■    ■  ■     ■  ■     ■  ■      ■  ■    \n");
    printf("        ■    ■  ■     ■■■       ■    ■■■■■■■\n");
    exit(1);
}
void CleanPicture() {
    gotoxy(0, 0);
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    printf("          \n");
    Sleep(50);//지연을 넣어서 새로운 그림이 나온 걸 플레이어가 확인하게 함
    gotoxy(0, 0);
}
