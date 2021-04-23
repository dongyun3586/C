#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, p, q;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	p = c - a;
	q = d - b;
	if (p < 0)
		p += 24;
	if (q < 0) {
		q += 60;
		p--;
	}
	printf("%d시간 %d분 ", p, q);

	return 0;
}