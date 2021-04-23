#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, x, y, h, m;

	printf("현재 시간: ");
	scanf("%2d %2d", &a, &b);
	printf("알람 시간: ");
	scanf("%2d %2d", &x, &y);

	if (b > y) {
		y += 60;
		x--;
		if (a > x)
			x += 24;
	}
	else {
		if (a > x)
			x += 24;
		
	}
	printf("\n");
	m = y - b;
	h = x - a;
	printf("%d시간 %d분 ", h, m);

	return 0;
}