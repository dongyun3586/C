#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define C 3
#define M 12
void hello();

int main()
{
    printf("1107 ���¿�\n");
    hello();
    printf("������ �˰���� ��¥�� �Է����ּ���\n");

    int a[C + 1];
    int dal[M + 1] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0, i, j;

    for (j = 1; j <= C; j++)
    {
        scanf("%d", &a[j]);
    }

    dal[2] = 28;

    if (a[1] % 4 == 0)
    {
        if (a[1] % 100 == 0)
        {
            if (a[1] % 400 == 0)
            {
                dal[2] = 29;
            }
            else
            {
                dal[2] = 28;
            }
        }
        else
        {
            dal[2] = 29;
        }
    }

    sum += (a[1] - 1) * 365;
    sum += (a[1] - 1) / 4;
    sum -= (a[1] - 1) / 100;
    sum += (a[1] - 1) / 400;

    for (j = 1; j <= a[2] - 1; j++)
    {
        sum += dal[j];
    }
    sum += a[3];

    if (sum % 7 == 1)
        printf("�������Դϴ�");

    else if (sum % 7 == 2)
        printf("ȭ�����Դϴ�");

    else if (sum % 7 == 3)
        printf("�������Դϴ�");

    else if (sum % 7 == 4)
        printf("������Դϴ�");

    else if (sum % 7 == 5)
        printf("�ݿ����Դϴ�");

    else if (sum % 7 == 6)
        printf("������Դϴ�");

    else if (sum % 7 == 0)
        printf("�Ͽ����Դϴ�");

    printf("\n");

    if (a[2] == 1 && a[3] == 1)
    {
        printf("�����Դϴ�.");
    }

    if (a[2] == 3 && a[3] == 1)
    {
        printf("�������Դϴ�.");
    }

    if (a[2] == 6 && a[3] == 6)
    {
        printf("�������Դϴ�.");
    }

    if (a[2] == 8 && a[3] == 15)
    {
        printf("�������Դϴ�.");
    }

    if (a[2] == 10 && a[3] == 3)
    {
        printf("��õ���Դϴ�.");
    }

    if (a[2] == 10 && a[3] == 9)
    {
        printf("�ѱ۳��Դϴ�.");
    }

    if (a[2] == 12 && a[3] == 25)
    {
        printf("ũ���������Դϴ�");
    }

    if (a[2] == 4 && a[3] == 5)
    {
        printf("�ĸ����Դϴ�.");
    }

    if (a[2] == 7 && a[3] == 17)
    {
        printf("�������Դϴ�.");
    }

    if (a[2] == 10 && a[3] == 1)
    {
        printf("������ ���Դϴ�.");
    }

    if (a[2] == 5 && a[3] == 1)
    {
        printf("�ٷ����� ���Դϴ�.");
    }

    if (a[2] == 5 && a[3] == 5)
    {
        printf("��̳��Դϴ�.");
    }

    if (a[2] == 5 && a[3] == 8)
    {
        printf("����̳��Դϴ�.");
    }

    if (a[2] == 5 && a[3] == 15)
    {
        printf("������ ���Դϴ�.");
    }
    return 0;
}

void hello() {
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf(" ��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf(" ��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("��");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*\n");
    Sleep(300);
}
