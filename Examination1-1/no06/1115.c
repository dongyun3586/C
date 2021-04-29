#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b, c = 0, d = 1;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);

	// ③ 처리 및 출력 [8점]
	printf("0 1 ");
	while (b<=a) {
		b = c + d;
		c = d;
		d = b;
		printf("%d ", b);
		}
	}

	return 0;
}