//중간 결과물
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int board[3][3];
int checkboard[3];
int RSPwinner[3][3] = { 0, 1, 2, 2, 0, 1, 1, 2, 0 };//무승부 0, user승 1 com 승 2, 사람과 컴퓨터의 선땍에 따른 승무패를 저장해 놓은 배열
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
    printf("<좌표 틱택토>\n");
    while (1) {
        printf("press 1 to start the game\npress 2 to check the statistics\npress 3 to end\n");
        scanf("%d", &choice);
        if (choice == 1) {
            while (1)
            {
                Reset_board();
                printf("주의: 틱택토에 입력하는 좌표는 3X3 배열위치 순서와 같습니다.\n");
                int rspresult = RSP();
                if (rspresult == 0)
                    printf("무승부입니다. 다시 가위바위보를 하여 주십시오.\n");
                else if (rspresult == 1)
                {
                    system("cls");
                    printf("사용자가 먼저 착수합니다.\n");
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
                    printf("컴퓨터가 먼저 착수합니다.\n");
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
        else if (choice == 2)//통계 확인
        {
            printf("총 경기수 : %d\n승 : %d\n무: %d\n패 : %d\n", losecount + wincount + drawcount, wincount, drawcount, losecount);
            printf("최근 5게임: ");
            for (int i = 0; i <= 4; i++)
                printf("%c ", Last_5_Games[i]);
            printf("\n");
        }
        else if (choice == 3)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }
    return 0;
}
int CheckGameSet1()
{
    int ans1, ans2, ans3, ans4 = 0;
    for (int i = 0; i <= 2; i++) //가로방향 확인
    {
        for (int j = 0; j <= 2; j++)
            checkboard[j] = board[i][j];
        ans1 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans1 == 1)return ans1;
    }
    for (int i = 0; i <= 2; i++) //세로방향 확인
    {
        for (int j = 0; j <= 2; j++)
            checkboard[j] = board[j][i];
        ans2 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans2 == 1)return ans2;
    }
    for (int i = 0; i <= 2; i++) //대각선방향 확인 
    {
        checkboard[i] = board[i][i];
        ans3 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans3 == 1)return ans3;
    }
    for (int i = 0; i <= 2; i++) //또 다른 대각선 방향 확인
    {
        checkboard[i] = board[i][2 - i];
        ans4 = CheckGameSet2(checkboard[0], checkboard[1], checkboard[2]);
        if (ans4 == 1)return ans4;
    }
    return 0;
}
int CheckGameSet2(int i, int j, int k) //초기 값은 0이므로 두어지지 않은 칸이 일렬일때도 게임이 끝나는 것을 방지
{
    int ans = 0, length = sizeof(Last_5_Games) / sizeof(char);
    if (i == j && j == k) {
        switch (i) {
        case 0: break;
        case 1: printf("사용자의 승리!\n"); ans = 1; wincount++;
            for (int i = length - 2; i >= 0; i--)Last_5_Games[i + 1] = Last_5_Games[i];
            Last_5_Games[0] = 'W'; break;
        case 2: printf("컴퓨터의 승리!\n"); ans = 1; losecount++;
            for (int i = length - 2; i >= 0; i--)Last_5_Games[i + 1] = Last_5_Games[i];
            Last_5_Games[0] = 'L'; break;
        }
    }
    return ans;
}
int UserCheckOverlap(int i, int j) //이미 두어진 자리에 돌을 또 둘수 있지 않게 하려는 부분
{
    if (board[i][j] != 0)
    {
        printf("이미 놓아진 자리입니다! 다시 좌표를 입력하여 주십시오,\n");
        return -1;
    }
    return 0;
}
int ComCheckOverlap(int i, int j)//컴퓨터가 둘 때는 문장을 출력할 필요가 없으므로 작성한 부분, 사실 이러면 함수 작성 의미가 없어지지만 원래 하나의 함수였어서 그대로 두고 새로 만들게 됨
{
    if (board[i][j] != 0)
        return -1;
    return 0;
}
int RSP()//가위바위보 하는 부분
{
    srand(time(NULL));
    int com = rand() % 3; //컴퓨터는 랜덤으로 가위바위보 중 하나 선택
    int user;
    printf("%d : 가위\n%d : 바위\n%d : 보\n", 0, 1, 2);
    scanf("%d", &user); //사람의 선택 입력
    switch (com)//조작된 결과가 아닌지 의심할 수 있기에 확인차 넣은 부분
    {
    case(0):printf("컴퓨터의 선택 : 가위\n"); break;
    case(1):printf("컴퓨터의 선택 : 바위\n"); break;
    case(2):printf("컴퓨터의 선택 : 보\n"); break;
    }
    return RSPwinner[com][user];
}
void ComPlacement()//컴퓨터가 랜덤적으로 두는 부분
{
    srand(time(NULL));
    int k;
    int x, y;
    do {
        x = rand() % 3; y = rand() % 3;
        k = ComCheckOverlap(x, y);
    } while (k == -1);
    board[x][y] = 2;
    printf("컴퓨터의 선택 : %d, %d\n", x, y);
}
void UserPlacement()//사용자의 돌 두기
{
    int k;
    int x, y;
    do {
        printf("좌표를 입력하여 주세요");
        scanf("%d %d", &x, &y);
        k = UserCheckOverlap(x, y);
    } while (k == -1);
    board[x][y] = 1;
}
int Check_Draw()//돌이 9개 다 놓아졌는데 게임이 끝나지 않는 문제를 해결하기 위해 작성된 부분
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
        Last_5_Games[0] = 'D';//최근 5 게임의 배열에 무승무 "D"를 입력하기 위한 코드
        printf("무승부입니다!\n");
    }

    return count;
}
void Reset_board()//매 판 끝날 때 마다 보드를 0으로 리셋할 필요가 있음 
{
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            board[i][j] = 0;
}