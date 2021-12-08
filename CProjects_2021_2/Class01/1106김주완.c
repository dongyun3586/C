#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define MAXSIZE 10

int size = 1;
int combingo[MAXSIZE][MAXSIZE];//��ǻ�� ������
int mybingo[MAXSIZE][MAXSIZE];//�� ������

void input();//�� ������ �Է�
void set(int bingo[MAXSIZE][MAXSIZE]);//��ǻ�� ������ ����
void explain();//���� ���� �� ����
void mixbingo(int bingo[MAXSIZE][MAXSIZE]);//������ ����
void print(char* owner, int bingo[MAXSIZE][MAXSIZE]);//������ ���
int game();//���� ����
void change(int c);//�ҷ��� ���ڸ� �ٲ�
int check(int bingo[MAXSIZE][MAXSIZE]);//���� ���� �밢�� �� Ȯ��
int random();//��ǻ���� ���� ����
void result(int x);//��� ���

int main()
{
    explain();
    int winner = game();
    result(winner);
    return 0;
}

void result(int x)
{
    Sleep(3000);
    system("cls");
    if (x == 1)
        printf("�¸��ϼ̽��ϴ�!!!\n");
    else if (x == -1)
        printf("�й�\n");
    else
        printf("���º� �Դϴ�.\n");
}

void print(char* owner, int bingo[MAXSIZE][MAXSIZE])
{
    printf("\n%s�� ������\n", owner);
    printf("%d����\n", check(bingo));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bingo[i][j] == 0)
                printf("�� ");
            else if ((strcmp(owner, "��ǻ��") != 0) && (bingo[i][j] != 0))
                printf("%2d ", bingo[i][j]);
            else
                printf("�� ");
        }
        printf("\n");
    }
    printf("\n");
}

void explain()
{
    printf("�������\n");
    Sleep(2000);
    system("cls");
    printf("�������� ũ�⸦ �Է��ϼ���\n");
    Sleep(1000);
    printf("�������� ũ��� 2*2~10*10�Դϴ�.\n");
    scanf("%d", &size);
    Sleep(1000);
    system("cls");
    printf("%d ���� ���� �޼��ϸ� �¸��մϴ�.\n", size - 1);
    Sleep(1000);
    printf("�������� �������� �ұ��?\n��  0 , �ƴϿ� 1\n");
    int ranset;
    scanf("%d", &ranset);
    if (ranset == 1)
    {
        printf("%d*%d ũ���� �������� �Է��ϼ���\n", size, size);
        input();
    }
    else
        set(mybingo);
    Sleep(1000);
    set(combingo);
}

void input()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &mybingo[i][j]);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = i; k < size; k++)
                for (int l = j + 1; l < size; l++)
                    while (mybingo[i][j] == mybingo[k][l])
                    {
                        printf("1~%d�� ���� �ٸ� ���ڷ� �ٽ� �Է��ϼ���\n", size * size);
                        for (int i = 0; i < size; i++)
                            for (int j = 0; j < size; j++)
                                scanf("%d", &mybingo[i][j]);
                    }
}

void set(int bingo[MAXSIZE][MAXSIZE])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            bingo[i][j] = i * size + j + 1;
    mixbingo(bingo);
}

void mixbingo(int bingo[MAXSIZE][MAXSIZE])
{
    int temp;
    srand(time(NULL));
    for (int i = 1; i <= (size * size); i++)
    {
        int x1 = rand() % size, y1 = rand() % size;
        int x2 = rand() % size, y2 = rand() % size;
        temp = bingo[x1][y1];
        bingo[x1][y1] = bingo[x2][y2];
        bingo[x2][y2] = temp;
    }
}

int game()
{
    int choose;
    while (1)
    {
        system("cls");
        print("��", mybingo);
        print("��ǻ��", combingo);
        printf("���ڸ� �Է��ϼ���\n");
        scanf("%d", &choose);
        while (1)
        {
            int flag = 0;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (choose == combingo[i][j])
                        flag = 1;
            if (flag == 1)
                break;
            else if (flag == 0)
            {
                printf("�̹� ���� �� �Դϴ�. �ٽ� �Է��� �ּ���.\n");
                scanf("%d", &choose);
            }
        }
        Sleep(1000);
        system("cls");
        change(choose);
        print("��", mybingo);
        print("��ǻ��", combingo);
        if ((check(mybingo) >= size - 1) && (check(combingo) >= size - 1))
        {
            if (check(mybingo) > check(combingo))
                return 1;
            else if (check(mybingo) < check(combingo))
                return -1;
            else
                return 0;
        }
        else if ((check(mybingo) == size - 1))
            return 1;
        else if ((check(combingo) == size - 1))
            return -1;
        choose = random();
        Sleep(1000);
        printf("��ǻ�Ͱ� �� �� : %d\n", choose);
        change(choose);
        Sleep(1500);
        if ((check(mybingo) >= size - 1) && (check(combingo) >= size - 1))
        {
            if (check(mybingo) > check(combingo))
                return 1;
            else if (check(mybingo) < check(combingo))
                return -1;
            else
                return 0;
        }
        else if ((check(mybingo) == size - 1))
            return 1;
        else if ((check(combingo) == size - 1))
            return -1;
    }
}

int random()
{
    srand(time(NULL));
    int num = rand() % (size * size) + 1;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (num == combingo[i][j])
                    flag = 1;
        if (flag == 1)
            break;
        else if (flag == 0)
            num = rand() % (size * size) + 1;
    }
    return num;
}

void change(int c)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mybingo[i][j] == c)
                mybingo[i][j] = 0;
            if (combingo[i][j] == c)
                combingo[i][j] = 0;
        }
    }
}

int check(int bingo[MAXSIZE][MAXSIZE])
{
    int count = 0;
    int g = 0, s = 0, uc = 0, dc = 0;//����, ����, ���� �ö󰡴� �밢��, �������� �밢��
    for (int i = 0; i < size; i++)
    {
        g = 0, s = 0;
        for (int j = 0; j < size; j++)
        {
            if (bingo[i][j] == 0)
                g++;
            if (bingo[j][i] == 0)
                s++;
        }
        if (bingo[i][i] == 0)
            dc++;
        if (bingo[size - i - 1][i] == 0)
            uc++;
        if (g == size)
            count++;
        if (s == size)
            count++;
    }
    if (dc == size)
        count++;
    if (uc == size)
        count++;
    return count;
}