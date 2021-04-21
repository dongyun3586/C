#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a1 = 0, a2 = 1, a3 = 1, t, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &n);

	// ③ 처리 및 출력 [8점]
	while (t <= n) {
		printf("%d ", a1);
		t = a3;
		a3 = a1 + a2;
		a1 = a2;
		a2 = t;
	}

#pragma region MyRegion
		//// ① 변수 선언 [2점]
		//int a1 = 0, a2 = 1, a3 = 1, t, n;

		//// ② 입력 정보 안내 및 입력 받기 [2점]
		//printf("양의 정수: ");
		//scanf("%d", &n);

		//// ③ 처리 및 출력 [8점]
		//while (a1 <= n) {			// 감점1
		//	printf("%d ", a1);

		//	a3 = a1 + a2;
		//	t = a3;					// 감정2
		//	a1 = a2;
		//	a2 = t;
		//}
#pragma endregion


	return 0;
}









