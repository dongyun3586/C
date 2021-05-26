#include<stdio.h>

int main() {
	int n, a = 0, b = 1, next;

#pragma region 지정된 개수만큼 피보나치 수열 출력
	printf("피보나치 수열 출력 개수는? ");
	scanf("%d", &n);

	// for문을 이용하여 피보나치 수열 출력
	for (int i = 0; i < n; i++) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n\n");
#pragma endregion

#pragma region 입력된 숫자보다 작은 피보나치 수열 모두 출력
	printf("양의 정수를 입력하시오: ");
	scanf("%d", &n);

	// while문을 사용하여 피보나치 수열 출력
	a = 0, b = 1;
	for (; ;) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}
	/*while (a <= n) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}*/

	printf("\n");
#pragma endregion

	return 0;
}