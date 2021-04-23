#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, h, m;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	h = { (24 + c - a) * 60 + d - b } / 60;
	m = { (24 + c - a) * 60 + d - b } % 60;
	printf("%d시간 %d분 ", h, m);

	return 0;
}