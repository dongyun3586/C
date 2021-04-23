#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, t;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (c >= a) {
		if(d>b)
			printf("%d시간 %d분 ", c - a, d - b);
		else
			printf("%d시간 %d분 ", c - a, d - b+60);
	}
	else {
		if (d > b)
			printf("%d시간 %d분 ", c - a+24, d - b);
		else
			printf("%d시간 %d분 ", c - a+24, d - b + 60);
	}
	

	return 0;
}