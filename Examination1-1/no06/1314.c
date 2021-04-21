#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a = 0, b = 1, c, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	scanf("%d", &n);

	// ③ 처리 및 출력 [8점]
	printf("%d %d ", a, b);
	for (int i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
		printf("%d ", c);
	}

	return 0;
}