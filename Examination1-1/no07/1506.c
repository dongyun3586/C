#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int a, b, c, d, m, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	// ③ 처리 [8점]
	if (a > c)
		c = c + 24;
	if (b > d) {
		n = 60 + d - b;
		c--;
	}

	m = c - a;
		

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", m, n);

	return 0;
}