#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h1, m1, h2, m2, hc, mc;

	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	if (m1 > m2) {
		h2--;
		m2 += 60;
		if (h1 > h2)
			hc = 24 + h2 - h1;
		else {
			hc = h2 - h1;
		}
	}
	else {
		if (h1 > h2)
			hc = 24 + h2 - h1;
		else
			hc = h2 - h1;
	}
	mc = m2 - m1;
	printf("%d시간 %d분 ", hc, mc);

	return 0;
}