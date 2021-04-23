#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, n;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	n/* = a * 60 + b - c * 60 - d;
	if (n >= 0) {
		p = n / 60;
		q = n % 60;
	}
	else {
		n = -n;
		p = n / 60;
		q = n % 60;
	}*/

	printf("%d시간 %d분 ", p,q);

	return 0;
}