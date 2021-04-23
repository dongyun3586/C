#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, h1, m1, h2, m2, h, m;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	h1 = a % 24;
	m1 = b % 59;
	h2 = c % 24;
	m2 = d % 59;
	h = h2 - h1;
	m = m2 - m1;
	if (h < 0) h = h + 24;
	if (m < 0) m += 60;
	printf("%d시간 %d분 ", h, m);

	return 0;
}