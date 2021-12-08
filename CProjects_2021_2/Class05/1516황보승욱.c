#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int cardlist[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };           //ī�� ����Ʈ. ���迡���� A�� 1, J, Q, K�� 10���� ����ϱ� ������ ������ ���� ������.
int* rnd = cardlist;                                                        //ī�带 �������� �����ؾ� �� ������ ù ĭ�� �ּ� + i(����)�� �������� �����Ѵ�.

typedef struct
{
    char name[20];                                                          //�÷��̾� �̸�
    int nowcards[20];                                                       //�÷��̾ ���� ������ ī��
    int win;                                                                //�÷��̾ �̱� Ƚ��
}player;

typedef struct
{
    int nowcards[20];                                                        //�̸��� ���ٴ� ���� �����ϸ� �÷��̾�� ���� ����
    int win;
}cp;

void cpai(cp cpu, int first1, int first2)
{
    if (5 + first1 + first2 < 21)                                            //ai���� ������ ���� �ο�. ���� �� �� ī���� ���� 16 �����̸� �� ���� �� �̴´�.
    {
        cpu.nowcards[2] = *rnd + rand() % 13;
        printf("%d %d %d\n", first1, first2, cpu.nowcards[2]);
    }
    else
    {
        printf("%d %d\n", first1, first2);
    }
}

void compare(cp cpu1, cp cpu2, cp cpu3, player user, cp deal)             //���ϴ� �Լ�. ������ ī����� ���� ������, ������ �꿡 ���� ���� ����
{
    int playsum = 0, sum1 = 0, sum2 = 0, sum3 = 0, dealsum = 0;
    for (int i = 0; i < 19; i++)
    {
        playsum += user.nowcards[i];
        sum1 += cpu1.nowcards[i];
        sum2 += cpu2.nowcards[i];
        sum3 += cpu3.nowcards[i];
        dealsum += deal.nowcards[i];
    }
    if (playsum < dealsum && playsum <= 21 || playsum <= 21 && dealsum > 21)
    {
        user.win++;
        printf("%s : �¸�\n", user.name);
    }
    if (sum1 < dealsum && sum1 <= 21 || sum1 <= 21 && dealsum > 21)
    {
        cpu1.win++;
        printf("ai 1 : �¸�\n");
    }
    if (sum2 < dealsum && sum2 <= 21 || sum2 <= 21 && dealsum > 21)
    {
        cpu2.win++;
        printf("ai 2 : �¸�\n");
    }
    if (sum3 < dealsum && sum3 <= 21 || sum3 <= 21 && dealsum > 21)
    {
        cpu3.win++;
        printf("ai 3 : �¸�\n");
    }
}

int main()
{
    int n;
    srand(time(NULL));
    do
    {
        printf("*** ���� ���� �޴� ***\n\n");
        printf("1 : ���� �� ���� \n2 : 1�� �÷��� \n3 : ����\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("*** �� ���� ***\n\n");
            printf("������ ���� ���� �Բ� �����ϴ� ī�� �����Դϴ�.\n\n");
            printf("������ �ϴ� �ο��� ���� �� ��, �׸��� �÷��̾� �� ���Դϴ�.\n\n");
            printf("�� ������ 10���� ����� �����Ǹ�, ��� ���尡 ���� �� ���� ���� ���忡�� �¸��� �÷��̾ �����Դϴ�.\n\n");
            printf("�÷��̾���� ���� �������Լ� ������ ī�� �� ���� �й�޽��ϴ�.\n\n");
            printf("�й���� ī��� ��ο��� �����Ǹ�, �÷��̾���� �ڽ��� ī�带 ���� ���� �ൿ�� ������ �� �ֽ��ϴ�.\n\n");
            printf("�� ���� �� �徿 ���ϴ� Ƚ����ŭ �������Լ� ī�带 �� �ްų�, ī�带 ���� �ʰ� �̹� ������ �ൿ�� ��ĥ �� �ֽ��ϴ�.\n\n");
            printf("�׷��� ��� �ൿ�� ������ ����, ������ ������ ī�� �� ���� �̽��ϴ�.\n\n");
            printf("������ �÷��̾��� ������ �ൿ�� �����մϴ�.\n\n");
            printf("�������� �ڽ��� ī�带 �����ϸ�, ����� ���۵˴ϴ�.\n\n");
            printf("��ǥ�� �ڽ��� ī����� ������ 21���� ũ�� ����, 21�� ���� ����� ���� ����� ���Դϴ�.\n\n");
            printf("A�� 1�� ����ϸ�, K, Q, J�� 10���� ����մϴ�.\n\n");
            printf("�� �÷��̾���� �� ����� �����̸�, �������� ī���� ���� �� ū �÷��̾�� �������Լ� �¸��� �����ɴϴ�.\n\n");
            printf("�������� ī���� ���� �۰ų�, ī���� ���� 21�� ���� �÷��̾���� �ش� ���忡�� �й��մϴ�.\n\n");
            printf("��, ������ ī���� ���� 21�� ���� ��� ī���� ���� 21�� �Ѵ� �÷��̾ ������ ��� �÷��̾ �����Դϴ�.\n\n");
            printf("�̰����� ������ ������ ����Ǿ����ϴ�. ��ſ� ���� �ǽʽÿ�.\n\n\n");
            break;
        case 2:
            printf("������ �����ϰڽ��ϴ�.\n");
            player player1 = { 0 };                                                      //�÷��̾� ����ü ����
            cp ai1 = { 0 }, ai2 = { 0 }, ai3 = { 0 }, dealer = { 0 };                    //cp��(���� ����) ����ü ����
            int* nc1 = player1.nowcards, nc2 = player1.nowcards[1], w = player1.win;
            int* a1nc1 = ai1.nowcards, a1nc2 = ai1.nowcards[1], a1w = ai1.win;
            int* a2nc1 = ai2.nowcards, a2nc2 = ai2.nowcards[1], a2w = ai2.win;
            int* a3nc1 = ai3.nowcards, a3nc2 = ai3.nowcards[1], a3w = ai3.win;
            int* dnc1 = dealer.nowcards, dnc2 = dealer.nowcards[1];
            w = a1w = a2w = a3w = 0;                                                     //�¸� Ƚ�� �ʱ�ȭ
            printf("�÷��̾��� �̸��� �Է��Ͽ� �ֽʽÿ�.\n");
            scanf("%s", player1.name);
            for (int i = 1; i < 10; i++)                                                //10����(10��) �ݺ��ϱ�
            {
                for (int j = 0; j < 19; j++)                                            //�� ���帶�� nowcrads�� �� �ʱ�ȭ
                {
                    *(nc1 + j) = 0;
                    *(a1nc1 + j) = 0;
                    *(a2nc1 + j) = 0;
                    *(a3nc1 + j) = 0;
                    *(dnc1 + j) = 0;
                }
                printf("*** ���� %d ***\n", i);
                printf("ī�带 �̰ڽ��ϴ�.\n\n");                                       //�÷��̾� ī�� �̱�
                nc1 = *rnd + rand() % 13;
                nc2 = *rnd + rand() % 13;
                printf("%s�� ī�� : %d, %d\n", player1.name, nc1, nc2);
                a1nc1 = *rnd + rand() % 13;                                            //ai���� ī�� �̱�
                a1nc2 = *rnd + rand() % 13;
                a2nc1 = *rnd + rand() % 13;
                a2nc2 = *rnd + rand() % 13;
                a3nc1 = *rnd + rand() % 13;
                a3nc2 = *rnd + rand() % 13;
                printf("ai 1�� ī�� : %d, %d\n", a1nc1, a1nc2);
                printf("ai 2�� ī�� : %d, %d\n", a2nc1, a2nc2);
                printf("ai 3�� ī�� : %d, %d\n", a3nc1, a3nc2);
                int patern, times = 2;
                do
                {
                    printf("� �ൿ�� �Ͻðڽ��ϱ�?\n");
                    printf("1 : ī�� �̱�\n");
                    printf("2 : ���� �ѱ��\n");
                    scanf("%d", &patern);
                    if (patern == 1)
                    {
                        player1.nowcards[times] = *rnd + rand() % 13;
                        printf("%s�� ī�� : %d, %d, %d\n", player1.name, nc1, nc2, player1.nowcards[2]);
                        printf("ai 1�� ī�� : %d, %d\n", a1nc1, a1nc2);
                        printf("ai 2�� ī�� : %d, %d\n", a2nc1, a2nc2);
                        printf("ai 3�� ī�� : %d, %d\n", a3nc1, a3nc2);
                    }
                    else if (patern == 2)
                    {
                        break;
                    }
                } while (patern != 2);
                printf("%s�� ī�� : %d, %d, %d\n", player1.name, nc1, nc2, player1.nowcards[2]);
                printf("ai 1�� ī�� : ");
                cpai(ai1, a1nc1, a1nc2);
                printf("ai 2�� ī�� : ");
                cpai(ai2, a2nc1, a2nc2);
                printf("ai 3�� ī�� : ");
                cpai(ai3, a3nc1, a3nc2);
                printf("������ �����Դϴ�.\n");
                dnc1 = *rnd + rand() % 13;
                dnc2 = *rnd + rand() % 13;
                printf("������ ī�� : ");
                cpai(dealer, dnc1, dnc2);
                printf("����� �����ϰڽ��ϴ�.\n");
                compare(ai1, ai2, ai3, player1, dealer);
                printf("\n\n");
            }
            printf("%s : %dȸ �¸�\n", player1.name, w);
            printf("ai 1 : %dȸ �¸�\n", a1w);
            printf("ai 2 : %dȸ �¸�\n", a2w);
            printf("ai 3 : %dȸ �¸�\n", a3w);
        case 3:
            break;
        }
    } while (n != 3);
    return 0;
}