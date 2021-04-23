#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h, m, a, b, k, l;

	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &a, &b);

	if (a < h)
		k = 24 + a - h;
	else k = h - a;
	if (m > b) {
		k--;
		l = 60 + b - m;
	}
	else l = m - b;

	printf("%d시간 %d분 ", k, l);

	return 0;
}