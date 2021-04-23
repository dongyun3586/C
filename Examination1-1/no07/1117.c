#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int hhour, hminute, ahour, aminute, dhour, dminute;

	printf("현재 시간: ");
	scanf("%d %d", &hhour, &hminute);
	printf("알람 시간: ");
	scanf("%d %d", &ahour, &aminute);

	if (hhour > ahour) {
		dhour = ahour + 24 - hhour;
		if (hminute > aminute)
			aminute = aminute + 60 - hminute;
		else
			dminute = aminute - hminute;
	}
	else
		dhour = ahour - hhour;
	if (hminute > aminute)
		dminute = aminute + 60 - hminute;
	else
		aminute = aminute - hminute;
	printf("%d시간 %d분 ", dhour, dminute);

	return 0;
}