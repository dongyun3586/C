#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, f;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a <= c) {
		if (b <= d) {
			f = d - b, e = c - a;
			printf("%d시간 %d분 ", e, f);
		}
		else {
			f = d - b + 59, e = c - a - 1;
			printf("%d시간 %d분 ", e, f);
		}
	}
	else {
		if (b <= d) {
			f = d - b, e = c - a+23;
			printf("%d시간 %d분 ", e, f);
		}
		else {
			f = d - b + 59, e = c - a +22;
			printf("%d시간 %d분 ", e, f);
		}
	}
	

	return 0;
}