#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int priceofsamsung(int k); //���������� �ֽ� ���� ����
int priceoftesla(int l); //�������� �ֽ� ���� ����
int priceofapple(int m); //�ۻ��� �ֽ� ���� ����
int priceofgamestop(int n); //���������� �ֽ� ���� ����
int maesudo(int k, int i, int buy[], int don); //�ֽ��� �ŵ��� �ż�
void printjusik(int i, int k, int n); //�ֽ��� ���� ��Ȳ, �ֽ� �� ���� ���� ���

int main_000() {
    long long int k = 10000, l = 15000, m = 20000, n = 5000, don = 300000;
    int buy[5] = { 0 }, yes;

    printf("\n\n\n\n\n\n\n          ================================================================\n");
    printf("          ==================== �� �� ��   �� �� �� �� ====================\n");
    printf("          ================================================================\n\n\n\n\n\n\n\n");
    printf("                         $$$  press '777' to start  $$$                        \n\n\n\n\n\n\n");
    scanf("%d", &yes);
    printf("\n\n\n\n\n\n");

    if (yes == 777) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '���� ���迡 ���� ���� ȯ���մϴ�' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n 'ȥ�������� ����� ���Ҿ� ���Ÿ��� �ֽĽ����� ���� �λ��� ������� �� ������ �̴ϴ�'\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '���� �� �ֽ� ǰ���� �ֽ��ϴ�' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n <��������> <������> <�ۻ�> <��������> \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '���������� �̵��� ���ݰ� ���� ���������� ����� �ɹڼ��� �Բ� �Ͻñ�...' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '30�ϰ��� �ֽĽ���, ū ���� ���� ���� �����ʴϱ�?' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '�׷��ٸ�, ����� ���ϴ�....' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '���� ���� �ʵ��� �����Ͻʽÿ�....���ŵ� �ý����� ���� �Ұ��մϴ�....\n 20���� ������ ������ ����� �ſ����� ������ ���Դϴ�....' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(5000);

        printf("          5�� 1�� KOSDAQU �ü�\n\n");
        printf("        1. <��������>  10000�� -\n");
        printf("        2.  <������>   15000�� -\n");
        printf("        3.   <�ۻ�>    20000�� -\n");
        printf("        4.<��������>  5000�� -\n");
        for (int i = 2; i <= 20; i++) {
            printf("\n\n\n\n\n\n�ż� Ȥ�� �ŵ��� �ֽ� ���� �Է��ϼ���.\n");
            don = maesudo(k, 1, buy, don);
            don = maesudo(l, 2, buy, don);
            don = maesudo(m, 3, buy, don);
            don = maesudo(n, 4, buy, don);
            printf("\n\n\n          5�� %d�� KOSDAQU �ü�\n\n", i);
            k = priceofsamsung(k);
            l = priceoftesla(l);
            m = priceofapple(m);
            n = priceofgamestop(n);
            printf("\n\n\n\n");

            printjusik(1, k, buy[1]);
            printjusik(2, l, buy[2]);
            printjusik(3, m, buy[3]);
            printjusik(4, n, buy[4]);

            if (don < 0)
                break;
        }
        if (don >= 500000)
            printf("\n\n\n\n\n����� �ſ� ����� 1.\n���ڿ� ����� �����ŵ���?\n\n\n");
        else if (don >= 300000 && don < 500000)
            printf("\n\n\n\n\n����� �ſ� ����� 2.\n���ݸ� �� �����Ͻø� �� ū ���� ���� �� ������ �� ������.\n\n\n");
        else if (don < 300000 && don >= 200000)
            printf("\n\n\n\n\n����� �ſ� ����� 3.\n������ �� ã���̱���...\n\n\n");
        else if (don < 200000)
            printf("\n\n\n\n\n����� �ſ� ����� 4.\n���, �ֽ��� �����Դϴ�.\n\n\n");
    }


    else
        printf("��Ȯõ���� ��ȸ�� ������ �����ñ�.......\n\n");

    return 0;

}

int priceofsamsung(int k) {
    int a;
    srand(time(NULL));
    a = rand() % 41 - 20;
    k = k * (100 + a) / 100;
    printf("       1. <��������>  %6d\ ", k);
    if (a > 10)
        printf("��\n");
    else if (a > 0 && a <= 10)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -10 && a < 0)
        printf("v\n");
    else
        printf("��\n");
    return k;
}

int priceoftesla(int l) {
    int a;
    srand(time(NULL));
    a = rand() % 61 - 30;
    l = l * (100 + a) / 100;
    printf("        2. <������>  %6d\ ", l);
    if (a >= 15)
        printf("���\n");
    else if (a > 5 && a < 15)
        printf("��\n");
    else if (a > 0 && a <= 5)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -5 && a < 0)
        printf("v\n");
    else if (a < -5 && a > -15)
        printf("��\n");
    else
        printf("���\n");
    return l;
}

int priceofapple(int m) {
    int a;
    srand(time(NULL));
    a = rand() % 41 - 20;
    m = m * (100 + a) / 100;
    printf("         3. <�ۻ�>  %6d\ ", m);
    if (a > 10)
        printf("��\n");
    else if (a > 0 && a <= 10)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -10 && a < 0)
        printf("v\n");
    else
        printf("��\n");
    return m;
}

int priceofgamestop(int n) {
    int a;
    srand(time(NULL));
    a = rand() % 81 - 40;
    n = n * (100 + a) / 100;
    printf("       4.<��������> %6d\ ", n);
    if (a >= 15)
        printf("���\n");
    else if (a > 5 && a < 15)
        printf("��\n");
    else if (a > 0 && a <= 5)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -5 && a < 0)
        printf("v\n");
    else if (a < -5 && a > -15)
        printf("��\n");
    else
        printf("���\n");
    return n;
}

int maesudo(int k, int i, int buy[], int don) {
    printf("\n���� ��밡�ɱݾ� : %d\n ", don);
    int a;
    switch (i) {
    case 1:
        printf("�������� ");
        break;
    case 2:
        printf("������ ");
        break;
    case 3:
        printf("�ۻ� ");
        break;
    case 4:
        printf("�������� ");
    }
    printf("\n�ż�(�ŵ��� -�� �Է�): ");
    scanf("%d", &a);
    buy[i] += a;
    don -= k * a;

    return don;
}

void printjusik(int i, int k, int n) {
    switch (i) {
    case 1:
        printf("\n�������� ");
        break;
    case 2:
        printf("������ ");
        break;
    case 3:
        printf("�ۻ� ");
        break;
    case 4:
        printf("�������� ");
    }
    printf(":  %d��, �� %d��\n", n, n * k);
}