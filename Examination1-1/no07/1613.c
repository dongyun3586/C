#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h1, h2, m1, m2, a, b, t, h, m;

	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	a = h1 * 60 + m1;	// 현재시간 분으로 환산
	b = h2 * 60 + m2;	// 알람시간 분으로 환산

	if (b >= a)			// 알람 환산값이 크면
		t = b - a;		// 차이 t = 알람 - 현재
	else {
		a = 1440 - a;	// 알람분 = 24시간분 - 알람분
		t = a + b;
	}
	h = t / 60;
	m = t % 60;
	printf("%d시간 %d분 ", h, m);

	return 0;
}