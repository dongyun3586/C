#include<stdio.h>
#include<stdlib.h>  // rand(), srand() 정의
#include<time.h>    // time() 정의

int main() {
	// rand()함수의 랜덤 숫자 생성을 위한 seed값 설정
	srand(time(NULL));

	// 변수 선언
	int n, dan, su, jungdap, response, score = 0;

	// 구구단 문항 희망 개수 입력받기
	printf("구구단 몇 문제? ");
	scanf("%d", &n);

	// 희망 개수만큼 구구단 문항 반복 출력
	for (int i = 1; i <= n; i++) {
		// 랜덤 숫자 생성
		dan = rand() % 8 + 2;		// 0~7을 2~9로 변경
		su = rand() % 9 + 1;		// 0~8을 1~9로 변경 
		jungdap = dan * n;

		// 구구단 문제 출력
		printf("%d * %d = ", dan, su);

		// 사용자 입력
		scanf("%d", &response);

		// 정답 체크
		if (response == jungdap) {
			printf("정답입니다.\n\n");
			score++;
		}
		else
			printf("틀렸습니다. 정답은 %d 입니다.\n\n", jungdap);
	}

	// 결과 출력
	printf("\n%d 개 중 %d 문제 맞았습니다.\n", n, score);

	return 0;
}