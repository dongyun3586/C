#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int NowHour, NowMinute, AlarmHour, AlarmMinute, TotNow, TotAlarm, TotRes, ResHour, ResMinute;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &NowHour, &NowMinute);
	printf("�˶� �ð�: ");
	scanf("%d %d", &AlarmHour, &AlarmMinute);

	// �� ó�� [8��]
	TotNow = 60 * NowHour + NowMinute;
	TotAlarm = 60 * AlarmHour + AlarmMinute;
	if (TotNow >= TotAlarm)
		TotRes = TotNow - TotAlarm;
	else
		TotRes = 1440 - (TotNow - TotAlarm);

	ResHour = TotRes / 60;
	ResMinute = TotRes % 60;

	// �� ��� [3��]
	printf("%d�ð� %d�� ", ResHour, ResMinute);

	return 0;
}