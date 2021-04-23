#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if(c-a<0&&d-b<0)
		printf("%d시간 %d분 ", c-a+23, d-b+60);
	if (c - a < 0 && d - b > 0)
		printf("%d시간 %d분 ", c - a + 24, d - b);
	if (c - a > 0 && d - b < 0)
		printf("%d시간 %d분 ", c - a -1, d - b + 60);
	if (c - a > 0 && d - b > 0)
		printf("%d시간 %d분 ", c - a, d - b);

	return 0;
}