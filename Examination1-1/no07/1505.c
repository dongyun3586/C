#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int a, b, c, d;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	// ③ 처리 [8점]
	if (c > a && d > b)
		printf("%d시간 %d분 ", c - a, d - b);
	else if (c > a && d < b)
		printf("%d시간 %d분 ", c - a - 1, 60 - d + b);
	else if (c < a && d < b)
		printf("%d시간 %d분 ", 24-c+a, d - b);
	else
		printf("%d시간 %d분 ", 24 - c + a-1, 60-d + b);

	// ④ 출력 [3점]

	return 0;
}