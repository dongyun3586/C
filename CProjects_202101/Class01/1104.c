#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define M 100

int gun(int num);

int main()
{
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n");
    printf("����������������������������������\n\n");
    Sleep(1000);
    printf("              4�� ��� ������� ���ϴ� ���α׷� \n\n");
    printf("                                                Made by 1104 ���\n");
    Sleep(2000);
    system("cls");
    Sleep(2000);
    printf("�������� �ƽó���?\n");
    printf("�ȴٸ� 1��, �𸣸� 2���� ��������. ");

    int yesorno;
    scanf("%d", &yesorno);
    if (yesorno == 2)
    {
        printf("\n������(ت۰��, ����: magic square) �Ǵ� ����(۰��)�̶�\n");
        printf("n^2���� ���� ����, ����, �밢���� ���ڵ��� ���ϸ� ���\n");
        printf("���� ���� �������� n �� n �÷� �迭�ϴ� ���� �����̴�. \n");
        Sleep(3000);
        printf("\n\n�׷��ٸ� ���ϴ� 4�� ����� �Է��� �ּ���: ");

    }
    if (yesorno == 1)
    {

        printf("�׷��ٸ� ���ϸ� 4�� ����� �Է��� �ּ���: ");

    }

    int jin[M][M] = { 0 };
    int n, a = 1, temp, m, count = 0;
    scanf("%d", &n);
    while (n % 4 != 0)
    {
        count++;
        if (count < 3)
        {
            printf("�ٽ� �Է��� �ּ���. ");
        }
        if (count >= 3)
        {
            printf("�ٽ� �Է��϶�� ");
        }
        if (count >= 10)
        {
            printf("������ ");
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