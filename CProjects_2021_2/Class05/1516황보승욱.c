#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int cardlist[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };           //카드 리스트. 블랙잭에서는 A를 1, J, Q, K를 10으로 취급하기 때문에 저러한 값을 가진다.
int* rnd = cardlist;                                                        //카드를 랜덤으로 선정해야 할 때에는 첫 칸의 주소 + i(랜덤)의 형식으로 선정한다.

typedef struct
{
    char name[20];                                                          //플레이어 이름
    int nowcards[20];                                                       //플레이어가 현재 보유한 카드
    int win;                                                                //플레이어가 이긴 횟수
}player;

typedef struct
{
    int nowcards[20];                                                        //이름이 없다는 점을 제외하면 플레이어와 같은 구성
    int win;
}cp;

void cpai(cp cpu, int first1, int first2)
{
    if (5 + first1 + first2 < 21)                                            //ai에게 나름의 전략 부여. 현재 든 두 카드의 합이 16 이하이면 한 장을 더 뽑는다.
    {
        cpu.nowcards[2] = *rnd + rand() % 13;
        printf("%d %d %d\n", first1, first2, cpu.nowcards[2]);
    }
    else
    {
        printf("%d %d\n", first1, first2);
    }
}

void compare(cp cpu1, cp cpu2, cp cpu3, player user, cp deal)             //비교하는 함수. 보유한 카드들의 합을 가지고, 블랙잭의 룰에 의해 승패 결정
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
        printf("%s : 승리\n", user.name);
    }
    if (sum1 < dealsum && sum1 <= 21 || sum1 <= 21 && dealsum > 21)
    {
        cpu1.win++;
        printf("ai 1 : 승리\n");
    }
    if (sum2 < dealsum && sum2 <= 21 || sum2 <= 21 && dealsum > 21)
    {
        cpu2.win++;
        printf("ai 2 : 승리\n");
    }
    if (sum3 < dealsum && sum3 <= 21 || sum3 <= 21 && dealsum > 21)
    {
        cpu3.win++;
        printf("ai 3 : 승리\n");
    }
}

int main()
{
    int n;
    srand(time(NULL));
    do
    {
        printf("*** 블랙잭 게임 메뉴 ***\n\n");
        printf("1 : 게임 룰 설명 \n2 : 1인 플레이 \n3 : 종료\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("*** 룰 설명 ***\n\n");
            printf("블랙잭은 여러 명이 함께 경쟁하는 카드 게임입니다.\n\n");
            printf("게임을 하는 인원은 딜러 한 명, 그리고 플레이어 네 명입니다.\n\n");
            printf("한 게임은 10개의 라운드로 구성되며, 모든 라운드가 끝난 후 가장 많은 라운드에서 승리한 플레이어가 승자입니다.\n\n");
            printf("플레이어들은 각자 딜러에게서 무작위 카드 두 장을 분배받습니다.\n\n");
            printf("분배받은 카드는 모두에게 공개되며, 플레이어들은 자신의 카드를 보고 다음 행동을 결정할 수 있습니다.\n\n");
            printf("한 번에 한 장씩 원하는 횟수만큼 딜러에게서 카드를 더 받거나, 카드를 받지 않고 이번 라운드의 행동을 마칠 수 있습니다.\n\n");
            printf("그렇게 모든 행동이 끝나고 나면, 딜러는 무작위 카드 두 장을 뽑습니다.\n\n");
            printf("딜러도 플레이어들과 동일한 행동이 가능합니다.\n\n");
            printf("딜러까지 자신의 카드를 결정하면, 계산이 시작됩니다.\n\n");
            printf("목표는 자신의 카드들의 합으로 21보다 크지 않은, 21에 가장 가까운 수를 만드는 것입니다.\n\n");
            printf("A는 1로 계산하며, K, Q, J는 10으로 계산합니다.\n\n");
            printf("각 플레이어들의 비교 대상은 딜러이며, 딜러보다 카드의 합이 더 큰 플레이어는 딜러에게서 승리를 가져옵니다.\n\n");
            printf("딜러보다 카드의 합이 작거나, 카드의 합이 21을 넘은 플레이어들은 해당 라운드에서 패배합니다.\n\n");
            printf("단, 딜러의 카드의 합이 21을 넘을 경우 카드의 합이 21이 넘는 플레이어를 제외한 모든 플레이어가 승자입니다.\n\n");
            printf("이것으로 게임의 설명이 종료되었습니다. 즐거운 게임 되십시오.\n\n\n");
            break;
        case 2:
            printf("게임을 시작하겠습니다.\n");
            player player1 = { 0 };                                                      //플레이어 구조체 생성
            cp ai1 = { 0 }, ai2 = { 0 }, ai3 = { 0 }, dealer = { 0 };                    //cp들(딜러 포함) 구조체 생성
            int* nc1 = player1.nowcards, nc2 = player1.nowcards[1], w = player1.win;
            int* a1nc1 = ai1.nowcards, a1nc2 = ai1.nowcards[1], a1w = ai1.win;
            int* a2nc1 = ai2.nowcards, a2nc2 = ai2.nowcards[1], a2w = ai2.win;
            int* a3nc1 = ai3.nowcards, a3nc2 = ai3.nowcards[1], a3w = ai3.win;
            int* dnc1 = dealer.nowcards, dnc2 = dealer.nowcards[1];
            w = a1w = a2w = a3w = 0;                                                     //승리 횟수 초기화
            printf("플레이어의 이름을 입력하여 주십시오.\n");
            scanf("%s", player1.name);
            for (int i = 1; i < 10; i++)                                                //10라운드(10번) 반복하기
            {
                for (int j = 0; j < 19; j++)                                            //매 라운드마다 nowcrads의 값 초기화
                {
                    *(nc1 + j) = 0;
                    *(a1nc1 + j) = 0;
                    *(a2nc1 + j) = 0;
                    *(a3nc1 + j) = 0;
                    *(dnc1 + j) = 0;
                }
                printf("*** 라운드 %d ***\n", i);
                printf("카드를 뽑겠습니다.\n\n");                                       //플레이어 카드 뽑기
                nc1 = *rnd + rand() % 13;
                nc2 = *rnd + rand() % 13;
                printf("%s의 카드 : %d, %d\n", player1.name, nc1, nc2);
                a1nc1 = *rnd + rand() % 13;                                            //ai들의 카드 뽑기
                a1nc2 = *rnd + rand() % 13;
                a2nc1 = *rnd + rand() % 13;
                a2nc2 = *rnd + rand() % 13;
                a3nc1 = *rnd + rand() % 13;
                a3nc2 = *rnd + rand() % 13;
                printf("ai 1의 카드 : %d, %d\n", a1nc1, a1nc2);
                printf("ai 2의 카드 : %d, %d\n", a2nc1, a2nc2);
                printf("ai 3의 카드 : %d, %d\n", a3nc1, a3nc2);
                int patern, times = 2;
                do
                {
                    printf("어떤 행동을 하시겠습니까?\n");
                    printf("1 : 카드 뽑기\n");
                    printf("2 : 차례 넘기기\n");
                    scanf("%d", &patern);
                    if (patern == 1)
                    {
                        player1.nowcards[times] = *rnd + rand() % 13;
                        printf("%s의 카드 : %d, %d, %d\n", player1.name, nc1, nc2, player1.nowcards[2]);
                        printf("ai 1의 카드 : %d, %d\n", a1nc1, a1nc2);
                        printf("ai 2의 카드 : %d, %d\n", a2nc1, a2nc2);
                        printf("ai 3의 카드 : %d, %d\n", a3nc1, a3nc2);
                    }
                    else if (patern == 2)
                    {
                        break;
                    }
                } while (patern != 2);
                printf("%s의 카드 : %d, %d, %d\n", player1.name, nc1, nc2, player1.nowcards[2]);
                printf("ai 1의 카드 : ");
                cpai(ai1, a1nc1, a1nc2);
                printf("ai 2의 카드 : ");
                cpai(ai2, a2nc1, a2nc2);
                printf("ai 3의 카드 : ");
                cpai(ai3, a3nc1, a3nc2);
                printf("딜러의 차례입니다.\n");
                dnc1 = *rnd + rand() % 13;
                dnc2 = *rnd + rand() % 13;
                printf("딜러의 카드 : ");
                cpai(dealer, dnc1, dnc2);
                printf("계산을 시작하겠습니다.\n");
                compare(ai1, ai2, ai3, player1, dealer);
                printf("\n\n");
            }
            printf("%s : %d회 승리\n", player1.name, w);
            printf("ai 1 : %d회 승리\n", a1w);
            printf("ai 2 : %d회 승리\n", a2w);
            printf("ai 3 : %d회 승리\n", a3w);
        case 3:
            break;
        }
    } while (n != 3);
    return 0;
}