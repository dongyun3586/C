#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 20        //����
#define HEIGHT 10        //����
#define TRUE 1
#define FALSE 0

//��(���� ��)
typedef struct
{
    int x;
    int y;
    //���� ���� (TRUE, FALSE)�� ��Ʈ���� ��
    int con;
}Enemy;
//�÷��̾�
typedef struct
{
    int x;
}Player;

////������ ��ġ�� Ŀ���� �̵���Ű�� �Լ�////
void gotoxy(int x, int y)
{
    //COORD : window.h�� �ִ� ����ü, {SHORT x, SHORT y} �� �����Ǿ� �ִ�.
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Enemy enemy[WIDTH];
Player player;

//// �ʱⰪ ////
void fvalue()
{
    int i;
    for (i = 0; i < WIDTH; i++)
        (*(enemy + i)).con = FALSE;//enemy[i].con
    //�÷��̾� ó�� ��ġ�� �߾�����
    player.x = WIDTH / 2;
}

//// ���� ���� ó�� ////
/* �� ���� */
void CreateEnemy()
{
    int i;

    for (i = 0; i < WIDTH; i++)
    {
        //�ش� �ε���[i]�� ���� ������ (FALSE �̸� ����)
        if (!enemy[i].con)
        {
            //���� (x��) �������� �� ����, ����(y��)�� ���� ��ġ �׻� ��ġ
            enemy[i].x = rand() % WIDTH;
            enemy[i].y = HEIGHT - 1;
            //���� ������ �ε��� [i]�� ���� = TRUE�� ����
            enemy[i].con = TRUE;
            return;
        }
    }
}
/* ���� ������ */
void FallEnemy()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //�ش� �ε��� [i]�� ���� ������ (TRUE���) ������ ����
        if (enemy[i].con)
        {
            enemy[i].y--;
        }
    }
}
/* ���ϱ� ������ ��(�ٴڿ� ������ ��) ���� */
void DelEnemy()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con && enemy[i].y < 0)
            enemy[i].con = FALSE;
    }
}
/* �÷��̾ ������ ���� ��� (�й�) */
int DamagedPlayer()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //���� ���°� TRUE && ���� ��ġ�� y=0 �� �ٴ� && ���� x�� ��ġ = �÷��̾��� x�� ��ġ
        if ((enemy[i].con && enemy[i].y == 0) && (enemy[i].x == player.x))
            return TRUE;
    }
    //���� �ʾ����� FALSE ��ȯ
    return FALSE;
}

//// �÷��̾� ó�� ////
/* Ű �ٿ� ó�� */
int isKeyDown(int key)
{
    //***GetAsyncKey�� Ű�� ���ȴٸ� �ֻ��� ��Ʈ�� 1�� ����, ������ Ű�� ���ȴٸ� ������ ��Ʈ�� 1�� ����
    //0x8000�� �ֻ��� ��Ʈ -> 16������ 2��Ʈ�� 4�� ���� ��Ʈ -> 0x8000 = 1000 0000 0000 0000�� �ǹ�
    // �� ������ ��Ʈ�� 0x0001 -> 0000 0000 0000 0001
    // ���� (GetAsyncKeyState(key) & 0x8000) != 0 �� ���� Ű�� �����ִٸ� ��(TRUE)--���ͳ��� ������
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

/* �÷��̾� �̵� (��/��) */
void MovePlayer()
{
    //���� ����Ű �Է� ��
    if (isKeyDown(VK_LEFT))
        player.x--;
    if (isKeyDown(VK_RIGHT))
        player.x++;
    //��ġ ���� ����
    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
}

//// ���� ȭ�� ��� ////
void PrintGame()
{
    //��� ȭ�� clear
    system("cls");

    gotoxy((WIDTH / 2) - 7, HEIGHT + 2);
    printf("                      Made by JYLEE");

    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con)
        {
            //�� ��ġ�� ���� ���
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
            printf("��");
        }
    }
    //�÷��̾� ���
    gotoxy(player.x, HEIGHT);
    printf("��");

    //�ٴ� ���
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("��");
}

//// main �Լ� ////
int main(void) {
    fvalue();
    int speed = 50;
    int score = 0;


    do {
        //�Ź� ������ ������ �ٸ� ���� �ֱ� ���� �õ尪 ����
        srand((int)malloc(NULL));

        CreateEnemy();
        FallEnemy();
        DelEnemy();

        MovePlayer();

        PrintGame();
        //������ �ӵ� ������ ���� Sleep ����

        Sleep(250 - speed);
        if (speed <= 200) {
            speed += 5;
        }

        score++;
        gotoxy(WIDTH + 5, HEIGHT / 2);
        printf("SCORE:%d", score);
    } while (!(DamagedPlayer()));    //���� ������ �ݺ�
}