#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h1, h2, m1, m2, hg, mg;

	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	if (h2 > h1)
		hg = h2 - h1;
	else if (h1 > h2)
		hg = 24 + h2 - h1;
	else if (h1 == h2)
		hg = 24;
	if (m2 > m1)
		mg = m2 - m1;
	else if (m1 > m2) {
		mg = 60 + m2 - m1;
		hg--;
	}
	else if (m1 == m2)
		mg = 0;

	printf("%d시간 %d분 ", hg, mg);

	return 0;
}