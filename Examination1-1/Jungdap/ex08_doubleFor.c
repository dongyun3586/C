#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	// ① 변수 선언 및 변수에 대한 주석(설명) [2점]
	int n, result = 1;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수 입력: ");
	scanf("%d", &n);

	// ③ 처리 [8점]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			result *= i;
	}

	// ④ 출력 [2점]
	printf("%d\n", result);

	return 0;
}