#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (b > d) {			
		y = 60 + d - b;
		x--;
	}
	else 
		y = d - b;
	if (a > c)
		x = x + 24 + c - a;
	else
		x = x + c - a;
	if (x < 0) x += 24;
	printf("%d시간 %d분 ", x, y);

	return 0;
}