#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, k, l;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a >= c) {
		if (b > d) {
			k = 23 - a + c;
			l = 60 - b - d;
		}
		else {
			k = 24 - a + c;
			l = d - b;
		}
	}
	else {
		if (b > d) {
			k = c - a - 1;
			l = 60 - b + d;
		}
		else {
			k = c - a;
			l = d - b;
		}
	}

	printf("%d시간 %d분 ", k, l);

	return 0;
}