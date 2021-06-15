#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Manual(int num);
int Auto(int num);
int Information(char mode1);

int main()
{
    char mode1, mode2, mode3;
    int num, turn;
    printf("WHAT KIND OF MODE WOULD YOU CHOOSE?\n\n");
    printf("INFOR | 'w'atch  or 's'kip\n");
    printf("PLAY  | 'm'anual or 'a'uto\n");
    printf("TURN  | 'm'anual or 'r'andom\n");
    scanf("%c%c%c", &mode1, &mode2, &mode3);
    if (mode1 == 'w')
        Information(mode1);
    if (mode3 == 'm')
    {
        printf("\nTURN  | '1'st or '2'nd\n");
        scanf("%d", &turn);
        if (turn == 1)
            num = 0;
        else if (turn == 2)
            num = 1;
    }
    else if (mode3 == 'r')
        num = rand() % 2;
    if (mode2 == 'm')
        Manual(num);
    else if (mode2 == 'a')
        Auto(num);
    return 0;
}

int Information(char mode1)
{
    mode1 -= 32;
    printf("\n%chat is 흑과백?\n", mode1);
    printf("0 ~ 8 까지의 홀은 백, 짝은 흑인 타일들을\n");
    printf("서로가 서로의 숫자를 모른체 타일을 내어\n");
    printf("더 큰 숫자가 승리, 다음 판에서 선공이 되며\n");
    printf("비기면 그 순서가 그대로 감\n");
    return 0;
}

int Manual(int num)
{
    srand(time(NULL));
    int row[9] = { 0,1,2,3,4,5,6,7,8 };
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
    int h = num;
    for (int i = 9; i > 0; i--)
    {
        printf("\nROUND%d   | ", 10 - i);
        a = rand() % i;
        b = row[a];
        if (g == h)
        {
            printf("선공\nPlayer   | ");
            scanf("%d", &c);
            printf("Computer | ");
            if (b % 2 == 0)
                printf("black\n");
            else if (b % 2 == 1)
                printf("white\n");
            printf("Result   | ");
            if (b < c)
                printf("win\n"), g = h, d++;
            else if (b > c)
                printf("loose\n"), g = h - 1, e++;
            else if (b == c)
                printf("draw\n"), f++;
        }
        else
        {
            printf("후공\nComputer | ");
            if (b % 2 == 0)
                printf("black\n");
            else if (b % 2 == 1)
                printf("white\n");
            printf("Player   | ");
            scanf("%d", &c);
            printf("Result   | ");
            if (b < c)
                printf("win\n"), g = h, d++;
            else if (b > c)
                printf("loose\n"), g = h - 1, e++;
            else if (b == c)
                printf("draw\n"), f++;
        }
        for (int j = 0; j < i; j++)
        {
            if (b <= row[j])
                row[j] = row[j + 1];
        }
    }
    printf("\nwin      | %d\ndraw     | %d\nloose    | %d", d, f, e);
    return 0;
}

int Auto(int num)
{
    srand(time(NULL));
    int row[9] = { 0,1,2,3,4,5,6,7,8 };
    int a, b, c;
    int d = num;
    int e = 0, f = 0, g = 0;
    int Row;
    printf("\nINSERT\n");
    scanf("%9d", &Row);
    for (int i = 9; i > 0; i--)
    {
        a = rand() % i;
        b = row[a];
        c = Row;
        for (int k = 1; k < i; k++)
            c /= 10;
        c %= 10;
        if (d == 0)
        {
            if (b < c)
                e++;
            else if (b > c)
                d++, f++;
            else if (b == c)
                g++;
        }
        else
        {
            if (b < c)
                d--, e++;
            else if (b > c)
                f++;
            else if (b == c)
                g++;
        }
        for (int j = 0; j < i; j++)
        {
            if (b <= row[j])
                row[j] = row[j + 1];
        }
    }
    printf("\nwin      | %d\ndraw     | %d\nloose    | %d", e, g, f);
    return 0;
}