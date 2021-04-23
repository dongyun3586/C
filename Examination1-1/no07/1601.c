#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	// ①) 변수 선언 [2점]
	int a, b, c, d, t1, t2, t;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("알람 시간: ");
	scanf("%d %d", &c, &d);

	// ③ 처리 [8점]
	t1 = 60 * a + b;
	t2 = 60 * c + d;
	t = t2 - t1;

	// ④ 출력 [3점]
	if(t>=0)
		printf("%d시간 %d분 ", t/60, t%60);
	else {
		t += 1440;
		printf("%d시간 %d분 ", t / 60, t % 60);
	}

	return 0;
}