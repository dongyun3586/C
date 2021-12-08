#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define MAXSIZE 10

int size = 1;
int combingo[MAXSIZE][MAXSIZE];//컴퓨터 빙고판
int mybingo[MAXSIZE][MAXSIZE];//내 빙고판

void input();//내 빙고판 입력
void set(int bingo[MAXSIZE][MAXSIZE]);//컴퓨터 빙고판 설정
void explain();//대충 시작 전 설명
void mixbingo(int bingo[MAXSIZE][MAXSIZE]);//빙고판 섞기
void print(char* owner, int bingo[MAXSIZE][MAXSIZE]);//빙고판 출력
int game();//게임 시작
void change(int c);//불러진 숫자를 바꿈
int check(int bingo[MAXSIZE][MAXSIZE]);//가로 세로 대각선 줄 확인
int random();//컴퓨터의 랜덤 숫자
void result(int x);//결과 출력

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
        printf("승리하셨습니다!!!\n");
    else if (x == -1)
        printf("패배\n");
    else
        printf("무승부 입니다.\n");
}

void print(char* owner, int bingo[MAXSIZE][MAXSIZE])
{
    printf("\n%s의 빙고판\n", owner);
    printf("%d빙고\n", check(bingo));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bingo[i][j] == 0)
                printf("● ");
            else if ((strcmp(owner, "컴퓨터") != 0) && (bingo[i][j] != 0))
                printf("%2d ", bingo[i][j]);
            else
                printf("○ ");
        }
        printf("\n");
    }
    printf("\n");
}

void explain()
{
    printf("빙고게임\n");
    Sleep(2000);
    system("cls");
    printf("빙고판의 크기를 입력하세요\n");
    Sleep(1000);
    printf("빙고판의 크기는 2*2~10*10입니다.\n");
    scanf("%d", &size);
    Sleep(1000);
    system("cls");
    printf("%d 빙고를 먼저 달성하면 승리합니다.\n", size - 1);
    Sleep(1000);
    printf("빙고판을 랜덤으로 할까요?\n예  0 , 아니오 1\n");
    int ranset;
    scanf("%d", &ranset);
    if (ranset == 1)
    {
        printf("%d*%d 크기의 빙고판을 입력하세요\n", size, size);
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
                        printf("1~%d의 서로 다른 숫자로 다시 입력하세요\n", size * size);
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
        print("나", mybingo);
        print("컴퓨터", combingo);
        printf("숫자를 입력하세요\n");
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
                printf("이미 나온 수 입니다. 다시 입력해 주세요.\n");
                scanf("%d", &choose);
            }
        }
        Sleep(1000);
        system("cls");
        change(choose);
        print("나", mybingo);
        print("컴퓨터", combingo);
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
        printf("컴퓨터가 고른 수 : %d\n", choose);
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
    int g = 0, s = 0, uc = 0, dc = 0;//가로, 세로, 위로 올라가는 대각선, 내려가는 대각선
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