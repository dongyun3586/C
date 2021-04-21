#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a = 0, b = 1, next=1, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &n);

	// ③ 처리 및 출력 [8점]
	while (next <= n) {
		printf("%d ", next);
		b = next;
		a = b;
		next = a + b;
	}

#pragma region MyRegion
	//// ③ 처리 및 출력 [8점]
	//while (a <= n) {
	//	printf("%d ", a);
	//	next = a + b;
	//	a = b;
	//	b = next;
	//}
#pragma endregion


	return 0;
}