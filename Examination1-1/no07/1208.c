#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int hour, min, alhour, almin, lefthour, leftmin;

	printf("현재 시간: ");
	scanf("%d %d", &hour, &min);
	printf("알람 시간: ");
	scanf("%d %d", &alhour, &almin);

	lefthour = alhour - hour;
	leftmin = almin - min;
	if (lefthour < 0)
		lefthour += 23;
	if (leftmin < 0)
		leftmin += 60;
	printf("\n%d시간 %d분 ", lefthour, leftmin);

	return 0;
}