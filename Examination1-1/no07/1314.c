#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int time, min, a, b;

	scanf("%d %d", &time, &min, &a,&b);

	int h, c;
	if (a > time)
		h = a - time;
	else
		h = a - time + 24;

	if (b > min)
		c = b - min;
	else {
		c = b - min + 60;
		h -= 1;
	}
		
	printf("%d시간 %d분 %d %d", time,min,a,b);

	return 0;
}