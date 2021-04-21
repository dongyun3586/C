#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a = 0, b = 1, c=0, x;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &x);

	// ③ 처리 및 출력 [8점]
	while (c <= x) {
		printf("%d ", c);
		c = a + b;
		a = b;
		b = c;
	}

#pragma region MyRegion
	//// ③ 처리 및 출력 [8점]
	//while (a <= x) {
	//	printf("%d ", a);
	//	c = a + b;
	//	a = b;
	//	b = c;
	//}
#pragma endregion


	return 0;
}