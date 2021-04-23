#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int nh, nm, ah, am;

	printf("현재 시간: ");
	scanf("%d %d", &nh, &nm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	if(nh>=ah||nm>=am)
		printf("%d시간 %d분 ", nh-ah, nm-am);
	if (nh >= ah || nm < am)
		printf("%d시간 %d분 ", nh - ah, am-nm);
	if (nh < ah || nm >= am)
		printf("%d시간 %d분 ", ah - nh, nm - am);
	else
		printf("%d시간 %d분 ", ah - nh, am - nm);

	return 0;
}