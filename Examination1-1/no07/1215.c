#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int timen, minn, timea, mina, timer, minr;

	printf("현재 시간: ");
	scanf("%d %d", &timen, &minn);
	printf("알람 시간: ");
	scanf("%d %d", &timea, &mina);

	timer = (timea + 24 - timen) % 24;
	minr = mina - minn;

	if (minr < 0)
		minr += 60;
	timer -= 1;

	printf("%d시간 %d분 ", timer, minr);

	return 0;
}