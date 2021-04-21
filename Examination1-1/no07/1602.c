#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int h1, h2, h, min1, min2, min;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &h1, &h2);
	printf("알람 시간: ");
	scanf("%d %d", &min1, &min2);

	// ③ 처리 [8점]
	if ((h2-h1) < 0)
		if ((min2 - min1) < 0) {
			min = min2 - min1 + 60;
			h = h2 - h1 + 23;
		}
		else {
			min = min2 - min1;
			h = h2 - h1 + 24;
		}
	else {
		if ((min2 - min1) < 0) {
			min = min2 - min1 + 60;
			h = h2 - h1 - 1;
		}
		else {
			min = min2 - min1;
			h = h2 - h1;
		}
	}

	printf("%d 시간 %d 분", h, min);
	

	return 0;
}