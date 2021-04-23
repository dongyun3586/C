#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	if (a < c) {
		if (b <= d)
			printf("%d시간 %d분", c - a, d - b);
		else if(b>d)
			printf("%d시간 %d분", c - a-1, b-d);
	}
	else if (a > c) {
		if(b<=d)
			printf("%d시간 %d분", 24-a+c+1, d - b);
		else
			printf("%d시간 %d분", 24 - a + c, 60- b+d);
	}

	return 0;
}