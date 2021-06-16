//�߰� �����
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int board[3][3];
int checkboard[3];
int RSPwinner[3][3] = { 0, 1, 2, 2, 0, 1, 1, 2, 0 };//���º� 0, user�� 1 com �� 2, ����� ��ǻ���� ������ ���� �¹��и� ������ ���� �迭
char Last_5_Games[5];
int CheckGameSet1();
int CheckGameSet2(int i, int j, int k);
int UserCheckOverlap(int i, int j);
int ComCheckOverlap(int i, int j);
int RSP();
int Check_Draw();
void ComPlacement(); void UserPlacement();
void Reset_board();
int wincount = 0, losecount = 0, drawcount = 0;
void main()
{
    int choice, countlose = 0, countwin = 0;
    printf("<��ǥ ƽ����>\n");
    while (1) {
        printf("press 1 to start the game\npress 2 to check the statistics\npress 3 to end\n");
        scanf("%d", &choice);
        if (choice == 1) {
            while (1)
            {
                Reset_board();
                printf("����: ƽ���信 �Է��ϴ� ��ǥ�� 3X3 �迭��ġ ������ �����ϴ�.\n");
                int rspresult = RSP();
                if (rspresult == 0)
                    printf("���º��Դϴ�. �ٽ� ������������ �Ͽ� �ֽʽÿ�.\n");
                else if (rspresult == 1)
                {
                    system("cls");
                    printf("����ڰ� ���� �����մϴ�.\n");
                    do {
                        system("cls");
                        UserPlacement();
                        if (CheckGameSet1() == 1 || Check_Draw() == 9)break;
                        ComPlacement();
                        /*if (CheckGameSet1() == 1 || Check_Draw() == 9)break;*/
                        system("pause");
                    } while (CheckGameSet1() == 0 && Check_Draw() != 9);
                    break;
                }
                else
                {
                    system("cls");
                    printf("��ǻ�Ͱ� ���� �����մϴ�.\n");
                    do {
                        system("cls");
                        ComPlacement();
                        if (CheckGameSet1() == 1 || Check_Draw() == 9)break;
                        UserPlacement();
                        /*if (CheckGameSet1() == 1 || Check_Draw() == 9)break;*/
                        system("pause");

                    } while (CheckGameSet1() == 0 && Check_Draw() != 9);
                    break;
                }
                system("cls");
            }
        }
        else if (choice == 2)//��� Ȯ��
        {
            printf("�� ���� : %d\n�� : %d\n��: %d\n�� : %d\n", losecount + wincount + drawcount, wincount, drawcount, losecount);
            printf("�ֱ� 5����: ");
            for (int i = 0; i <= 4; i++)
                printf("%c ", Last_5_Games[i]);
            printf("\n");
        }
        else if (choice == 3)
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
    }
    return 0;
}
int CheckGameSet1()
{
    int ans1, ans2, ans3, ans4 = 0;
    for (int i = 0; i <= 2; i++) //���ι��� Ȯ��
    {
        for (int j = 0; j <= 2; j++)
            checkboard[j] = board[i][j];
        ans1 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans1 == 1)return ans1;
    }
    for (int i = 0; i <= 2; i++) //���ι��� Ȯ��
    {
        for (int j = 0; j <= 2; j++)
            checkboard[j] = board[j][i];
        ans2 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans2 == 1)return ans2;
    }
    for (int i = 0; i <= 2; i++) //�밢������ Ȯ�� 
    {
        checkboard[i] = board[i][i];
        ans3 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans3 == 1)return ans3;
    }
    for (int i = 0; i <= 2; i++) //�� �ٸ� �밢�� ���� Ȯ��
    {
        checkboard[i] = board[i][2 - i];
        ans4 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans4 == 1)return ans4;
    }
    return 0;
}
int CheckGameSet2(int i, int j, int k) //�ʱ� ���� 0�̹Ƿ� �ξ����� ���� ĭ�� �Ϸ��϶��� ������ ������ ���� ����
{
    int ans = 0, length = sizeof(Last_5_Games) / sizeof(char);
    if (i == j && j == k) {
        switch (i) {
        case 0: break;
        case 1: printf("������� �¸�!\n"); ans = 1; wincount++;
            for (int i = length - 2; i >= 0; i--)Last_5_Games[i + 1] = Last_5_Games[i];
            Last_5_Games[0] = 'W'; break;
        case 2: printf("��ǻ���� �¸�!\n"); ans = 1; losecount++;
            for (int i = length - 2; i >= 0; i--)Last_5_Games[i + 1] = Last_5_Games[i];
            Last_5_Games[0] = 'L'; break;
        }
    }
    return ans;
}
int UserCheckOverlap(int i, int j) //�̹� �ξ��� �ڸ��� ���� �� �Ѽ� ���� �ʰ� �Ϸ��� �κ�
{
    if (board[i][j] != 0)
    {
        printf("�̹� ������ �ڸ��Դϴ�! �ٽ� ��ǥ�� �Է��Ͽ� �ֽʽÿ�,\n");
        return -1;
    }
    return 0;
}
int ComCheckOverlap(int i, int j)//��ǻ�Ͱ� �� ���� ������ ����� �ʿ䰡 �����Ƿ� �ۼ��� �κ�, ��� �̷��� �Լ� �ۼ� �ǹ̰� ���������� ���� �ϳ��� �Լ���� �״�� �ΰ� ���� ����� ��
{
    if (board[i][j] != 0)
        return -1;
    return 0;
}
int RSP()//���������� �ϴ� �κ�
{
    srand(time(NULL));
    int com = rand() % 3; //��ǻ�ʹ� �������� ���������� �� �ϳ� ����
    int user;
    printf("%d : ����\n%d : ����\n%d : ��\n", 0, 1, 2);
    scanf("%d", &user); //����� ���� �Է�
    switch (com)//���۵� ����� �ƴ��� �ǽ��� �� �ֱ⿡ Ȯ���� ���� �κ�
    {
    case(0):printf("��ǻ���� ���� : ����\n"); break;
    case(1):printf("��ǻ���� ���� : ����\n"); break;
    case(2):printf("��ǻ���� ���� : ��\n"); break;
    }
    return RSPwinner[com][user];
}
void ComPlacement()//��ǻ�Ͱ� ���������� �δ� �κ�
{
    srand(time(NULL));
    int k;
    int x, y;
    do {
        x = rand() % 3; y = rand() % 3;
        k = ComCheckOverlap(x, y);
    } while (k == -1);
    board[x][y] = 2;
    printf("��ǻ���� ���� : %d, %d\n", x, y);
}
void UserPlacement()//������� �� �α�
{
    int k;
    int x, y;
    do {
        printf("��ǥ�� �Է��Ͽ� �ּ���");
        scanf("%d %d", &x, &y);
        k = UserCheckOverlap(x, y);
    } while (k == -1);
    board[x][y] = 1;
}
int Check_Draw()//���� 9�� �� �������µ� ������ ������ �ʴ� ������ �ذ��ϱ� ���� �ۼ��� �κ�
{
    int length = sizeof(Last_5_Games) / sizeof(char);
    int count = 0;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
        {
            if (board[i][j] != 0)
                count++;
        }
    if (count == 9)
    {
        drawcount++;
        for (int i = length - 2; i >= 0; i--)
            Last_5_Games[i + 1] = Last_5_Games[i];
        Last_5_Games[0] = 'D';//�ֱ� 5 ������ �迭�� ���¹� "D"�� �Է��ϱ� ���� �ڵ�
        printf("���º��Դϴ�!\n");
    }

    return count;
}
void Reset_board()//�� �� ���� �� ���� ���带 0���� ������ �ʿ䰡 ���� 
{
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            board[i][j] = 0;
}