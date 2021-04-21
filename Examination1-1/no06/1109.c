#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int n, t, a = 0, b = 1, next;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &n);

	// ③ 처리 및 출력 [8점]
	printf("%d %d ", a, b);
	while (1) {
		if (next > n)
			break;
		else {
			printf("%d ", next);
			t = next;
			next = next + b;
			b = t;
		}
	}

	return 0;
}