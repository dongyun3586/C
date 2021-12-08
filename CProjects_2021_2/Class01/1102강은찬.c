#include <stdio.h>
#include <stdlib.h>
#include <windows.h>                //Sleep, system �Լ��� ����ϱ� ���� �ʿ��� �������

char num[10];          //���� �迭�� �Է¹޴´�.
int n, R;
char R_number[50] = { 0 };
char* p = R_number;                  //������ �̿�

void explain();
void input();
int change10(char nun[10], int n);                   //10������ ��ȯ
void changeR(int num, int R, char p[50]);               //�Է¹��� ������ ��ȯ
void output(int R, char p[50]);

int main()
{
    explain();                                      //���α׷��� ���� ������ �ϴ� �Լ��� ����
    input();
    printf("�� : %s\n", num);
    printf("���� ���� : %d\n", n);
    printf("10���� : %d\n", change10(num, n));
    changeR(change10(num, n), R, p);
    output(R, p);
    return 0;
}

void explain()
{
    printf("�ȳ��ϼ��� ���� �ٸ� �������� �ٲ�帳�ϴ�!\n");
    Sleep(1000);                                 //1�� ��ٸ���
    printf("���� 8�ڸ�, ������ 16�������� �����մϴ�.\n");
    Sleep(2000);                                                 //2�� ��ٸ���
    system("cls");
}

void input()
{
    printf("���� ���� ������ �Է��ϼ���\n");
    scanf("%s %d", &num, &n);

    printf("���� �������� �ٲܱ��?\n");
    scanf("%d", &R);                                  //R�� �ٲ� �����̴�.
    system("cls");
}

int change10(char num[10], int n)
{
    int number = 0;
    int i = 1, d = strlen(num) - 1;

    while (d >= 0)
    {
        if (num[d] >= 48 && num[d] <= 57)            //�Է��� �����϶�
        {
            number += (num[d] - 48) * i;
        }
        else                                   //�Է��� �빮�� ���ĺ� �϶�
        {
            number += (num[d] - 55) * i;
        }
        i = i * n;
        d--;
    }

    return number;
}

void changeR(int num, int R, char p[50])                      //�Է¹��� ���� R�������� �ٲ� �ִ� �Լ��̴�.
{
    int i = 0;

    while (1)
    {
        if (num % R < 10)                 //�Է��� �����϶�
        {
            p[i] = 48 + num % R;              //�迭�� �����ϱ� ������ ������ ��� 0�� �ƽ�Ű�ڵ��� 48�� �����ش�.
        }
        else                                 //�Է��� �빮�� ���ĺ� �϶�
        {
            p[i] = 55 + num % R;             //�迭�� �����ϱ� ������ ���ĺ��� ��� A�� �ƽ�Ű�ڵ��� 65���� A�� ���� 10�� ���� 55�� �����ش�.
        }
        i++;
        num = num / R;
        if (num == 0)
        {
            break;
        }
    }
}

void output(int R, char p[50])          //������ ��ȯ�� ���� ������ִ� �Լ��̴�.
{
    printf("%d���� : ", R);
    int len = strlen(p);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", p[i]);
    }
    printf("\n\n");
}          //�� 101��