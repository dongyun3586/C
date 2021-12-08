#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char* cardname[11] = { "","��","��","��","��","��","��","��","��","��","��" };//ī�� �̸�
int card[4][5];//ī�� �迭
int checkcard[4][5];//���������� Ȯ��

void shuffle();//ī�� ����
void information();//���� ����
void game();
void print();//ī�� ���
int check();//���� ���� ���� üũ

int main()
{
    shuffle();
    information();
    game();
    return 0;
}

void shuffle()
{
    srand(time(NULL));
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            int x = rand() % 4;
            int y = rand() % 5;
            while (card[x][y] != 0)
            {//�̹� ī�尡 ä���� ������ �ٸ� ������
                x = rand() % 4;
                y = rand() % 5;
            }
            card[x][y] = i;
        }
    }
}

void information()
{
    printf("¦���߱� ����");
    Sleep(2000);
    system("cls");
    printf("ī�带 5�ʰ� �����帮�ڽ��ϴ�.\n\n"); //ī�� 5�ʰ� ������ �� 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%4s ", cardname[card[i][j]]);
        printf("\n\n");
    }
    for (int i = 5; i >= 1; i--)
    {
        printf("%d ", i);
        Sleep(1000);
    }
    system("cls");
}

void game()
{
    int mistake = 0;
    while (1)
    {
        system("cls");
        print();
        if (check() == 1)
            break;
        int s1, s2;
        printf("������ �� ī�带 ������\n"); //������ �� ī�� ����
        scanf("%d %d", &s1, &s2);
        while ((s1 == s2) || (checkcard[s1 / 5][s1 % 5]) || (checkcard[s2 / 5][s2 % 5]) || (s1 >= 20) || (s2 >= 20))
        {//�߸� �Է��� ��� s1,s2�� ���ų�, �̹� ���õ� ī��ų�, 20�̻��϶�
            printf("�ٽ� �Է��ϼ���\n");
            scanf("%d %d", &s1, &s2);
        }
        if (card[s1 / 5][s1 % 5] == card[s2 / 5][s2 % 5])//�� ī�尡 ���� ��
        {
            printf("\n%s! ������ϴ�!\n", cardname[card[s1 / 5][s1 % 5]]);
            checkcard[s1 / 5][s1 % 5] = 1;
            checkcard[s2 / 5][s2 % 5] = 1;
            Sleep(1000);
        }
        else//�� ī�尡 �ٸ� ��
        {
            system("cls");
            checkcard[s1 / 5][s1 % 5] = 1;
            checkcard[s2 / 5][s2 % 5] = 1;
            print();
            printf("��! Ʋ�Ƚ��ϴ�!\n");
            checkcard[s1 / 5][s1 % 5] = 0;
            checkcard[s2 / 5][s2 % 5] = 0;
            Sleep(1000);
            mistake++;
        }
    }
    printf("��� �� ã���̽��ϴ�.\n");
    printf("%d�� Ʋ���̽��ϴ�.\n", mistake);
}

void print()
{
    printf("<¦���߱� ����>\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkcard[i][j] == 1)
                printf("%4s ", cardname[card[i][j]]);
            else
                printf("  %2d ", i * 5 + j);
        }
        printf("\n\n");
    }
}

int check()//��� ���������� üũ
{
    int c = 0;
    for (int i = 0; i < 20; i++)
        if (checkcard[i / 5][i % 5] == 1)
            c++;
    if (c == 20)
        return 1;
    return 0;
}