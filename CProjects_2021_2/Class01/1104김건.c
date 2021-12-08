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
    printf("베팅할 말을 골라주세요\n\n");
    name();
    printf("1~%d번 말\n", HORSE);
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
        system("cls");         //한 프레임씩 나오도록 출력된 것을 지운다. 
        ranking(horse, rank, &r);
        print(horse, rank);
        if (horse[min] > MAX)  // 최솟값과 결승점 최종값을 비교하여 게임을 종료한다.
            break;
        random(horse);
        Sleep(70);             //0.07초 멈춘 후 출력
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
    printf("당신이 선택한 말 : %d번\n\n", myhorse);
    printf("     start");
    for (int i = 1; i < MAX; i++)
        printf(" ");
    printf("end\n");
    printf("       ↓");
    for (int i = 1; i <= MAX; i++)
        printf(" ");
    printf("↓\n");
    for (int i = 0; i < HORSE; i++)
    {
        if (rank[i] != 0)
            printf("%d등 ", rank[i]);
        else
            printf("    ");
        printf("%d번|", i + 1);
        for (int j = 1; j <= horse[i]; j++)  // horse[i] 만큼 
            printf(" ");                     // " "를 출력한다.  
        printf("馬\n");
    }
    printf("       ↑");
    for (int i = 1; i <= MAX; i++)
        printf(" ");
    printf("↓\n");
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
        if (horse[i] <= MAX)              //말의 칸 수를 horse[i]에 저장한다.
            horse[i] += rand() % 3 + 1;   // 1~3까지 임의의 칸 수만큼 이동
    }
}

int minimum(int horse[HORSE])    // 말의 칸 수 중에 가장 최소인 값을 반환해 주는 함수
{
    int min = 0;
    for (int i = 0; i < HORSE; i++)
        if (horse[min] > horse[i])
            min = i;
    return min;
}

void end(int rank[HORSE])
{
    printf("\n당신이 선택한 %d번 말은 %d등 입니다.\n", myhorse, rank[myhorse - 1]);
}

void name()
{
    char* names[] = { "James", "Lucas", "Henry", "Jacob", "Alexander" };

    for (int i = 0; i < 5; i++)
        printf(" %d 번째 말의 이름 = %s\n", i + 1, *(names + i));
    printf("\n");
}