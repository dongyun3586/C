#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int dan, i, jungdap, userdap, n, count=0;

	printf("구구단 몇 개? ");
	scanf("%d", &n);

	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		// 문제 랜덤 생성
		dan = rand() % 8 + 2; // 2~9
		i = rand() % 9 + 1;	// 1~9
		jungdap = dan * i;

		// 출제
		printf("%d * %d = ");
		scanf("%d", &userdap);

		// 정답 비교
		if (jungdap == userdap) {
			printf("맞았습니다. \n");
			count++;
		}
		else
			printf("틀렸습니다. 정답은 %d 입니다. \n", jungdap);
	}



	return 0;
}