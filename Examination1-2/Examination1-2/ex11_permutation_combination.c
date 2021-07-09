#include<stdio.h>
int factorial(int n);
int permutation(int n, int r);
int main() {
	// ① 변수 선언 [2점]
	int n, r;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("n과 r 입력: ");
	scanf("%d %d", &n, &r);

	// ③ 결과 출력 [4점]
	printf("P(%d, %d) = %d \n", n, r, permutation(n, r));
	printf("C(%d, %d) = %d \n", n, r, permutation(n, r) / factorial(r));

	return 0;
}
// ④ factorial 함수 [4점]
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
// ⑤ permutation 함수 [3점]
int permutation(int n, int r) {
	return factorial(n) / factorial(n - r);
}