#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define M 100

int gun(int num);

int main()
{
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("□□□□□□□■□□□□■□□□■□■□□□□□□□□□□□□□□\n");
    printf("□■■■■■□■□□□□■□□□■□■□□□□■■■■■□■□□□\n");
    printf("□■□□□■□■□□□□■■■■■□■■■□□□□■□□□■□□□\n");
    printf("□■□□□■□■■■□□■□□□■□■□□□□□■□■□□■□□□\n");
    printf("□■□□□■□■□□□□■■■■■□■□□□□■□□□■□■□□□\n");
    printf("□■■■■■□■□□□□□□□□□□□□□□□□□□□□□■□□□\n");
    printf("□□□□□□□■□□□□□□□□■■■□□□□□□□■□□□□□□\n");
    printf("□□□□□□□■□□□□□□□■□□□■□□□□□□■□□□□□□\n");
    printf("□□□□□□□□□□□□□□□■□□□■□□□□□□■■■■■■□\n");
    printf("□□□□□□□□□□□□□□□□■■■□□□□□□□□□□□□□□\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n\n");
    Sleep(1000);
    printf("              4의 배수 마방식을 구하는 프로그램 \n\n");
    printf("                                                Made by 1104 김건\n");
    Sleep(2000);
    system("cls");
    Sleep(2000);
    printf("마방진을 아시나요?\n");
    printf("안다면 1번, 모르면 2번을 누르세요. ");

    int yesorno;
    scanf("%d", &yesorno);
    if (yesorno == 2)
    {
        printf("\n마방진(魔方陣, 영어: magic square) 또는 방진(方陣)이란\n");
        printf("n^2개의 수를 가로, 세로, 대각선의 숫자들을 더하면 모두\n");
        printf("같은 값이 나오도록 n × n 꼴로 배열하는 숫자 놀이이다. \n");
        Sleep(3000);
        printf("\n\n그렇다면 원하는 4의 배수를 입력해 주세요: ");

    }
    if (yesorno == 1)
    {

        printf("그렇다면 원하면 4의 배수를 입력해 주세요: ");

    }

    int jin[M][M] = { 0 };
    int n, a = 1, temp, m, count = 0;
    scanf("%d", &n);
    while (n % 4 != 0)
    {
        count++;
        if (count < 3)
        {
            printf("다시 입력해 주세요. ");
        }
        if (count >= 3)
        {
            printf("다시 입력하라고 ");
        }
        if (count >= 10)
        {
            printf("제에발 ");
        }
        scanf("%d", &n);
    }
    m = n / 4;
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            a++;
    }
}
{
    jin[i][j] = a;

    for (int i = 1; i <= n - m; i++)
    {
        for (int j = 1; j <= n - m; j++)
        {
            if (i <= m || i > n - m)
            {
                if (j > m && j <= n - m)
                {
                    temp = jin[i][j];
                    jin[i][j] = jin[n - i + 1][n - j + 1];
                    jin[n - i + 1][n - j + 1] = temp;

                    temp = jin[j][i];
                    jin[j][i] = jin[n - j + 1][n - i + 1];
                    jin[n - j + 1][n - i + 1] = temp;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", jin[i][j]);
            for (int k = 1; k <= gun(n * n) - gun(jin[i][j]); k++)
            {
                printf(" ");
            }
        }
        printf("\n\n");
    }
    return 0;
}

int gun(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }

    return count;
}