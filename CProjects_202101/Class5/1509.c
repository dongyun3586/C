#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multi();//멀티플레이와 싱글플레이의 함수를 나누었다.
void single();

int main(void)
{
    int k;
    while (1) {
        printf("싱글플레이는 1, 멀티플레이는 2를 입력하세요.");
        scanf("%d", &k);
        if (k != 1 && k != 2)//1또는 2가 입력되지 않을떄 다시 입력값을 받는다.
            printf("다시 입력하세요.\n");
        else
            break;
    }
    if (k == 1)
        single();//1을 입력하면 싱글플레이

    else if (k == 2)
        multi();//2를 입력하면 멀티플레이
}
void single() {//싱글함수
    int i, mycnt, comcnt, cnt = 0;
    while (cnt < 31)
    {
        printf("몇개의 숫자를 부르시겠습니까?\n");
        printf("1에서 3사이의 숫자를 입력하세요.\n");
        scanf("%d", &mycnt);
        if (1 <= mycnt && mycnt <= 3)//자신이 부를 수 있는 숫자의 개수는 최대 3개이다.
        {
            printf("당신이 부른 숫자는 : ");

            for (i = 1; i <= mycnt; i++)//1부터 카운트를 시작하여 내가 부른 수까지 1씩 더해감
            {
                ++cnt;//카운트 1 증가후
                printf("%d ", cnt);//카운터 출력

                if (cnt == 31) break;//판단
            }

            if (cnt == 31) //포문 빠져나오자마자 출력후 와일문 탈출 
            {
                printf("당신이 패배하셨습니다.\n"); break;
            }

            else printf("\n");

            srand(time(NULL));//srand seed값 초기화
            comcnt = rand() % 3 + 1;//컴퓨터가 부르는 숫자 개수-3으로 나눈 나머지에 1을 나눈다.

            printf("컴퓨터가 부른 숫자는 : ");

            for (i = 1; i <= comcnt; i++)
            {
                ++cnt;
                printf("%d ", cnt);

                if (cnt == 31) break;//종료조건
            }
            if (cnt == 31)//컴퓨터가 부른 숫자가 31이 될떄
            {
                printf("당신이 승리하셨습니다.\n"); break;
            }

            else printf("\n");

        }
        else
        {
            printf("다시 입력하세요.\n");
        }
    }

    //if((com+i)>=31
  //   printf("당신이 승리하셨습니다.\n");
   // else
   //  printf("당신이 패배하셨습니다.\n");

}

void multi() {
    int now, i, usercnt, cnt = 0;//함수 자체가 바껴서 다시 한번 변수 선언
    srand(time(NULL));
    now = rand() % 2 + 1;//플레이어 둘중 누가 먼저 시작할지 랜덤으로 결정
    printf("\n플레이어 %d가 먼저 시작합니다.\n", now);
    while (1) {
        printf("\n플레이어 %d, 몇개의 숫자를 부르시겠습니까?\n", now);
    re:
        printf("1에서 3사이의 숫자를 입력하세요.\n");
        printf("현재 숫자:%d\n", cnt);
        scanf("%d", &usercnt);
        if (usercnt < 1 || usercnt > 3) {// 유저가 부른 숫자가 1이상 3이하여야 함
            printf("다시 입력하세요.");
            goto re;// 만약 1미만 3초과를 부를시 다시 re로 돌아감
        }
        printf("\n플레이어 %d가 부른 숫자는:", now);
        for (int i = cnt + 1; i <= cnt + usercnt; i++)//현재 숫자의 다음 숫자부터 
            printf("%d ", i);
        cnt += usercnt;//유저가 부른 수를 카운트에 축적
        if (now == 1)
            now = 2;
        else
            now = 1;//순서를 바꿔줌
        if (cnt >= 31)//cnt가 31이 넘을시 게임 종료
            break;
    }
    printf("\n플레이어 %d가 승리하셨습니다.\n", now);
}