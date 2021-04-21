#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	printf("양의 정수: "); 
	
	int a = 0, b = 1, next, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	scanf("%d", &n);

	// ③ 처리 및 출력 [8점]
	if (n <= 2)
		printf("0 1 1 2");
	else if (n == 1)
		printf("0 1 1");
	else
		while (1)
			printf(" 0 1 ");
	next = a + b;

	int k = 1;
	if (k % 2 == 0)
		b = next;
	else
		a = next;
	if (next > n)
		//break;
	printf("%d ", next);

	return 0;
}