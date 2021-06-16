#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int priceofsamsung(int k); //샘숭전자의 주식 값과 변동
int priceoftesla(int l); //데술라의 주식 값과 변동
int priceofapple(int m); //앱뽈의 주식 값과 변동
int priceofgamestop(int n); //멈춰라게임의 주식 값과 변동
int maesudo(int k, int i, int buy[], int don); //주식의 매도와 매수
void printjusik(int i, int k, int n); //주식의 구매 현황, 주식 별 현재 가격 출력

int main_000() {
    long long int k = 10000, l = 15000, m = 20000, n = 5000, don = 300000;
    int buy[5] = { 0 }, yes;

    printf("\n\n\n\n\n\n\n          ================================================================\n");
    printf("          ==================== 주 식 은   인 생 이 다 ====================\n");
    printf("          ================================================================\n\n\n\n\n\n\n\n");
    printf("                         $$$  press '777' to start  $$$                        \n\n\n\n\n\n\n");
    scanf("%d", &yes);
    printf("\n\n\n\n\n\n");

    if (yes == 777) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '돈의 세계에 오신 것을 환영합니다' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '혼란스러운 세상과 더불어 흔들거리는 주식시장을 통해 인생을 배워보실 수 있으실 겁니다'\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '여기 네 주식 품목이 있습니다' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n <샘숭전자> <데술라> <앱뽈> <멈춰라게임> \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '오르내리는 이들의 가격과 맞춰 오르내리는 당신의 심박수도 함께 하시길...' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '30일간의 주식시장, 큰 돈을 벌고 싶지 않으십니까?' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '그렇다면, 행운을 빕니다....' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(2000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n '빚을 지지 않도록 조심하십시오....공매도 시스템은 아직 불가합니다....\n 20일의 현금의 양으로 당신의 신용등급이 정해질 것입니다....' \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(5000);

        printf("          5월 1일 KOSDAQU 시세\n\n");
        printf("        1. <샘숭전자>  10000원 -\n");
        printf("        2.  <데술라>   15000원 -\n");
        printf("        3.   <앱뽈>    20000원 -\n");
        printf("        4.<멈춰라게임>  5000원 -\n");
        for (int i = 2; i <= 20; i++) {
            printf("\n\n\n\n\n\n매수 혹은 매도할 주식 수를 입력하세요.\n");
            don = maesudo(k, 1, buy, don);
            don = maesudo(l, 2, buy, don);
            don = maesudo(m, 3, buy, don);
            don = maesudo(n, 4, buy, don);
            printf("\n\n\n          5월 %d일 KOSDAQU 시세\n\n", i);
            k = priceofsamsung(k);
            l = priceoftesla(l);
            m = priceofapple(m);
            n = priceofgamestop(n);
            printf("\n\n\n\n");

            printjusik(1, k, buy[1]);
            printjusik(2, l, buy[2]);
            printjusik(3, m, buy[3]);
            printjusik(4, n, buy[4]);

            if (don < 0)
                break;
        }
        if (don >= 500000)
            printf("\n\n\n\n\n당신의 신용 등급은 1.\n투자에 재능이 있으신데요?\n\n\n");
        else if (don >= 300000 && don < 500000)
            printf("\n\n\n\n\n당신의 신용 등급은 2.\n조금만 더 공부하시면 더 큰 돈을 버실 수 있으실 것 같군요.\n\n\n");
        else if (don < 300000 && don >= 200000)
            printf("\n\n\n\n\n당신의 신용 등급은 3.\n본전도 못 찾으셨군요...\n\n\n");
        else if (don < 200000)
            printf("\n\n\n\n\n당신의 신용 등급은 4.\n당신, 주식은 금지입니다.\n\n\n");
    }


    else
        printf("일확천금의 기회는 다음에 얻으시길.......\n\n");

    return 0;

}

int priceofsamsung(int k) {
    int a;
    srand(time(NULL));
    a = rand() % 41 - 20;
    k = k * (100 + a) / 100;
    printf("       1. <샘숭전자>  %6d\ ", k);
    if (a > 10)
        printf("▲\n");
    else if (a > 0 && a <= 10)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -10 && a < 0)
        printf("v\n");
    else
        printf("▽\n");
    return k;
}

int priceoftesla(int l) {
    int a;
    srand(time(NULL));
    a = rand() % 61 - 30;
    l = l * (100 + a) / 100;
    printf("        2. <데술라>  %6d\ ", l);
    if (a >= 15)
        printf("▲▲\n");
    else if (a > 5 && a < 15)
        printf("▲\n");
    else if (a > 0 && a <= 5)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -5 && a < 0)
        printf("v\n");
    else if (a < -5 && a > -15)
        printf("▽\n");
    else
        printf("▽▽\n");
    return l;
}

int priceofapple(int m) {
    int a;
    srand(time(NULL));
    a = rand() % 41 - 20;
    m = m * (100 + a) / 100;
    printf("         3. <앱뽈>  %6d\ ", m);
    if (a > 10)
        printf("▲\n");
    else if (a > 0 && a <= 10)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -10 && a < 0)
        printf("v\n");
    else
        printf("▽\n");
    return m;
}

int priceofgamestop(int n) {
    int a;
    srand(time(NULL));
    a = rand() % 81 - 40;
    n = n * (100 + a) / 100;
    printf("       4.<멈춰라게임> %6d\ ", n);
    if (a >= 15)
        printf("▲▲\n");
    else if (a > 5 && a < 15)
        printf("▲\n");
    else if (a > 0 && a <= 5)
        printf("^\n");
    else if (a == 0)
        printf("-\n");
    else if (a >= -5 && a < 0)
        printf("v\n");
    else if (a < -5 && a > -15)
        printf("▽\n");
    else
        printf("▽▽\n");
    return n;
}

int maesudo(int k, int i, int buy[], int don) {
    printf("\n현재 사용가능금액 : %d\n ", don);
    int a;
    switch (i) {
    case 1:
        printf("샘숭전자 ");
        break;
    case 2:
        printf("데술라 ");
        break;
    case 3:
        printf("앱뿔 ");
        break;
    case 4:
        printf("멈춰라게임 ");
    }
    printf("\n매수(매도는 -값 입력): ");
    scanf("%d", &a);
    buy[i] += a;
    don -= k * a;

    return don;
}

void printjusik(int i, int k, int n) {
    switch (i) {
    case 1:
        printf("\n샘숭전자 ");
        break;
    case 2:
        printf("데술라 ");
        break;
    case 3:
        printf("앱뿔 ");
        break;
    case 4:
        printf("멈춰라게임 ");
    }
    printf(":  %d주, 총 %d원\n", n, n * k);
}