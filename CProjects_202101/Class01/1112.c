#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//Sleep, system
#define M 101

int digitnum(int n);//ĭ�� �����ֱ� ���� �� ������ �ڸ����� ���� ū �ڸ����� ���� ���� �ڸ����� ���Ѵ�.
int magic_square(int a, int b, int n);//�������� ä���ִ� �κ�
int magic_square_sum(int n);//����.����.�밢�� ��
void print_magic_square(int n);//�������� ����ϴ� �κ�

int main()
{
    int jin[M][M] = { 0 };//�������� ���� 2���� �迭
    int num, banbok;

    printf("�ȳ��ϼ���! �������� ����� �帳�ϴ�.");
    Sleep(2000);//1000=1��, 2�� ��ٸ�
    printf("\n�������� ����, ����, �밢���� ���� ���������� ���簢�� ������� �迭�� �� �Դϴ�.\n");
    Sleep(3000);
    system("cls");//clear
    printf("��� �������� ������? ");//�ݺ�
    scanf("%d", &banbok);
    system("cls");//clear

    printf("n*n�������� ����� �帳�ϴ�.\n");
    for (int i = 1; i <= banbok; i++)
    {
        printf("\n41������ Ȧ���� �Է��� �ּ���.");//�� �Ҽ��� ������ ���� �Ѿ��, 100 �̻����� �Ѿ�� �����÷ο찡 ���� �� �ִ�.
        scanf("%d", &num);
        while (num % 2 == 0 || num > 41)
        {
            printf("41������ Ȧ���� �ٽ� �Է��� �ּ���.");
            scanf("%d", &num);
        }

        printf("\n<%d�� ������> %d*%d\n", i, num, num);
        printf("����.���� �밢�� �� = %d\n\n", magic_square_sum(num));
        print_magic_square(num);//������ ���
        Sleep(1000);//1�� ��ٸ�
    }
    return 0;
}

//�������� ä���ִ� �κ�
int magic_square(int x, int y, int n)
{
    int jin[M][M] = { 0 };//�������� ���� 2���� �迭
    int a = 1, b = (n + 1) / 2; //�������� a->1�� b->��� ��
    for (int i = 1; i <= n * n; i++)
    {
        jin[a][b] = i;//�迭�� ���� ä�� ����

        a--;//������� �̵�
        b++;//������ �̵�

        //���� ����� ��
        if (a == 0)

        {
            a = n;//n������ �ű�
        }

        //���� ����� ��
        if (b == n + 1)
        {
            b = 1;//1���� �ű�
        }

        //��� ���� ��� �Ѿ�� ��
        if (a == n && b == 1)
        {
            //1�� n������ ���� ������� �̵��ϰ� �Ǹ� ��� ���� ��� �Ѿ
            //n�� 1���� �ű�� �̹� ���ڰ� ä���� ����
            //�̸� ��� ����Ͽ� �ڵ带 ¥�� ��Ʊ� ������ �� ��츦 ���� ���� ������

            //1�� n������ �Ѿ���� n�� 1���϶��� ����ϴ� ����=���� if������ n�� 1���� �Ǿ��� ����
            //������ n�� 1���� ���� ��������� �ʾ� �Ʒ��� �̵��Ͽ� ä������ ����̱⿡ �Ʒ��� if������ �Ű���
            //���� �� if�������� ������ ���� ����
            a = 2;
            b = n;
        }

        //ĭ�� ������� ���� ��
        if (jin[a][b] != 0)
        {
            //���� �밢������ �̵��� �ڿ� ������ ��ġ���� �� �� �Ʒ��� �������� �̵�
            //���� �ุ 1 ���ϴ� ���� �ƴ϶� ���� 2 ���ϰ� ���� 1 ������
            a += 2;
            b -= 1;
        }
    }
    return jin[x][y];//������ ��ȯ
}

//ĭ�� �����ֱ� ���� �� ������ �ڸ����� ���� ū �ڸ����� ���� ���� �ڸ����� ����
int digitnum(int n)
{
    int result = 0;

    while (n >= 1)
    {
        n /= 10;
        result++;
    }

    return result;//�ڸ��� ��ȯ
}

//����.����.�밢�� ��
int magic_square_sum(int n)
{
    int result = 0;

    for (int i = 1; i <= n * n; i++)
    {
        result += i;
    }
    result /= n;

    return result;
}

//�������� ����ϴ� �κ�
void print_magic_square(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", magic_square(i, j, n));//���� ���

            //���� ū �ڸ��� ���� ���� ĭ���� ������
            //���� ��ĭ�� ���� = �ִ��ڸ���-���� �ڸ���
            for (int k = 1; k <= digitnum(n * n) - digitnum(magic_square(i, j, n)); k++)
            {
                printf(" ");
            }
        }
        printf("\n\n");
    }
    printf("\n");
}
