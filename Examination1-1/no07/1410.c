#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, t;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (c > a) {
		if (d > b) {
			e = c - a;
			t = d - b;
			printf("%d시간 %d분 ", e, t);
		}
		else if (b > d) {
			e = c - a - 1;
			t = b - d;
			printf("%d시간 %d분 ", e, t);
		}
	}
	else if (a > c) {
		if (d > b) {
			e = 24- a+b;
			t = d - b;
			printf("%d시간 %d분 ", e, t);
		}
		else if (b > d) {
			e = 24- a+b - 1;
			t = b - d;
			printf("%d시간 %d분 ", e, t);
		}
	}
	

	return 0;
}