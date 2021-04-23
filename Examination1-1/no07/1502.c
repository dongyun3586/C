#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int hour, min, ahour, amin, phour, pmin;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &hour, &min);
	printf("\n");						// 감점 -1
	printf("알람 시간: ");
	scanf("%d %d", &ahour, &amin);
	printf("\n");						// 감점 -1

	// ③ 처리 [8점]
	if (hour > ahour) {
		phour = hour - ahour + 24;
	}
	else {
		phour = hour - ahour;
	}

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", phour, pmin);

	return 0;
}