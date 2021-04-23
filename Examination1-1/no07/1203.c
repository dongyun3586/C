#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int ch, cm, ah, am;

	printf("현재 시간: ");
	scanf("%d %d", &ch, &cm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	if (am < cm) {
		am = 60 + am;
		ah--;
	}
	if (ah < ch)
		ah = ah + 24;

	printf("%d시간 %d분 ", ah-ch, am-cm);

	return 0;
}