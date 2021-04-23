#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h1, m1, h2, m2;

	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	if (h1 < h2) {
		if (m1 < m2)
			printf("%d시간 %d분 ", h2 - h1, m2 - m1);
		else
			printf("%d시간 %d분 ", h2 - h1 - 1, m2 + 60 - m1);
	}
	else {
		if (m1 < m2)
			printf("%d시간 %d분 ", h2 +24-h1, m2 - m1);
		else
			printf("%d시간 %d분 ", h2 - h1 +23, m1-m2);
	}
	

	return 0;
}