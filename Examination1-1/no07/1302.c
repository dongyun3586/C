#include<stdio.h>

/* 알람 시간 출력 1301 곽나영 */
int main() {
	int c1, c2, a1, a2, ct, at, rt;

	printf("현재 시간: ");
	scanf("%d %d", &c1, &c2);
	printf("알람 시간: ");
	scanf("%d %d", &a1, &a2);

	ct = c1 * 60 + c2;
	at = a1 * 60 + a2;
	rt = (at - ct) % 1440;

	printf("%d시간 %d분 ", rt/60, rt%60);

	return 0;
}