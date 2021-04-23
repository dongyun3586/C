#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int h1, h2, m1, m2, h, m;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &h1, &m1);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	// ③ 처리 [8점]
	m = m2 - m1;
	if (m < 0)
		m += 60, h2--;
	h = h2 - h1;
	if (h < 0)
		h += 24;

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", h, m);

	return 0;
}