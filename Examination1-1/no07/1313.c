#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, f;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (d >= b)
		f = d - b;
	else {
		f = d - b + 60;
		c--;
	}
	if (c >= a)
		e = c - a;
	else
		e = c - a + 24;
	printf("%d시간 %d분 ", e, f);

	return 0;
}