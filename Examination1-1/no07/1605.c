#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int nowh, nowm, alarmh, alarmm, a, b, timeh, timem, c, d;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &nowh, &nowm);
	printf("알람 시간: ");
	scanf("%d %d", &alarmh, &alarmm);

	a = 60 * nowh + nowm;		// a: 현재시간 분으로 환산한 값
	b = 60 * alarmh + alarmm;	// b: 알람시간 분으로 환산한 값

	if (a > b) {
		c = 1440 - a;
		d = b + c;
		timeh = d / 60;
		timem = d % 60;
	}
	else {
		d = b - a;
		timeh = d / 60;
		timem = d % 60;
	}

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", timeh, timem);

	return 0;
}