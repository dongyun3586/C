#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum gun { scissors = 1, rock, paper };
void game();        //전체적인 게임 함수
int bet();         //베팅 금액 지정 함수
void appoint();     //시작 금액, 목표 금액 지정 함수
void select();      //쌍권총 선택 함수

int a;      //시작 금액
int b;      //목표 금액
int p = 1;      //게임 횟수
int choice1, choice2;   //쌍권총

int main()
{
    //시작 금액과 목표 금액 지정
    appoint();
    //게임 플레이
    game();
}

void select() {
    printf("선택 : 가위-1, 바위-2, 보-3\n");
    scanf("%d %d", &choice1, &choice2);
    printf("\n");
    if ((choice1 != 1 && choice1 != 2 && choice1 != 3) || (choice2 != 1 && choice2 != 2 && choice2 != 3))
    {
        printf("다시 입력해 주세요\n\n");
        select();
    }
    return choice1, choice2;
}

void appoint() {
    printf("시작 금액 : ");
    scanf("%d", &a);
    printf("목표 금액 : ");
    scanf("%d", &b);

    if (2 * a > b || b > 10 * a)
    {
        printf("목표 금액을 시작 금액의 2배~10배 사이로 설정해 주세요.\n\n");
        appoint();
    }
    return 0;
}

int bet() {
    int n;      //베팅 금액
    printf("보유금액 : %d\n", a);
    printf("베팅 금액 : ");
    scanf("%d", &n);
    if (n > a)
    {
        printf("베팅 금액이 보유 금액을 넘어가면 안됩니다.\n\n");
        n = bet();
    }
    return n;
}

void game() {
    char* rsp[3] = { "가위", "바위", "보" };
    srand((unsigned int)time(NULL));
    int c, n;

    //쌍권총(나)
    printf("\n쌍권총\n");
    select();

    //쌍권총(컴퓨터)
    int z = rand() % 3;
    int w = rand() % 3;

    //결과 표시
    printf("나 : %s %s\n", rsp[choice1 - 1], rsp[choice2 - 1]);
    printf("컴퓨터 : %s %s\n", rsp[z], rsp[w]);

    //베팅
    n = bet();

    //하나 빼기 일 (나)
    printf("하나 빼기 일\n");
    printf("%s %s 중에서 선택, %s-%d, %s-%d\n", rsp[choice1 - 1], rsp[choice2 - 1], rsp[choice1 - 1], choice1, rsp[choice2 - 1], choice2);
    scanf("%d", &c);

    //하나 빼기 일 (컴퓨터)
    printf("\n나 : %s\n", rsp[c - 1]);
    int k;
    int s;
    k = rand() % 2 + 1;
    if (k == 1)
    {
        printf("컴퓨터 : %s\n", rsp[z]);
        s = z + 1;
    }
    else
    {
        printf("컴퓨터 : %s\n", rsp[w]);
        s = w + 1;
    }

    //결과 표시 및 돈 정산
    if (c > s || (c == 1 && s == 3))
    {
        printf("승리!\n");
        a = a + n;
        printf("현재 나의 돈: %d\n", a);
    }
    else if (c == s)
    {
        printf("무승부\n");
        a = a;
        printf("현재 나의 돈: %d\n", a);
    }
    else
    {
        printf("패배\n");
        a = a - n;
        printf("현재 나의 돈: %d\n", a);
    }

    if (a <= 0) {
        printf("game over: 파산했습니다.\n");
        return;
    }
    else if (a >= b) {
        printf("목표에 도달했습니다!\n");
        return;
    }
    else
    {
        int input;
        printf("계속하시겠습니까?(네-1,아니요-0)");
        scanf("%d", &input);
        if (input == 1)
        {
            p++;
            if (p >= 10)
            {
                printf("게임 횟수를 초과하였습니다\n");
                printf("game over");
                return;
            }
            game();
        }
    }
}