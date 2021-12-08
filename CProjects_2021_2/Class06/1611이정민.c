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
int gun[2] = { 30, 70 }; //������ ��ǥ: gun[0]: x��ǥ, gun[1]: y��ǥ
int enemynum = 1;// ������� �� ��
int score = 0; // ���� ������ �����ϴ� ����
void printMap(int(*arr)[width], enemy* enemyinfo); // Map ����ϴ� �Լ�
void MapInfo(int(*arr)[width], enemy* enemyinfo);//�� ������ �ٲٴ� �Լ�: �� �Լ��� arr �迭�� ���� �ٲ����μ�
void respondEnemy(int(*arr)[width], enemy* enemyinfo);// ���� ����� ���� �Լ�
void enemymove(enemy* enemyinfo);//���� �����̰� �ϴ�  �Լ�: ���� ��ġ������ ��                    ���ִ� enemyinfo ����ü �迭�� ���� �ٲ����μ� ���� ��ġ�� �ٲ۴�.
void gotoxy(int x, int y) //�� �Լ��� ���̹� ��α׸� �����ؼ� ��������ϴ�.
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void GunInfo(int(*arr)[width], enemy* enemyinfo);
int main()
{
    enemy enemyinfo[TOTALENEMYNUMBER]; // ���� ��ġ ������ ���� �迭�� ũ��
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
        printf("����: %d\n", score);//���� ������ ������ ���� �ð� ���ȸ� ���̸� while(1)�� ������ Ȯ���ϼ���.
    }    Sleep(1);
    return 0;
}
void printMap(int(*arr)[width], enemy* enemyinfo)   // MAP�� ����ϴ� �Լ�
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arr[i][j] == 1)
            {
                printf("*"); // ���� �׸��� *�� �ߴ�.
            }
            else if (arr[i][j] == 4)
            {
                printf("@");// �������� �׸��� @�� �ߴ�.
            }
            else
            {
                printf(" ");// �ƹ��͵� ���� ������ ����ϴ� ����
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
            arr[i][j] = 0;// arr �迭�� ���� 0���� �ʱ�ȭ
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
                    arr[j][p] = 1;// ���� �߽����κ��� �� 4, �Ʒ� 3, ���� 4, ������ 3��ŭ�� ���� ũ��� �ߴ�.
                }
            }
        }
    }
    GunInfo(arr, enemyinfo);// �� �������� ����ϴ� �Լ�.
    arr[gun[0]][gun[1]] = 4;// �������� ��ǥ�� arr �迭���� 4�� ó���Ѵ�.

}

void respondEnemy(int(*arr)[width], enemy* enemyinfo) // �� �����ϴ� �Լ�
{
    srand(time(NULL));
    if (rand() % 2 == 1 && enemyinfo[enemynum - 1].x > 10 && enemynum < TOTALENEMYNUMBER)// rand �Լ��� ����
    {
        enemyinfo[enemynum].x = 5;
        enemyinfo[enemynum].y = rand() % 50 + 5;
        enemynum++;
    }
}
void enemymove(enemy* enemyinfo)// �� �̵��ϴ� �Լ�
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

    int n;//_getch�� ���� ����4
    n = _getch();
    if (n == 'A' || n == 'a') // ��������  �̵��ϴ� ����Ű;
    {
        gun[1]--;

        if (gun[1] <= 0)
            gun[1] = 0;
    }
    if (n == 'W' || n == 'w') // ���� �̵��ϴ� ����Ű;
    {
        gun[0]--;
        if (gun[0] <= 0)
            gun[0] = 0;
    }
    if (n == 'D' || n == 'd') //D(d): ���������� �̵��ϴ� ����Ű
    {
        gun[1]++;
        if (gun[1] >= 139)
        {
            gun[1] = 139;
        }
    }
    if (n == 'S' || n == 's')//S(s): �Ʒ��� �̵��ϴ�  ����Ű
    {
        gun[0]++;
        if (gun[0] >= 59)
        {
            gun[0] = 59;
        }
    }
    if (n == 'F' || n == 'f') //F: ���Ű(
    {
        if (arr[gun[0]][gun[1]] == 1)
            score++;
    }

}
