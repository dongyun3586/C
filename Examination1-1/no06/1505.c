#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, x = 0, y = 1, z;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);

	// ③ 처리 및 출력 [8점]
	for (z = 0; z < a; z = z + 1) {  // z 감점, <= 감점
		printf("%d ", x);
		z = x + y;
		x = y;
		y = z;
	}

#pragma region MyRegion
	//// ③ 처리 및 출력 [8점]
	//for (z = 0; x <= a; z = z + 1) {
	//	printf("%d ", x);
	//	z = x + y;
	//	x = y;
	//	y = z;
	//}
#pragma endregion


	return 0;
}