#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h, m, a, b;

	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &a, &b);

	if (h > a) {
		if(m>b)
			printf("%d시간 %d분 ", h-a, m-b);
		else
			printf("%d시간 %d분 ", h - a-1, m - b+60);
	}
	else {
		if(m>b)
			printf("%d시간 %d분 ", h - a+24, m - b);
		else
			printf("%d시간 %d분 ", h - a +23, m - b + 60);
	}
	

	return 0;
}