#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, e;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	e = 60 * a - 60 * c + b - d;
	printf("%d 시간 %d 분 ", e / 60, e % 60);


	return 0;
}