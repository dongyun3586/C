#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a > c)
		c += 24;
	if (b > d) {
		c--;
		d += 60;
	}
	printf("%d시간 %d분 ", c-a, d-b);

	return 0;
}