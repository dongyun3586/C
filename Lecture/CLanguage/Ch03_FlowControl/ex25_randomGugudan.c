#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int dan, d, jungdap, userdap, score = 0, n;

	printf("구구단 몇 문제? ");
	scanf("%d", &n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		dan = rand() % 8 + 2;
		d = rand() % 8 + 1;
		jungdap = dan * d;

		printf("%d * %d = ", dan, d);
		scanf("%d", &userdap);

		if (userdap == jungdap) {
			printf("정답입니다. \n");
			score++;
		}
		else
			printf("틀렸습니다. 정답은 %d 입니다. \n", jungdap);
	}

	printf("%d 개 중 %d 문제 맞았습니다. \n", n, score);
	return 0;
}