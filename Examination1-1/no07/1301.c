#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int nh, nm, ah, am, dh, dm;

	printf("현재 시간: ");
	scanf("%d %d", &nh, &nm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	dh = ah - nh;
	dm = am - nm;
	if (dm < 0) {
		dh--;
		dm += 60;
	}
	if (dh < 0)
		dh += 24;

	printf("%d시간 %d분 ", dh, dm);

	return 0;
}