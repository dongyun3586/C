#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	// 변수 선언
	int dan, i, jungdap, userdap, score = 0, n;

	// 사용자 입력 받기
	printf("몇 문제? ");
	scanf("%d", &n);

	// 처리
	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		dan = rand() % 8 + 2;	// 2~9
		i = rand() % 9 + 1;		// 1~9
		jungdap = dan * i;

		printf("%d * %d = ", dan, i);
		scanf("%d", &userdap);

		if (userdap == jungdap) {
			printf("정답입니다. \n");
			score++;
		}
		else
			printf("틀렸어요. 정답은 %d 입니다. \n", jungdap);
	}

	// 최종 결과 출력
	printf("%d 문제 중 %d 개 맞음\n", n, score);

	return 0;
}
