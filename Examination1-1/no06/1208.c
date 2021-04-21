#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int max = 0, a = 0, b = 1, next = 0;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &max);

	// ③ 처리 및 출력 [8점]
	printf("\n");
	while (1) {
		next = a + b;
		a = b;
		b = next;

		if (b > max)
			break;
		else
			printf("%d ", b);
	}

	return 0;
}