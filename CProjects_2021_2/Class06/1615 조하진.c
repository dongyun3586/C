#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


#define MoveSpeed 100;
#define BulletSpeed 500;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define W 119 // 방향키 및 각 키보드의 아스키 코드


typedef struct {
    int x;
    int y;
} Coordinate;//좌표 구조체

typedef struct {
    Coordinate coor;
    char shape;
    int shootingTime;
    int direction;
}Player;//플레이어 구조체

typedef struct {
    Coordinate coor;
    char shape;
    int shootingTime;
} Computer;//컴퓨터 구조체

typedef struct {
    Coordinate coor;
    int direction;
} Bullet;//총알 구조체

void StartBoard();
void menu();
void GameRule();
void GameStart();
void PlayerMove(Player* A); // 플레이어의 움직임 함수
void ComputerMove(Computer* A); // 컴퓨터의 (무작위) 움직임 함수
void PrintMember(Coordinate coor, char shape); // 어떤 모양을 지정된 좌표로 이동하여 출력
void Delete(Coordinate coor); // 어떤 좌표에 있는 요소를 지움
void PrintSideLine(); // 게임 내 사이드라인 출력
void PlayerShooting(Player* A, Bullet* X, int* playerShootingCheck); // 플레이어의 발사 함수
void ComputerShooting(Computer* A, Bullet X[4], int computerShootingCheck[5]); // 컴퓨터의 (4방향) 발사 함수
void WinnerCheck(Player* A, Computer* B, Bullet* X, Bullet Y[4]); // 승자 판단
void PlayerWin(); // 플레이어 승리 시
void ComputerWin(); // 컴퓨터 승리 시
void gotoxy(int x, int y)

{

    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
// 지정된 좌표로 이동
void cursor(int n) // 커서 보이기 & 숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//인터넷에서 가져온 커서 깜빡임 제거 코드 // 마우스 깜빡이는 커서 없애는 함수 (인터넷에서 가져옴)

int main() {
    StartBoard();
    Sleep(1000);
    system("cls");
    menu();
}

void StartBoard() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                  ■      ■     ■             ■■■■■■■  ■■■■          ■■■■          ■\n");
    printf("■         ■■■           ■      ■    ■  ■   ■             ■              ■      ■      ■        ■        ■\n");
    printf("■       ■      ■     ■■■■■  ■      ■     ■             ■              ■        ■    ■                  ■\n");
    printf("■             ■         ■  ■    ■■           ■             ■              ■        ■    ■                  ■\n");
    printf("■           ■         ■      ■  ■    ■■■   ■             ■              ■        ■      ■■■■          ■\n");
    printf("■         ■                       ■      ■   ■■             ■■■■■■    ■      ■                ■        ■\n");
    printf("■       ■■■■■                 ■             ■             ■              ■■■■                  ■        ■\n");
    printf("■                                          ■     ■             ■              ■                        ■        ■\n");
    printf("■                                          ■                    ■              ■              ■        ■        ■\n");
    printf("■                                          ■■■■■            ■              ■                ■■■■          ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                  1615   조하진                                                     ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void menu() {
    int n;
    printf("2차원 FPS 게임에 오신 것을 환영합니다!\n");
    printf("1 : Rule\n");
    printf("2 : Start\n");
    while (1) {
        scanf("%d", &n);
        switch (n) {
        case 1:
            GameRule();
            break;
        case 2:
            GameStart();
            break;
        default:
            printf("1,2 중 하나를 누르세요.\n");
            break;
        }
    }

}
void GameRule() {
    printf("*************************************************    Game Rule    *************************************************\n");
    printf("1. 플레이어 모양: o 컴퓨터 모양 : x\n");
    printf("2. 플레이어는 방향키를 통해 4방향으로 움직일 수 있으며, 스페이스바를 누르면 움직이는 방향 쪽으로 총알이 날아갑니다.\n");
    printf("3. 컴퓨터는 랜덤으로 움직이며, 일정시간마다 3~4방향으로 총알을 발사합니다.\n");
    printf("4. 플레이어와 컴퓨터 모두 총알을 한 발 맞으면 사망합니다.\n");
    printf("5. 플레이어와 컴퓨터가 부딪치면 플레이어가 사망합니다.\n");
    printf("6. 벽에 붙어있는 상태에서는 총알이 발사되지 않습니다. 이 점을 유의해주시기 바랍니다.\n");
    printf("7. 컴퓨터가 쏘는 총은 사거리가 있기 때문에 일정 거리 이상 나아가면 총알이 멈춥니다.\n");
    printf("8. 그렇게 바닥에 떨어져 있는 총알은 맞아도 죽지 않습니다.\n");
    printf("9. 동시타 발생 시 무조건 컴퓨터의 승리로 판정됩니다.\n");
    printf("*******************************************************************************************************************\n");
}
void GameStart() {
    Player player = { 0 };
    Computer computer = { 0 };
    Bullet playerBullet = { 0 };
    Bullet computerBullet[4] = { 0 };
    player.coor.x = 10;
    player.coor.y = 10;
    computer.coor.x = 70;
    computer.coor.y = 18;
    player.shape = 'o';
    computer.shape = 'x';
    player.shootingTime = 50;
    computer.shootingTime = 0;
    player.direction = 0;

    int playerShootingCheck = 0;
    int computerShootingCheck[5] = { 0 };
    system("cls");
    cursor(0);
    PrintSideLine();
    while (1) {
        PlayerMove(&player);
        ComputerMove(&computer);
        Sleep(50); // 딜레이
        player.shootingTime++;
        computer.shootingTime++;
        PlayerShooting(&player, &playerBullet, &playerShootingCheck);
        ComputerShooting(&computer, computerBullet, computerShootingCheck);
        WinnerCheck(&player, &computer, &playerBullet, computerBullet);
    }
}
void PlayerMove(Player* A) {
    if (_kbhit())
    {
        A->direction = _getch();
        switch (A->direction)
        {
        case UP:
            Delete(A->coor);
            A->coor.y--;
            if (A->coor.y < 1) A->coor.y = 1;
            PrintMember(A->coor, A->shape);
            break;
        case DOWN:
            Delete(A->coor);
            A->coor.y++;
            if (A->coor.y > 27) A->coor.y = 27;
            PrintMember(A->coor, A->shape);
            break;
        case LEFT:
            Delete(A->coor);
            A->coor.x -= 2;
            if (A->coor.x < 2) A->coor.x = 2;
            PrintMember(A->coor, A->shape);
            break;
        case RIGHT:
            Delete(A->coor);
            A->coor.x += 2;
            if (A->coor.x > 117) A->coor.x = 117;
            PrintMember(A->coor, A->shape);
            break;
        }
    }
} //플레이어의 움직임 함수
void ComputerMove(Computer* A) {
    srand(time(NULL));
    int RandomMove;
EXIT:
    RandomMove = rand() % 4;

    switch (RandomMove)
    {
    case 0:
        Delete(A->coor);
        A->coor.y--;
        if (A->coor.y < 1) {
            A->coor.y = 1;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        } // 컴퓨터가 벽에 머리박고 멈추는 것을 방지함
        PrintMember(A->coor, A->shape);
        break;
    case 1:
        Delete(A->coor);
        A->coor.y++;
        if (A->coor.y > 27) {
            A->coor.y = 27;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        } // 컴퓨터가 벽에 머리박고 멈추는 것을 방지함
        PrintMember(A->coor, A->shape);
        break;
    case 2:
        Delete(A->coor);
        A->coor.x--;
        if (A->coor.x < 2) {
            A->coor.x = 2;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        }  // 컴퓨터가 벽에 머리박고 멈추는 것을 방지함
        PrintMember(A->coor, A->shape);
        break;
    case 3:
        Delete(A->coor);
        A->coor.x++;
        if (A->coor.x > 117) {
            A->coor.x = 117;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        } // 컴퓨터가 벽에 머리박고 멈추는 것을 방지함
        PrintMember(A->coor, A->shape);
        break;
    }
}//컴퓨터의 (무작위) 움직임 함수
void PrintMember(Coordinate coor, char shape) {
    gotoxy(coor.x, coor.y);
    printf("%c", shape);
} // 어떤 모양을 정해진 좌표에 출력
void Delete(Coordinate coor) {
    gotoxy(coor.x, coor.y);
    printf("  ");
}
void PrintSideLine() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■                                                                                                                    ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
void PlayerShooting(Player* A, Bullet* X, int* playerShootingCheck) {


    if (_kbhit()) {
        if (_getch() == SPACE && A->shootingTime > 20) {
            *playerShootingCheck = 1;
            X->direction = A->direction;
            X->coor = A->coor;
        }
    }

    if (*playerShootingCheck == 1) {


        A->shootingTime = 0;

        if (!(A->coor.x == X->coor.x && A->coor.y == X->coor.y)) Delete(X->coor);
        switch (X->direction) {
        case UP:
            X->coor.y--;
            PrintMember(X->coor, '.');
            break;
        case DOWN:
            X->coor.y++;
            PrintMember(X->coor, '.');
            break;
        case RIGHT:
            X->coor.x++;
            PrintMember(X->coor, '.');
            break;
        case LEFT:
            X->coor.x--;
            PrintMember(X->coor, '.');
            break;
        }

        if (X->coor.x < 3 || X->coor.x>116 || X->coor.y < 2 || X->coor.y>26) {
            *playerShootingCheck = 0;
            Delete(X->coor);
        }

    }

}
void ComputerShooting(Computer* A, Bullet X[4], int computerShootingCheck[5]) {
    if (A->shootingTime > 50) {
        A->shootingTime = 0;
        for (int i = 0; i < 5; i++)
            computerShootingCheck[i] = 1;
        for (int i = 0; i < 4; i++)
            X[i].coor = A->coor;
    }

    if (computerShootingCheck[4] == 1) {
        if (computerShootingCheck[0] == 1) {
            Delete(X[0].coor);
            X[0].coor.y--;
            PrintMember(X[0].coor, '.');
        }
        if (computerShootingCheck[1] == 1) {
            Delete(X[1].coor);
            X[1].coor.y++;
            PrintMember(X[1].coor, '.');
        }
        if (computerShootingCheck[2] == 1) {
            Delete(X[2].coor);
            X[2].coor.x++;
            PrintMember(X[2].coor, '.');
        }
        if (computerShootingCheck[3] == 1) {
            Delete(X[3].coor);
            X[3].coor.x--;
            PrintMember(X[3].coor, '.');
        }
        if (X[0].coor.y < 2) { computerShootingCheck[0] = 0; Delete(X[0].coor); }
        if (X[1].coor.y > 26) { computerShootingCheck[1] = 0; Delete(X[1].coor); }
        if (X[2].coor.x > 116) { computerShootingCheck[2] = 0; Delete(X[2].coor); }
        if (X[3].coor.x < 5) { computerShootingCheck[3] = 0; Delete(X[3].coor);; }

        if (!(computerShootingCheck[0] || computerShootingCheck[1] || computerShootingCheck[2] || computerShootingCheck[3]))
            computerShootingCheck[4] = 0;

    }

}
void WinnerCheck(Player* A, Computer* B, Bullet* X, Bullet Y[4]) {
    if (A->coor.x == B->coor.x && A->coor.y == B->coor.y) ComputerWin();
    for (int i = 0; i < 3; i++)
        if (A->coor.x == Y[i].coor.x && A->coor.y == Y[i].coor.y) ComputerWin();
    if (B->coor.x == X->coor.x && B->coor.y == X->coor.y) PlayerWin();

}
void PlayerWin() {
    system("cls");
    printf("축하합니다. 승리하셨습니다.\n");
    Sleep(20000);
    exit(0);
}
void ComputerWin() {
    system("cls");
    printf("축하드립니다. 패배하셨습니다.\n");
    Sleep(3000);
    exit(0);
}
