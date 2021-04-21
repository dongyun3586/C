#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b, t, num;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &num);
	a = 0; b = 1;

	// ③ 처리 및 출력 [8점]
	printf("0 1 ");
	while (1) {
		t = a + b;
		if (t > num)
			break;
		printf("%d ", t);
		b = a;
		a = t;
	}

	return 0;
}