#include<stdio.h>
#include<stdlib.h>  // rand(), srand() 정의
#include<time.h>    // time() 정의

int main() {
    // 변수 선언
    int n, dan, su, jungdap, score = 0, userdap;

    // 필요한 값 입력받기
    printf("몇 문제? ");
    scanf("%d", &n);

    // 처리
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        // 랜덤 문제 생성
        dan = rand() % 18 + 2;  // 2~19
        su = rand() % 19 + 1;   // 1~19
        jungdap = dan * su;

        // 문제 출력 및 사용자 입력 받기
        printf("%2d * %2d = ", dan, su);
        scanf("%d", &userdap);

        // 정답 체크
        if (jungdap == userdap) {
            printf("정답입니다. \n");
            score++;
        }
        else
            printf("틀렸습니다. 정답은 %d\n", jungdap);
    }

    // 결과 출력
    printf("%d개 중 %d 문제 맞았습니다.\n", n, score);

    return 0;
}