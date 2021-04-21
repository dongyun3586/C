#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int a, b, c, d, e, f;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a > 12 && b > d) {
		e = 24 - a - 1 + c;
		f = b - d;
		printf("%d시간 %d분", e, f);
	}
	else if (a > 12 && b < d) {
		e = 24 - a + c;
		f = d - b;
		printf("%d시간 %d분", e, f);
	}
	else if (a < 12 && b < d) {
		e = c - a;
		f = b - d;
		printf("%d시간 %d분", e, f);
	}
	else if (a<12 && b>d) {
		e = c - a - 1;
		f = d - b;
		printf("%d시간 %d분", e, f);
	}


	return 0;
}