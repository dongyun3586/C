#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char* cardname[11] = { "","♠","■","♥","▲","●","♤","□","♡","△","○" };//카드 이름
int card[4][5];//카드 배열
int checkcard[4][5];//뒤집혔는지 확인

void shuffle();//카드 섞기
void information();//게임 정보
void game();
void print();//카드 출력
int check();//게임 종료 여부 체크

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
            {//이미 카드가 채워져 있으면 다른 곳으로
                x = rand() % 4;
                y = rand() % 5;
            }
            card[x][y] = i;
        }
    }
}

void information()
{
    printf("짝맞추기 게임");
    Sleep(2000);
    system("cls");
    printf("카드를 5초간 보여드리겠습니다.\n\n"); //카드 5초간 보여준 후 
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
        printf("뒤집을 두 카드를 고르세요\n"); //뒤집을 두 카드 선정
        scanf("%d %d", &s1, &s2);
        while ((s1 == s2) || (checkcard[s1 / 5][s1 % 5]) || (checkcard[s2 / 5][s2 % 5]) || (s1 >= 20) || (s2 >= 20))
        {//잘못 입력한 경우 s1,s2가 같거나, 이미 선택된 카드거나, 20이상일때
            printf("다시 입력하세요\n");
            scanf("%d %d", &s1, &s2);
        }
        if (card[s1 / 5][s1 % 5] == card[s2 / 5][s2 % 5])//두 카드가 같을 때
        {
            printf("\n%s! 맞췄습니다!\n", cardname[card[s1 / 5][s1 % 5]]);
            checkcard[s1 / 5][s1 % 5] = 1;
            checkcard[s2 / 5][s2 % 5] = 1;
            Sleep(1000);
        }
        else//두 카드가 다를 때
        {
            system("cls");
            checkcard[s1 / 5][s1 % 5] = 1;
            checkcard[s2 / 5][s2 % 5] = 1;
            print();
            printf("땡! 틀렸습니다!\n");
            checkcard[s1 / 5][s1 % 5] = 0;
            checkcard[s2 / 5][s2 % 5] = 0;
            Sleep(1000);
            mistake++;
        }
    }
    printf("모두 다 찾으셨습니다.\n");
    printf("%d번 틀리셨습니다.\n", mistake);
}

void print()
{
    printf("<짝맞추기 게임>\n\n");
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

int check()//모두 뒤집혔는지 체크
{
    int c = 0;
    for (int i = 0; i < 20; i++)
        if (checkcard[i / 5][i % 5] == 1)
            c++;
    if (c == 20)
        return 1;
    return 0;
}