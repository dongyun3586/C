#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b = 0, c = 1, d = 1;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);

	// ③ 처리 및 출력 [8점]
	while (b<a&&c<a) {
		if (d == 1) {
			printf("%d ", b);
			b = b + c;
			d = 2;
		}
		if (d == 2) {
			printf("%d ", c);
			c = b + c;
			d = 1;
		}
	}

	return 0;
}