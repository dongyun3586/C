#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a1, b1, a2, b2, num1, num2, finalnum;

	printf("현재 시간: ");
	scanf("%d %d", &a1, &b1);
	printf("알람 시간: ");
	scanf("%d %d", &a2, &b2);

	num1 = 60 * a1 + b1;
	num2 = 60 * a2 + b2;

	if (num1 > num2)
		num2 += 1440;
	finalnum = num2 - num1;

	printf("%d시간 %d분 ", finalnum/60, finalnum%60);

	return 0;
}