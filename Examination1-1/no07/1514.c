#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int NowHour, NowMinute, AlarmHour, AlarmMinute, TotNow, TotAlarm, TotRes, ResHour, ResMinute;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &NowHour, &NowMinute);
	printf("알람 시간: ");
	scanf("%d %d", &AlarmHour, &AlarmMinute);

	// ③ 처리 [8점]
	TotNow = 60 * NowHour + NowMinute;
	TotAlarm = 60 * AlarmHour + AlarmMinute;
	if (TotNow >= TotAlarm)
		TotRes = TotNow - TotAlarm;
	else
		TotRes = 1440 - (TotNow - TotAlarm);

	ResHour = TotRes / 60;
	ResMinute = TotRes % 60;

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", ResHour, ResMinute);

	return 0;
}