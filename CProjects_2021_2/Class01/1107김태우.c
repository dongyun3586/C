#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDE 2  // �ٸ� �� ����
#define LENGTH 18  // �ٸ� ���� ����
#define LIFE 16    // ��� ����

int bri[WIDE][LENGTH + 1];      // �ٸ��� ���� �迭
int dieposition[LENGTH + 1];        //�״� ��ġ ���� �迭
int life = LIFE;               // ��� ����
int a = 0, b = 96, c = 308, d = 62, e = 21, f = 453, g = 244, h = 151, i = 407, j = 101, k = 322, l = 212, m = 360, n = 17, o = 218, p = 67, q = 456;
int* person[LIFE + 1] = { &a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q };    // ���� ��¡�� ���� ������ ��ȣ ����(������ �迭 Ȱ��)


void SetBridge();                 // �ٸ� ����
void reset();                     // �ٸ� �ʱ�ȭ
void PrintBridge(int s, int p);                  // �ٸ��� ���� ��ġ ���
void end(int l, int p);                          // ���� ���� �Լ�
void game();                                     // ���� ���� �Լ�
void printlife();                                // ��� ��� �Լ�
void explain();                                  // ���� ���� �Լ�

int main()
{
    explain();    // ���� ����
    SetBridge();    // �ٸ� ����
    game();     // ���� ����
    return 0;
}

void explain()          // ���� ���� �Լ�
{
    // ��¡�� ���� ���� ��� �Է�
    printf("�ۡ��\n");
    Sleep(500);
    printf("��¡�� ����\n");
    Sleep(1100);
    system("cls");
    printf("�ټ� ��° ���ӿ� ���� ������ �������� ȯ���մϴ�.\n");
    Sleep(500);
    printf("�ټ� ��° ������ ¡�˴ٸ� �ǳʱ� �Դϴ�.\n");
    Sleep(1100);
    system("cls");
    printf("�տ� ���̴� �� ���� ������ �� ���� ����\n");
    Sleep(500);
    printf("��ȭ ������ �Ϲ� ������ �Ǿ� �ֽ��ϴ�.\n");
    Sleep(1100);
    system("cls");
    printf("��ȭ ������ �� ����� ���Ե� ��ƿ �� ���� ��ŭ ưư������\n");
    Sleep(500);
    printf("�Ϲ� ������ �� ����� �ö󰡵� ���� �����ϴ�.\n");
    Sleep(1100);
    system("cls");
    printf("�����ڵ��� �տ� ���� �� ���� ���� �߿�\n");
    Sleep(500);
    printf("��� ���� ��ȭ ���������� �Ǵ��ؼ�\n");
    Sleep(500);
    printf("�װ͵��� ��� ������ ���� �ٸ��� ����\n");
    Sleep(500);
    printf("�ݴ������ ������ �ǳʰ��� ����Դϴ�.\n");
    Sleep(1100);
    system("cls");
}

void SetBridge()            // �ٸ� ���� �Լ�
{
    srand(time(NULL));          // ���� �Լ� �̿�
    for (int i = 1; i <= LENGTH; i++)
        bri[rand() % WIDE][i] = 1;           // 0�̸� ��ȭ ����, 1�̸� �Ϲ� ����
}

void reset()            // �ٸ� �ʱ�ȭ �Լ�
{
    printlife();            // ��� ��� �Լ�
    for (int i = 0; i < WIDE; i++)
    {
        if (i == 1)
            printf("��");
        printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if ((dieposition[j] == 1) && (bri[i][j] == 1))
            {
                printf("�� ");
            }
            else
                printf("�� ");
        }
        printf("\n");
    }
}

void PrintBridge(int s, int p)          // �ٸ� ��� �Լ�
{
    printlife();            // ��� ��� �Լ�
    for (int i = 0; i < WIDE; i++)
    {
        if (s == i)
        {
            for (int i = 0; i < 2 * p - 2; i++)
                printf("  ");
            printf("  ��\n%d", i + 1);
        }
        else
            printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if ((dieposition[j] == 1) && (bri[i][j] == 1))
            {
                printf("�� ");
            }
            else
                printf("�� ");
        }
        printf("\n");
    }
}

void printlife()            // ��� ��� �Լ�
{
    for (int i = 1; i <= LIFE - life; i++)
        printf("��");            // ������ ��� ���
    for (int i = 1; i <= life; i++)
        printf("��");            // ���� ��� ���
    printf("\n\n");
    for (int i = 1; i <= LENGTH; i++)
        printf("  %2d", i);
    printf("\n");
}

void end(int l, int p)          // ���� ���� �Լ�
{
    system("cls");
    printlife();            // ��� ��� �Լ�
    for (int i = 0; i < WIDE; i++)
    {
        printf("\n%d", i + 1);
        for (int j = 1; j <= LENGTH; j++)
        {
            printf(" ");
            if (bri[i][j] == 0)
                printf("�� ");           // ��ȭ������ ��� ��ĥ�� �簢�� ���
            else
                printf("�� ");           // �Ϲ������� ��� ����ִ� �簢�� ���
        }
        printf("\n");
    }
    if (l == 0)
        printf("\n���� Ż��\n");            // ���� ������ ��� ���� Ż�� ���
    else if (p == LENGTH)
    {
        printf("\n");
        for (int i = LIFE - life + 1; i <= LIFE; i++)
        {
            if (i != LIFE)
                printf("%d��, ", *person[i]);
            if (i == LIFE)
                printf("%d�� ", *person[i]);
        }
        printf("������ ����\n\n");           // ������ ��� ������ ������ ��ȣ ���
    }
}

void game()         // ���� ���� �Լ�
{

    int position = 0;
    int select = 0;
    reset();
    while (1)
    {
        printf("\n\n��� ��� ���ðڽ��ϱ�? : 1, 2\n");
        scanf("%d", &select);           // ����� �Է� �ޱ�
        select--;
        while (select != 0 && select != 1)
        {
            printf("�ٽ� �Է��ϼ���\n");           // 0,1�� �ƴ� ���ڸ� �Է��� ��� �ٽ� �Է� �ޱ�
            scanf("%d", &select);
            select--;
        }
        if (bri[select][position + 1] == 1)             // �Ϲ� ������ ������ ���
        {
            life--;
            dieposition[position + 1] = 1;
            position = 0;
            system("cls");
            reset();            // ��� 1�� ����, ó�� ��ġ�� �̵�, �ʱ�ȭ
        }
        else                                           // ��ȭ ������ ������ ���
        {
            position++;
            system("cls");
            PrintBridge(select, position);          // �� ĭ ������ �̵�
        }
        if ((life == 0) || (position == LENGTH))            // ���� ����� ���ų� �ٸ� ������ ������ ���
            break;              // ���� ����
    }
    end(life, position);            // ���� ���� �Լ�
    Sleep(2000);
    system("cls");
    printf("��ŵ� ���ӿ� �����Ͻðڽ��ϱ�?\n");
    Sleep(3000);
    system("cls");
    printf("�ۡ��\n010-4092-6813\n");
}