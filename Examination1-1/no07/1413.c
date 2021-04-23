#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int n, m, a, b, x, y, z;

	printf("현재 시간: ");
	scanf("%d %d", &n, &m);
	printf("알람 시간: ");
	scanf("%d %d", &a, &b);

	x = 60 * n + m;
	y = 60 * a + b;
	if (x > y) {
		y = 60 * a + b + 60 * 24;
		z = y - z;
		printf("%d시간 %d분 ", z/60, z%60);
	}
	if(x==y)
		printf("0시간 0분");
	if (x < y) {
		z = y - x;
		printf("%d시간 %d분 ", z / 60, z % 60);
	}

	return 0;
}