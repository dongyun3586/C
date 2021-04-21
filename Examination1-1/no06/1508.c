#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b = 1, c = 0;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	scanf("%d", &a);

	// ③ 처리 및 출력 [8점]
	while (b<=a) {
		printf("%d ", c);
		c = b + c;
		b = c + b;
		printf("%d ", b);
	}

	return 0;
}