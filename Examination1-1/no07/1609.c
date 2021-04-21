#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, x, y;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (b >= d) {
		c = c - 1;
		x = b - d;
		if (a >= c)
			y = c + 24 - a;
		else
			y = a - c;		// y = c - a; 감점
	}
	else {
		x = d - b;
		if (a >= c)
			y = c + 24 - a;
		else
			y = a - c;		// y = c - a; 감점
	}
	printf("%d시간 %d분 ", y, x);

	return 0;
}