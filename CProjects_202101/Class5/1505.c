#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process1(int k);

void process2(int a, int k, int s);

void process3(int k, int p);

void process4(int k, int a, int p, int s);
int main()
{
    srand(time(NULL));

    int sum = 0;                //������ ���� ���� ���� �հ�
    int p;                      //�÷��̾� ��
    printf("�÷��̾� ���� �Է��ϼ��� : ");
    scanf("%d", &p);
    printf("\n");
    int k = rand() % p + 1;     //������ ���� ���� �� ���� �������� ���ϴ� ������ ���� �Ű�����
    int a = rand() % 91 + 10;   //�������� Ż�� ���� ����
    int s = rand() % 3 + 3;     //������ ���� ���ϴ� ���� ���� ����

    printf("��Ģ : ");
    printf("�÷��̾�� ���ʴ�� Ư�� �������� ���ڸ� �����ϰ� �� ���ڴ� ��� ��������.\n");
    printf("������ ���ڰ� Ż�� ���� �̻��� �Ǹ� Ż�� ���ڸ� �Ѱ� �� ����� �й��Ѵ�.\n");
    printf("��, ������ ���� ���ϴ� ���� ������ �Ѿ�� ���ڸ� ���ϸ� ��Ģ�з� �й��Ѵ�.\n\n\n");
    printf("Ż�� ���ڸ� �������� �����մϴ�.\n");
    printf("Ż�� ���� : %d\n\n\n", a);
    printf("������ ���� ���ϴ� ���� ������ �������� �����մϴ�.\n");
    printf("������ ���� ���ϴ� ���� ���� : 1~%d\n\n\n", s);
    printf("���� ����\n\n");

    if (p == 2) //�÷����ϴ� ����� 2���϶�
    {
        process1(k);
        process2(k, a, s);
    }
    else //�÷����ϴ� ����� 3�� �̻��϶�
    {
        process3(k, p);
        process4(k, a, p, s);
    }

    printf("���� ����");

    return 0;
}

void process1(int k)
{
    srand(time(NULL));
    printf("���� ���ϱ�\n");
    //���� ��� �κ�
    if (k == 1)
        printf("player 1 ����\n");
    else
        printf("player 2 ����\n");

    return 0;
}

void process2(int k, int a, int s)
{
    int x;          //�����ư��鼭 ���ϴ� ����
    int sum = 0;    //���ϴ� ������ ����

    while (1)
    {
        printf("player %d�� �߰� ���� �Է� : ", k);    //player k���� ���� ����
        scanf("%d", &x);                               //�߰� ���� �Է�
        printf("\n");
        sum = sum + x;
        printf("�հ� : %2d\n", sum);
        //���� ���� Ż�� ���� �̻��� �� ��
        if (sum >= a)
        {
            printf("Ż�� ���ڿ� �����߽��ϴ�\n");
            printf("player %d �й�\n", k);
            break;
        }
        //���ϰ��� �ϴ� ���� ������ �ʰ�������(��Ģ)
        if (x > s)
        {
            printf("������ �ʰ��߽��ϴ�\n");
            printf("player %d ��Ģ��\n", k);

            break;
        }
        //�����ư��� ���ϱ�(���� �� ���� �ٲٱ�)
        if (k == 1)
        {
            k = 2;
        }
        else
        {
            k = 1;
        }
    }
}

void process3(int k, int p)
{
    printf("���� ���ϱ�\n");
    printf("player %d ����\n", k);
    printf("���� : ");

    //���� ��� �κ�(Ư���� �������� ����)
    for (int i = k; i <= p; i++)
    {
        printf("%d, ", i);
    }
    for (int i = 1; i < k; i++)
    {
        printf("%d, ", i);
    }

    printf("%d ������ ����\n\n\n", k);
}

void process4(int k, int a, int p, int s)
{
    int x, sum = 0;

    while (1)
    {
        printf("player %d�� �߰� ���� �Է� : ", k);
        scanf("%d", &x);
        printf("\n");
        sum = sum + x;
        printf("�հ� : %d\n", sum);
        //���� ���� Ż�� ���� �̻��� �� ��
        if (sum >= a)
        {
            printf("Ż�� ���ڿ� �����߽��ϴ�\n");
            printf("player %d �й�\n\n\n", k);
            break;
        }
        //���ϰ��� �ϴ� ���� ������ �ʰ�������(��Ģ)
        if (x > s)
        {
            printf("������ �ʰ��߽��ϴ�\n");

            printf("player %d ��Ģ��\n\n\n", k);
            break;
        }
        //���� �ٲٱ�
        k = k + 1;
        //������ �÷��̾�� �÷��̾� 1�� �ٽ� �� ��
        if (k > p)
        {
            k = k - p;
        }
    }
}