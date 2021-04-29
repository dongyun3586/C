#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int a, b, c, d, e, f;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("현재 시간: %d %d", a, b);
	printf("알람 시간: %d %d", c, d);

	// ③ 처리 [8점]
	if (a > c)
		e = 24 - a + c;
	else
		e = c - a;

	if (b > d) {
		f = 60 - b + d;
		e--;
		//if (e < 0) e += 24; <- 감점
	}
	else
		f = d - b;

	printf("%d시간 %d분 ", e, f);

	return 0;
}