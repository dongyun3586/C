#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int h, m, h2, m2, time, time2, t;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	// ③ 처리 [8점]
	time = 60 * h + m;
	time2 = 60 * h2 + m2;

	if (time2 >= time) {
		t = time2 - time;
		printf("%d시간 %d분 ", t/60, t%60);
	}
	else {
		t = time2 - time + 24;
		printf("%d시간 %d분 ", t / 60, t % 60);
	}

	// ④ 출력 [3점]

	return 0;
}