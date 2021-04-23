#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int time, hour, m, n;

	printf("현재 시간: ");
	scanf("%d %d", &hour, &time);
	printf("알람 시간: ");
	scanf("%d %d", &m, &n);

	if(m>=hour, n>=time)
		printf("%d시간 %d분 ", m-hour, n-time);

	return 0;
}