#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum gun { scissors = 1, rock, paper };
void game();        //��ü���� ���� �Լ�
int bet();         //���� �ݾ� ���� �Լ�
void appoint();     //���� �ݾ�, ��ǥ �ݾ� ���� �Լ�
void select();      //�ֱ��� ���� �Լ�

int a;      //���� �ݾ�
int b;      //��ǥ �ݾ�
int p = 1;      //���� Ƚ��
int choice1, choice2;   //�ֱ���

int main()
{
    //���� �ݾװ� ��ǥ �ݾ� ����
    appoint();
    //���� �÷���
    game();
}

void select() {
    printf("���� : ����-1, ����-2, ��-3\n");
    scanf("%d %d", &choice1, &choice2);
    printf("\n");
    if ((choice1 != 1 && choice1 != 2 && choice1 != 3) || (choice2 != 1 && choice2 != 2 && choice2 != 3))
    {
        printf("�ٽ� �Է��� �ּ���\n\n");
        select();
    }
    return choice1, choice2;
}

void appoint() {
    printf("���� �ݾ� : ");
    scanf("%d", &a);
    printf("��ǥ �ݾ� : ");
    scanf("%d", &b);

    if (2 * a > b || b > 10 * a)
    {
        printf("��ǥ �ݾ��� ���� �ݾ��� 2��~10�� ���̷� ������ �ּ���.\n\n");
        appoint();
    }
    return 0;
}

int bet() {
    int n;      //���� �ݾ�
    printf("�����ݾ� : %d\n", a);
    printf("���� �ݾ� : ");
    scanf("%d", &n);
    if (n > a)
    {
        printf("���� �ݾ��� ���� �ݾ��� �Ѿ�� �ȵ˴ϴ�.\n\n");
        n = bet();
    }
    return n;
}

void game() {
    char* rsp[3] = { "����", "����", "��" };
    srand((unsigned int)time(NULL));
    int c, n;

    //�ֱ���(��)
    printf("\n�ֱ���\n");
    select();

    //�ֱ���(��ǻ��)
    int z = rand() % 3;
    int w = rand() % 3;

    //��� ǥ��
    printf("�� : %s %s\n", rsp[choice1 - 1], rsp[choice2 - 1]);
    printf("��ǻ�� : %s %s\n", rsp[z], rsp[w]);

    //����
    n = bet();

    //�ϳ� ���� �� (��)
    printf("�ϳ� ���� ��\n");
    printf("%s %s �߿��� ����, %s-%d, %s-%d\n", rsp[choice1 - 1], rsp[choice2 - 1], rsp[choice1 - 1], choice1, rsp[choice2 - 1], choice2);
    scanf("%d", &c);

    //�ϳ� ���� �� (��ǻ��)
    printf("\n�� : %s\n", rsp[c - 1]);
    int k;
    int s;
    k = rand() % 2 + 1;
    if (k == 1)
    {
        printf("��ǻ�� : %s\n", rsp[z]);
        s = z + 1;
    }
    else
    {
        printf("��ǻ�� : %s\n", rsp[w]);
        s = w + 1;
    }

    //��� ǥ�� �� �� ����
    if (c > s || (c == 1 && s == 3))
    {
        printf("�¸�!\n");
        a = a + n;
        printf("���� ���� ��: %d\n", a);
    }
    else if (c == s)
    {
        printf("���º�\n");
        a = a;
        printf("���� ���� ��: %d\n", a);
    }
    else
    {
        printf("�й�\n");
        a = a - n;
        printf("���� ���� ��: %d\n", a);
    }

    if (a <= 0) {
        printf("game over: �Ļ��߽��ϴ�.\n");
        return;
    }
    else if (a >= b) {
        printf("��ǥ�� �����߽��ϴ�!\n");
        return;
    }
    else
    {
        int input;
        printf("����Ͻðڽ��ϱ�?(��-1,�ƴϿ�-0)");
        scanf("%d", &input);
        if (input == 1)
        {
            p++;
            if (p >= 10)
            {
                printf("���� Ƚ���� �ʰ��Ͽ����ϴ�\n");
                printf("game over");
                return;
            }
            game();
        }
    }
}