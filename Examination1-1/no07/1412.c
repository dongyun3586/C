#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int nh, nm, ah, am, fh, fm, x, y;

	printf("현재 시간: ");
	scanf("%d %d", &nh, &nm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	fh = ah + 24 - nh;
	fm = am + 60 - nm;
	if (fh >= 24)
		x = fh - 24;
	else
		x = x;
	if (fm >= 60)
		y = fm - 60;
	else
		x = x - 1;

	printf("%d시간 %d분 ", x, y);

	return 0;
}