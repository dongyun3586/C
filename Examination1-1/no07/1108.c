#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, f;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (b > d) {
		f = d - b;
		if (a <= c)
			e = c - a;
		else
			e = c + 12 - a;
	}
	else {
		f = d + 60 - b;
		if (a < c)
			e = c - a - 1;
		else
			e = c - a + 11;
	}
	printf("%d시간 %d분 ", e,f);

	return 0;
}