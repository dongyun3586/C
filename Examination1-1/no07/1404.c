#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a > c) {
		e = 60 * a + b - 60 * c - d;
		printf("%d시간 %d분 ", (60 * 24 - e) / 60, (60 * 24 - e) % 60);
	}
	else {
		e = 60 * c + d - 60 * a - b;
		printf("%d시간 %d분 ", e / 60, e % 60);
	}

	return 0;
}