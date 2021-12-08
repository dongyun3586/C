#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define HORSE 5
#define MAX 100

int myhorse;

void explain();
void game();
void print(int horse[HORSE], int rank[HORSE]);
void random(int horse[HORSE]);
void ranking(int horse[HORSE], int rank[HORSE], int* r);
int minimum(int horse[HORSE]);
void end(int rank[HORSE]);
void name();

int main()
{
    explain();
    game();
    return 0;
}

void explain()
{
    printf("������ ���� ����ּ���\n\n");
    name();
    printf("1~%d�� ��\n", HORSE);
    scanf("%d", &myhorse);
}

void game()
{
    int horse[HORSE] = { 0 };
    int rank[HORSE] = { 0 };
    int r = 1;
    while (1)
    {
        int min = minimum(horse);
        system("cls");         //�� �����Ӿ� �������� ��µ� ���� �����. 
        ranking(horse, rank, &r);
        print(horse, rank);
        if (horse[min] > MAX)  // �ּڰ��� ����� �������� ���Ͽ� ������ �����Ѵ�.
            break;
        random(horse);
        Sleep(70);             //0.07�� ���� �� ���
    }
    end(rank);
}

void ranking(int horse[HORSE], int rank[HORSE], int* r)
{
    for (int i = 0; i < HORSE; i++)
        if (horse[i] > MAX && rank[i] == 0)
        {
            rank[i] = *r;
            (*r)++;
        }
}

void print(int horse[HORSE], int rank[HORSE])
{
    printf("����� ������ �� : %d��\n\n", myhorse);
    printf("     start");
    for (int i = 1; i < MAX; i++)
        printf(" ");
    printf("end\n");
    printf("       ��");
    for (int i = 1; i <= MAX; i++)
        printf(" ");
    printf("��\n");
    for (int i = 0; i < HORSE; i++)
    {
        if (rank[i] != 0)
            printf("%d�� ", rank[i]);
        else
            printf("    ");
        printf("%d��|", i + 1);
        for (int j = 1; j <= horse[i]; j++)  // horse[i] ��ŭ 
            printf(" ");                     // " "�� ����Ѵ�.  
        printf("ة\n");
    }
    printf("       ��");
    for (int i = 1; i <= MAX; i++)
        printf(" ");
    printf("��\n");
    printf("     start");
    for (int i = 1; i < MAX; i++)
        printf(" ");
    printf("end\n");
}

void random(int horse[HORSE])
{
    srand(time(NULL));
    for (int i = 0; i < HORSE; i++)
    {
        if (horse[i] <= MAX)              //���� ĭ ���� horse[i]�� �����Ѵ�.
            horse[i] += rand() % 3 + 1;   // 1~3���� ������ ĭ ����ŭ �̵�
    }
}

int minimum(int horse[HORSE])    // ���� ĭ �� �߿� ���� �ּ��� ���� ��ȯ�� �ִ� �Լ�
{
    int min = 0;
    for (int i = 0; i < HORSE; i++)
        if (horse[min] > horse[i])
            min = i;
    return min;
}

void end(int rank[HORSE])
{
    printf("\n����� ������ %d�� ���� %d�� �Դϴ�.\n", myhorse, rank[myhorse - 1]);
}

void name()
{
    char* names[] = { "James", "Lucas", "Henry", "Jacob", "Alexander" };

    for (int i = 0; i < 5; i++)
        printf(" %d ��° ���� �̸� = %s\n", i + 1, *(names + i));
    printf("\n");
}