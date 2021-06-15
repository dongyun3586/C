#include <stdio.h>
#include <time.h>                               // time() 정의
#include <stdlib.h>                             // rand(), srand() 정의
#include <math.h>                               // double pow(double base, double exponent);

void start(void);                               // 조건 입력
void problem(int a, int b, int n, int m);          // 문제 출력, 입력, 결과 출력

int main() {
    printf("*** 암산 연습 프로그램입니다 ***\n");
    printf("*** 숫자만 입력하세요 ***\n");

    //조건 입력 함수로 이동
    start();
    return 0;
}

void start(void) {
    int a, b, n, m;
    printf("\n");
    printf("1. 덧셈\n");
    printf("2. 곱셈\n");
    printf("3. 뺄셈\n");
    printf("4. 나눗셈(몫)\n");
    printf("5. 종료하기\n\n");

    printf("다음 중에서 선택하세요 : ");
    scanf("%d", &m);

    //m이 범위를 만족할 때까지 반복
    while (m < 1 || m>5) {
        printf("다시 입력하세요 : ");
        scanf("%d", &m);
    }

    //m이 5일 경우 함수 종료
    if (m == 5)
        return;

    printf("자리수 두개를 입력하세요(1~5) : ");
    scanf("%d %d", &a, &b);

    //a,b가 범위를 만족할 때까지 반복
    while (a < 1 || a>5 || a < 1 || b>5) {
        printf("다시 입력하세요 : ");
        scanf("%d %d", &a, &b);
    }

    printf("문제 개수를 입력하세요(1~50) : ");
    scanf("%d", &n);

    //n이 범위를 만족할 때까지 반복
    while (n < 1 || n>50) {
        printf("다시 입력하세요 : ");
        scanf("%d", &n);
    }

    //실행 함수로 이동
    problem(a, b, n, m);
}

void problem(int a, int b, int n, int m) {
    int ans, cnt = 0, cnt1 = 0, flag[100] = { 0 }, x, y, temp, cmd, enter;
    long int t, t0;

    printf("시작하려면 enter키를 누르세요.");

    //getchar()로 enter키 입력
    //위 scanf()에서 enter키를 이미 입력했기 때문에 한번 더 입력받는다
    getchar();
    enter = getchar();

    //enter키를 눌렀을 때 실행
    if (enter == '\n') {
        printf("\n");
        srand((unsigned int)time(NULL));

        //시작 전과 후 시간을 입력받는다
        t0 = time(NULL);

        //n만큼 문제 출력
        for (int i = 0; i < n; i++) {
            //임의의 x,y 생성(a 자리수, b 자리수)
            x = rand() % (int)(pow(10, a) - pow(10, a - 1)) + pow(10, a - 1);
            y = rand() % (int)(pow(10, b) - pow(10, b - 1)) + pow(10, b - 1);

            //x가 y보다 작을 경우 자리 바꿈
            if (x < y) {
                temp = x;
                x = y;
                y = temp;
            }
            switch (m) {
            case 1: printf("%d. %d + %d = ", i + 1, x, y);
                scanf("%d", &ans);
                //입력받은 값이 정답이 아닐 경우 배열에 저장,cnt++
                if (ans != x + y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 2: printf("%d. %d * %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x * y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 3: printf("%d. %d - %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x - y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            case 4: printf("%d. %d / %d = ", i + 1, x, y);
                scanf("%d", &ans);
                if (ans != x / y) {
                    flag[i] = 1;
                    cnt++;
                }
                printf("\n"); break;
            }
        }
        t = time(NULL);

        printf("맞은 문제 수 : %d개\n", n - cnt);
        printf("정답률 : %.2f%%\n", ((float)(n - cnt) / n) * 100);
        printf("틀린 문제 : ");

        //틀린 문제일 때 출력
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                printf("%d번 ", i + 1);
                cnt1++;
            }
        }

        //틀린 문제가 없을 경우
        if (!cnt1)
            printf("없음");

        printf("\n걸린 시간 : %ld초\n\n", t - t0);
        printf("1. 다시하기\n");
        printf("2. 처음으로\n");
        printf("3. 종료하기\n\n");
        printf("다음 중에서 선택하세요 : ");
        scanf("%d", &cmd);

        //범위를 만족할 때까지 반복
        while (cmd < 1 || cmd>3) {
            printf("다시 입력하세요 : ");
            scanf("%d", &cmd);
        }
        switch (cmd) {
        case 1: problem(a, b, n, m); break;      //문제 다시 출제
        case 2: start(); break;                  //조건 다시 입력
        case 3: break;                          //종료
        }
    }
}
