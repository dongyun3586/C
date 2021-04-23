#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e, f;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a > c)
		e = c + 24 - a - (d - b) / 60;
	else 
		e = c - a - (d - b) / 60;
	if (b > d)
		f = d + 60 - b;
	else
		f = d - b;
	printf("%d시간 %d분 ", e, f);

	return 0;
}