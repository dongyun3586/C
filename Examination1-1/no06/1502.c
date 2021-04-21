#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int num, sum = 0, temp;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &num);

	// ③ 처리 및 출력 [8점]
	for (int i = 0; i < num; i = temp) {
		while (sum <= num) {
			temp = sum;
			sum = sum + i;
			printf("%d", sum);
		}
	}

	return 0;
}