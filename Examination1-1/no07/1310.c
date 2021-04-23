#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, f;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (c - a < 0) {
		if (d - b < 0) {
			e = 23 + c - a;
			f = 60 + d - b;
		}
		else {
			e = 24 + c - a;
			f = d - b;
		}
	}
	else {
		if (d - b < 0) {
			e = c - a - 1;
			f = 60 + d - b;
		}
		else {
			e = c - a;
			f = d - b;
		}
	}
	printf("%d시간 %d분 ", e, f);

	return 0;
}