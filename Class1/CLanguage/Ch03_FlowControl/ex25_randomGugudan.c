#include<stdio.h>
#include<stdlib.h>  // rand(), srand() 정의
#include<time.h>    // time() 정의

int main() {
    // 1. 변수 선언
    int dan, i, jungdap, userdap, score = 0, n;

    // 2. 사용자 입력 받기
    printf("구구단 몇 문제? ");
    scanf("%d", &n);

    // 3. 처리
    srand(time(NULL));
    for (int a = 0; a < n; a++) {
        dan = rand() % 8 + 2;   // 2~9
        i = rand() % 9 + 1;     // 1~9
        jungdap = dan * i;

        printf("%d * %d = ", dan, i);
        scanf("%d", &userdap);

        if (userdap == jungdap) {
            printf("정답입니다. \n");
            score++;
        }
        else
            printf("틀렸습니다. 정답은 %d 입니다.\n", jungdap);
    }

    // 4. 결과 출력
    printf("%d 개 중 %d개 맞았습니다. \n", n, score);

    return 0;
}