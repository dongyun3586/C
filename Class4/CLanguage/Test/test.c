#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	// 변수 생성
	int dan, i, jungdap, userdap, n, count = 0;

	// 입력값 받기
	printf("구구단 몇 개? ");
	scanf("%d", &n);


	// 처리
	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		// 문제 랜덤 생성
		dan = rand() % 8 + 2; // 2~9
		i = rand() % 9 + 1;	// 1~9
		jungdap = dan * i;

		// 출제
		printf("%d * %d = ", dan, i);
		scanf("%d", &userdap);

		// 정답 비교
		if (jungdap == userdap) {
			printf("맞았습니다. \n");
			count++;
		}
		else
			printf("틀렸습니다. 정답은 %d 입니다. \n", jungdap);
	}

	// 결과 출력
	printf("%d문제 중 %d 문제 맞음.\n", n, count);


	return 0;
}