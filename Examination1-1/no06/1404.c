#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, t;
	int b = 0;
	int c = 1;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);

	// ③ 처리 및 출력 [8점]
	printf("%d ", b);
	while (c <= a) {
		t = c;
		c = b + c;
		b = t;
		printf("%d ", b);
	}

	return 0;
}