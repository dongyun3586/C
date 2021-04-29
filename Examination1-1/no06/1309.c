#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, b, next, num;
	a = 0;
	b = 1;
	next = 1;

	printf("양의 정수: ");
	scanf("%d", &num);
	printf("%d %d ", a, b);

	while (1) {
		a = b;
		b = next;
		next = a + b;
		if (next > num)
			break;
		printf("%d ", next);
	}

	return 0;
}