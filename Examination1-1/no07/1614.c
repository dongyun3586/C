#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h1, m1, h2, m2, a, b;

	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	if (h1 <= h2 && m1 <= m2) {
		a = h2 - h1;
		b = m2 - m1;
	}
	else if (h1<h2 && m1>m2) {
		a = h2 - h1 - 1;
		b = 60 - m1 + m2;
	}
	else if (h1 > h2 && m1 < m2) {
		a = 23 - h1 + h2;
	}
	printf("%d시간 %d분 ", a, b);

	return 0;
}