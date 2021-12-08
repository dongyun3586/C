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
#define W 119 // ����Ű �� �� Ű������ �ƽ�Ű �ڵ�


typedef struct {
    int x;
    int y;
} Coordinate;//��ǥ ����ü

typedef struct {
    Coordinate coor;
    char shape;
    int shootingTime;
    int direction;
}Player;//�÷��̾� ����ü

typedef struct {
    Coordinate coor;
    char shape;
    int shootingTime;
} Computer;//��ǻ�� ����ü

typedef struct {
    Coordinate coor;
    int direction;
} Bullet;//�Ѿ� ����ü

void StartBoard();
void menu();
void GameRule();
void GameStart();
void PlayerMove(Player* A); // �÷��̾��� ������ �Լ�
void ComputerMove(Computer* A); // ��ǻ���� (������) ������ �Լ�
void PrintMember(Coordinate coor, char shape); // � ����� ������ ��ǥ�� �̵��Ͽ� ���
void Delete(Coordinate coor); // � ��ǥ�� �ִ� ��Ҹ� ����
void PrintSideLine(); // ���� �� ���̵���� ���
void PlayerShooting(Player* A, Bullet* X, int* playerShootingCheck); // �÷��̾��� �߻� �Լ�
void ComputerShooting(Computer* A, Bullet X[4], int computerShootingCheck[5]); // ��ǻ���� (4����) �߻� �Լ�
void WinnerCheck(Player* A, Computer* B, Bullet* X, Bullet Y[4]); // ���� �Ǵ�
void PlayerWin(); // �÷��̾� �¸� ��
void ComputerWin(); // ��ǻ�� �¸� ��
void gotoxy(int x, int y)

{

    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
// ������ ��ǥ�� �̵�
void cursor(int n) // Ŀ�� ���̱� & �����
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//���ͳݿ��� ������ Ŀ�� ������ ���� �ڵ� // ���콺 �����̴� Ŀ�� ���ִ� �Լ� (���ͳݿ��� ������)

int main() {
    StartBoard();
    Sleep(1000);
    system("cls");
    menu();
}

void StartBoard() {
    printf("�������������������������������������������������������������\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                  ��      ��     ��             ��������  �����          �����          ��\n");
    printf("��         ����           ��      ��    ��  ��   ��             ��              ��      ��      ��        ��        ��\n");
    printf("��       ��      ��     ������  ��      ��     ��             ��              ��        ��    ��                  ��\n");
    printf("��             ��         ��  ��    ���           ��             ��              ��        ��    ��                  ��\n");
    printf("��           ��         ��      ��  ��    ����   ��             ��              ��        ��      �����          ��\n");
    printf("��         ��                       ��      ��   ���             �������    ��      ��                ��        ��\n");
    printf("��       ������                 ��             ��             ��              �����                  ��        ��\n");
    printf("��                                          ��     ��             ��              ��                        ��        ��\n");
    printf("��                                          ��                    ��              ��              ��        ��        ��\n");
    printf("��                                          ������            ��              ��                �����          ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                  1615   ������                                                     ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("�������������������������������������������������������������\n");
}
void menu() {
    int n;
    printf("2���� FPS ���ӿ� ���� ���� ȯ���մϴ�!\n");
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
            printf("1,2 �� �ϳ��� ��������.\n");
            break;
        }
    }

}
void GameRule() {
    printf("*************************************************    Game Rule    *************************************************\n");
    printf("1. �÷��̾� ���: o ��ǻ�� ��� : x\n");
    printf("2. �÷��̾�� ����Ű�� ���� 4�������� ������ �� ������, �����̽��ٸ� ������ �����̴� ���� ������ �Ѿ��� ���ư��ϴ�.\n");
    printf("3. ��ǻ�ʹ� �������� �����̸�, �����ð����� 3~4�������� �Ѿ��� �߻��մϴ�.\n");
    printf("4. �÷��̾�� ��ǻ�� ��� �Ѿ��� �� �� ������ ����մϴ�.\n");
    printf("5. �÷��̾�� ��ǻ�Ͱ� �ε�ġ�� �÷��̾ ����մϴ�.\n");
    printf("6. ���� �پ��ִ� ���¿����� �Ѿ��� �߻���� �ʽ��ϴ�. �� ���� �������ֽñ� �ٶ��ϴ�.\n");
    printf("7. ��ǻ�Ͱ� ��� ���� ��Ÿ��� �ֱ� ������ ���� �Ÿ� �̻� ���ư��� �Ѿ��� ����ϴ�.\n");
    printf("8. �׷��� �ٴڿ� ������ �ִ� �Ѿ��� �¾Ƶ� ���� �ʽ��ϴ�.\n");
    printf("9. ����Ÿ �߻� �� ������ ��ǻ���� �¸��� �����˴ϴ�.\n");
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
        Sleep(50); // ������
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
} //�÷��̾��� ������ �Լ�
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
        } // ��ǻ�Ͱ� ���� �Ӹ��ڰ� ���ߴ� ���� ������
        PrintMember(A->coor, A->shape);
        break;
    case 1:
        Delete(A->coor);
        A->coor.y++;
        if (A->coor.y > 27) {
            A->coor.y = 27;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        } // ��ǻ�Ͱ� ���� �Ӹ��ڰ� ���ߴ� ���� ������
        PrintMember(A->coor, A->shape);
        break;
    case 2:
        Delete(A->coor);
        A->coor.x--;
        if (A->coor.x < 2) {
            A->coor.x = 2;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        }  // ��ǻ�Ͱ� ���� �Ӹ��ڰ� ���ߴ� ���� ������
        PrintMember(A->coor, A->shape);
        break;
    case 3:
        Delete(A->coor);
        A->coor.x++;
        if (A->coor.x > 117) {
            A->coor.x = 117;
            PrintMember(A->coor, A->shape);
            goto EXIT;
        } // ��ǻ�Ͱ� ���� �Ӹ��ڰ� ���ߴ� ���� ������
        PrintMember(A->coor, A->shape);
        break;
    }
}//��ǻ���� (������) ������ �Լ�
void PrintMember(Coordinate coor, char shape) {
    gotoxy(coor.x, coor.y);
    printf("%c", shape);
} // � ����� ������ ��ǥ�� ���
void Delete(Coordinate coor) {
    gotoxy(coor.x, coor.y);
    printf("  ");
}
void PrintSideLine() {
    printf("�������������������������������������������������������������\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("��                                                                                                                    ��\n");
    printf("�������������������������������������������������������������\n");
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
    printf("�����մϴ�. �¸��ϼ̽��ϴ�.\n");
    Sleep(20000);
    exit(0);
}
void ComputerWin() {
    system("cls");
    printf("���ϵ帳�ϴ�. �й��ϼ̽��ϴ�.\n");
    Sleep(3000);
    exit(0);
}
