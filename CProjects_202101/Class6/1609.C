
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void scanword_1(int n1, char ko_1[100][100], char en_1[100][100]); // 1 level �ܾ �Է¹޴� �Լ�
void scanword_2(int n2, char ko_2[100][100], char en_2[100][100]); // 2 level   ~~~
void scanword_3(int n3, char ko_3[100][100], char en_3[100][100]); // 3 level   ~~~

// ���� 1, 2, 3, �ܰ��� ������ �Լ�
int quize_1(int n1, int score, char ko_1[100][100], char en_1[100][100], char ans_1[100][100]);
int quize_2(int n2, int score, char ko_2[100][100], char en_2[100][100], char ans_2[100][100]);
int quize_3(int n3, int score, char ko_3[100][100], char en_3[100][100], char ans_3[100][100]);

// �� ������ �ܾ �����ϰ� �����ִ� �Լ�. ��, �ߺ��� ����.
void rand_1(int a[100], int n1);
void rand_2(int a[100], int n2);
void rand_3(int a[100], int n3);


int main()
{
    // ���� ����
    char ko_1[100][100], ko_2[100][100], ko_3[100][100]; // ko_i�� i ���̵��� �ܾ��� �ѱ� ��
    char en_1[100][100], en_2[100][100], en_3[100][100]; // en_i�� i ���̵��� ����
    int n1 = 0, n2 = 0, n3 = 0;                                // ni�� i ���̵��� �ܾ� ����


    // ���ӿ� ���� ������ �ȳ� ��Ʈ
    printf("*** �ܾ��� ���迡 ���� ���� ȯ���մϴ�. �ܾ� �����ͷ��� ������ ������ ���ô�!! ***\n");
    printf("���� ���� ���� �ܾ ���� �Է��� �ּ���\n\n");


    // �ܾ� �Է�
    // 1. �ܾ� �� �Է�
    printf("����, �� ������ �ܾ���� �˷��ּ���\n");
    printf("�ܾ��� ������ 3���� �־��. 1���� �ܾ�� �� �� �ΰ���?");
    scanf("%d", &n1);
    printf("2������ �� �� �ΰ���? ");
    scanf("%d", &n2);
    printf("3������ �� �� �ΰ���? ");
    scanf("%d", &n3);
    // 2. ������ �ܾ� �Է�
    scanword_1(n1, ko_1, en_1);
    printf("\n");
    scanword_2(n2, ko_2, en_2);
    printf("\n");
    scanword_3(n3, ko_3, en_3);
    printf("\n");


    // �ܾ� ���� ����
    char ans_1[100][100], ans_2[100][100], ans_3[100][100];
    int score = 0;

    if (quize_1(n1, score, ko_1, en_1, ans_1))
    {
        // 1�ܰ踦 ����ߴٸ� 2�ܰ� ����
        if (quize_2(n2, score, ko_2, en_2, ans_2))
        {
            //  2�ܰ踦 ����ߴٸ� 3�ܰ� ����
            if (quize_3(n3, score, ko_3, en_3, ans_3))
            {
                // ���ϸ�Ʈ
                printf("\n\n");
                printf(" *         *         *         *\n");
                printf("***       ***       ***       ***\n");
                printf("****     *****     *****     ****\n");
                printf("*****   *******   *******   *****\n");
                printf("****** ********* ********* ******\n");
                printf("*********************************\n");
                printf("*********************************\n");
            }
        }
    }


    return 0;
}


void scanword_1(int n1, char ko_1[100][100], char en_1[100][100])
{
    printf("���ƿ�, 1�ܰ���� �Է��� ���ּ���\n");
    for (int i = 0; i < n1; i++)
    {
        printf("�ѱ� : ");
        scanf("%s", ko_1[i]);
        printf("���� : ");
        scanf("%s", en_1[i]);
    }
}
void scanword_2(int n2, char ko_2[100][100], char en_2[100][100])
{
    printf("�������� 2�ܰ�\n");
    for (int i = 0; i < n2; i++)
    {
        printf("�ѱ� : ");
        scanf("%s", ko_2[i]);
        printf("���� : ");
        scanf("%s", en_2[i]);
    }
}
void scanword_3(int n3, char ko_3[100][100], char en_3[100][100])
{
    printf("������ 3�ܰ�!\n");
    for (int i = 0; i < n3; i++)
    {
        printf("�ѱ� : ");
        scanf("%s", ko_3[i]);
        printf("���� : ");
        scanf("%s", en_3[i]);
    }
}



int quize_1(int n1, int score, char ko_1[100][100], char en_1[100][100], char ans_1[100][100])
{
    int a[100];
    printf("�׷� 1�ܰ���� ����!\n");
    printf("���� �ܾ��� ���� �������\n");

    rand_1(a, n1);

    for (int i = 0; i < n1; i++) {
        printf("\n���� : 1\n");
        printf("���ھ� : %d\n", score);
        printf("%s : ", ko_1[a[i]]);

        scanf("%s", ans_1[i]);

        if (strcmp(en_1[a[i]], ans_1[i]))
        {
            printf("��!\n\n");
        }
        else {
            printf("����!\n\n");
            score++;
        }

    }
    if (n1 == score)
    {
        printf("1�ܰ踦 ��� ������!\n");
        printf("�׷� ���� ������ ��!\n");
        return 1;
    }
    else {
        printf("�ƽ��׿�, ������ �ٽ� ����!");
        return 0;
    }
}

int quize_2(int n2, int score, char ko_2[100][100], char en_2[100][100], char ans_2[100][100])
{
    int a[100];
    score = 0;
    printf("���� 2�ܰ�!\n");
    printf("�� �� ������ ȭ����~\n");

    rand_2(a, n2);

    for (int i = 0; i < n2; i++) {
        printf("\n���� : 2\n");
        printf("���ھ� : %d\n", score);
        printf("%s : ", ko_2[a[i]]);

        scanf("%s", ans_2[i]);

        if (strcmp(en_2[a[i]], ans_2[i]))
        {
            printf("��!\n");
        }
        else {
            printf("����!\n");
            score++;
        }

    }
    if (n2 == score)
    {
        printf("2�ܰ踦 ��� ������!\n");
        printf("�׷� ���� ������ ��!\n");
        return 1;
    }
    else {
        printf("�ƽ��׿�, ������ �ٽ� ����!");
        return 0;
    }
}
int quize_3(int n3, int score, char ko_3[100][100], char en_3[100][100], char ans_3[100][100])
{
    int a[100];
    score = 0;
    printf("���� 3�ܰ�!!!\n");
    printf("������ �ھ��̿���, ȭ����~\n");

    rand_3(a, n3);

    for (int i = 0; i < n3; i++) {
        printf("\n���� : 3\n");
        printf("���ھ� : %d\n", score);
        printf("%s : ", ko_3[a[i]]);

        scanf("%s", ans_3[i]);

        if (strcmp(en_3[a[i]], ans_3[i]))
        {
            printf("��!\n");
        }
        else {
            printf("����!\n");
            score++;
        }

    }
    if (n3 == score)
    {
        printf("3�ܰ踦 ��� ������!\n");
        printf("���ϵ���� �ܾ� �����Ͱ� �Ǿ����!!\n");
        return 1;
    }
    else {
        printf("�ƽ��׿�, ������ �ٽ� ����!");
        return 0;
    }
}


void rand_1(int a[100], int n1)
{
    srand(time(NULL));

    for (int i = 0; i < n1; i++)
    {
        a[i] = rand() % n1;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}
void rand_2(int a[100], int n2)
{
    srand(time(NULL));

    for (int i = 0; i < n2; i++)
    {
        a[i] = rand() % n2;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}
void rand_3(int a[100], int n3)
{
    srand(time(NULL));

    for (int i = 0; i < n3; i++)
    {
        a[i] = rand() % n3;

        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                i--;
                break;
            }
        }
    }
}