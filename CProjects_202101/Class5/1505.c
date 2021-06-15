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

    int sum = 0;                //번갈아 가며 더한 수의 합계
    int p;                      //플레이어 수
    printf("플레이어 수를 입력하세요 : ");
    scanf("%d", &p);
    printf("\n");
    int k = rand() % p + 1;     //무작위 순서 생성 및 게임 과정에서 더하는 순서를 돕는 매개변수
    int a = rand() % 91 + 10;   //무작위로 탈락 숫자 생성
    int s = rand() % 3 + 3;     //번갈아 가며 더하는 수의 범위 생성

    printf("규칙 : ");
    printf("플레이어는 차례대로 특정 범위까지 숫자를 선택하고 그 숫자는 계속 더해진다.\n");
    printf("더해진 숫자가 탈락 숫자 이상이 되면 탈락 숫자를 넘게 한 사람이 패배한다.\n");
    printf("또, 번갈아 가며 더하는 수의 범위를 넘어가는 숫자를 더하면 반칙패로 패배한다.\n\n\n");
    printf("탈락 숫자를 무작위로 생성합니다.\n");
    printf("탈락 숫자 : %d\n\n\n", a);
    printf("번갈아 가며 더하는 수의 범위를 무작위로 생성합니다.\n");
    printf("번갈아 가며 더하는 수의 범위 : 1~%d\n\n\n", s);
    printf("게임 시작\n\n");

    if (p == 2) //플레이하는 사람이 2명일때
    {
        process1(k);
        process2(k, a, s);
    }
    else //플레이하는 사람이 3명 이상일때
    {
        process3(k, p);
        process4(k, a, p, s);
    }

    printf("게임 종료");

    return 0;
}

void process1(int k)
{
    srand(time(NULL));
    printf("순서 정하기\n");
    //순서 출력 부분
    if (k == 1)
        printf("player 1 선공\n");
    else
        printf("player 2 선공\n");

    return 0;
}

void process2(int k, int a, int s)
{
    int x;          //번갈아가면서 더하는 숫자
    int sum = 0;    //더하는 숫자의 총합

    while (1)
    {
        printf("player %d이 추가 숫자 입력 : ", k);    //player k부터 게임 시작
        scanf("%d", &x);                               //추가 숫자 입력
        printf("\n");
        sum = sum + x;
        printf("합계 : %2d\n", sum);
        //더한 값이 탈락 숫자 이상이 될 때
        if (sum >= a)
        {
            printf("탈락 숫자에 도달했습니다\n");
            printf("player %d 패배\n", k);
            break;
        }
        //더하고자 하는 값이 범위를 초과했을때(반칙)
        if (x > s)
        {
            printf("범위를 초과했습니다\n");
            printf("player %d 반칙패\n", k);

            break;
        }
        //번갈아가며 더하기(더한 뒤 순서 바꾸기)
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
    printf("순서 정하기\n");
    printf("player %d 선공\n", k);
    printf("순서 : ");

    //순서 출력 부분(특정한 방향으로 지정)
    for (int i = k; i <= p; i++)
    {
        printf("%d, ", i);
    }
    for (int i = 1; i < k; i++)
    {
        printf("%d, ", i);
    }

    printf("%d 순으로 진행\n\n\n", k);
}

void process4(int k, int a, int p, int s)
{
    int x, sum = 0;

    while (1)
    {
        printf("player %d이 추가 숫자 입력 : ", k);
        scanf("%d", &x);
        printf("\n");
        sum = sum + x;
        printf("합계 : %d\n", sum);
        //더한 값이 탈락 숫자 이상이 될 때
        if (sum >= a)
        {
            printf("탈락 숫자에 도달했습니다\n");
            printf("player %d 패배\n\n\n", k);
            break;
        }
        //더하고자 하는 값이 범위를 초과했을때(반칙)
        if (x > s)
        {
            printf("범위를 초과했습니다\n");

            printf("player %d 반칙패\n\n\n", k);
            break;
        }
        //순서 바꾸기
        k = k + 1;
        //마지막 플레이어에서 플레이어 1로 다시 갈 때
        if (k > p)
        {
            k = k - p;
        }
    }
}