#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a = 0;
	int b = 1;
	int Data;
	int temp;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &Data);

	printf("\n"); // 감점

	// ③ 처리 및 출력 [8점]
	while (a < Data + 1) {
		printf("%d ", a);
		temp = a;
		a = b;
		b = b+temp;
	}

	return 0;
}