#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b, c;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);
	b = 0;

	// ③ 처리 및 출력 [8점]
	printf("%d ", b);
	for (c = 1; c <= a; c = c + b) {
		printf("%d ", c);
		b = c;
	}

	return 0;
}