#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int ch, cm, ah, am, h, m;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &ch, &cm);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	// ③ 처리 [8점]
	if (ah < ch)
		h = ah + 24 - ch;
	else
		h = ah - ch;
	if (am < cm) {
		m = am + 60 - cm;
		h--;
		if (h < 0) h += 24;
	}
	else
		m = am - cm;

	// ④ 출력 [3점]
	printf("%d시간 %d분 ", h, m);

	return 0;
}