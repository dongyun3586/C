#include <stdio.h>
#include <time.h>                               // time() ����
#include <stdlib.h>                             // rand(), srand() ����
#include <math.h>                               // double pow(double base, double exponent);

void start(void);                               // ���� �Է�
void problem(int a, int b, int n, int m);          // ���� ���, �Է�, ��� ���

int main() {
    printf("*** �ϻ� ���� ���α׷��Դϴ� ***\n");
    printf("*** ���ڸ� �Է��ϼ��� ***\n");

    //���� �Է� �Լ��� �̵�
    start();
    return 0;
}

void start(void) {
    int a, b, n, m;
    printf("\n");
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ����\n");
    printf("4. ������(��)\n");
    printf("5. �����ϱ�\n\n");

    printf("���� �߿��� �����ϼ��� : ");
    scanf("%d", &m);

    //m�� ������ ������ ������ �ݺ�
    while (m < 1 || m>5) {
        printf("�ٽ� �Է��ϼ��� : ");
        scanf("%d", &m);
    }

    //m�� 5�� ��� �Լ� ����
    if (m == 5)
        return;

    printf("�ڸ��� �ΰ��� �Է��ϼ���(1~5) : ");
    scanf("%d %d", &a, &b);

    //a,b�� ������ ������ ������ �ݺ�
    while (a < 1 || a>5 || a < 1 || b>5) {
        printf("�ٽ� �Է��ϼ��� : ");
        scanf("%d %d", &a, &b);
    }

    printf("���� ������ �Է��ϼ���(1~50) : ");
    scanf("%d", &n);

    //n�� ������ ������ ������ �ݺ�
    while (n < 1 || n>50) {
        printf("�ٽ� �Է��ϼ��� : ");
        scanf("%d", &n);
    }

    //���� �Լ��� �̵�
    problem(a, b, n, m);
}

void problem(int a, int b, int n, int m) {
    int ans, cnt = 0, cnt1 = 0, flag[100] = { 0 }, x, y, temp, cmd, enter;
    long int t, t0;

    printf("�����Ϸ��� enterŰ�� ��������.");

    //getchar()�� enterŰ �Է�
    //�� scanf()���� enterŰ�� �̹� �Է��߱� ������ �ѹ� �� �Է¹޴´�
    getchar();
    enter = getchar();

    //enterŰ�� ������ �� ����
    if (enter == '\n') {
        printf("\n");
        srand((unsigned int)time(NULL));

        //���� ���� �� �ð��� �Է¹޴´�
        t0 = time(NULL);

        //n��ŭ ���� ���
        for (int i = 0; i < n; i++) {
            //������ x,y ����(a �ڸ���, b �ڸ���)
            x = rand() % (int)(pow(10, a) - pow(10, a - 1)) + pow(10, a - 1);
            y = rand() % (int)(pow(10, b) - pow(10, b - 1)) + pow(10, b - 1);

            //x�� y���� ���� ��� �ڸ� �ٲ�
            if (x < y) {
                temp = x;
                x = y;
                y = temp;
            }
            switch (m) {
            case 1: printf("%d. %d + %d = ", i + 1, x, y);
                scanf("%d", &ans);
                //�Է¹��� ���� ������ �ƴ� ��� �迭�� ����,cnt++
                if (ans != x + y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 2: printf("%d. %d * %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x * y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 3: printf("%d. %d - %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x - y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 4: printf("%d. %d / %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x / y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            }
        }
        t = time(NULL);

        printf("���� ���� �� : %d��\n", n - cnt);
        printf("����� : %.2f%%\n", ((float)(n - cnt) / n) * 100);
        printf("Ʋ�� ���� : ");

        //Ʋ�� ������ �� ���
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                printf("%d�� ", i + 1);
                cnt1++;
            }
        }

        //Ʋ�� ������ ���� ���
        if (!cnt1)
            printf("����");

        printf("\n�ɸ� �ð� : %ld��\n\n", t - t0);
        printf("1. �ٽ��ϱ�\n");
        printf("2. ó������\n");
        printf("3. �����ϱ�\n\n");
        printf("���� �߿��� �����ϼ��� : ");
        scanf("%d", &cmd);

        //������ ������ ������ �ݺ�
        while (cmd < 1 || cmd>3) {
            printf("�ٽ� �Է��ϼ��� : ");
            scanf("%d", &cmd);
        }
        switch (cmd) {
        case 1: problem(a, b, n, m); break;      //���� �ٽ� ����
        case 2: start(); break;                  //���� �ٽ� �Է�
        case 3: break;                          //����
        }
    }
}
