#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b, c, now;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &c);

	a = 0;
	b = 1;

	do {
		printf("%d ", a);
	} while (a < c);

	// ③ 처리 및 출력 [8점]
	
	while (b < n) {
		printf("%d ", b);
		next = a + b;
		a = b;
		b = next;
	}

	return 0;
}