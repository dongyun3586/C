#include<stdio.h>
int factorial(int n);
int permutation(int n, int r);
int main() {
	// ① 변수 선언 [2점]
	int a, b, c, d, e;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("n과 r 입력: ");
	scanf("%d %d", &a, &b);

	// ③ 결과 출력 [4점]
	c = factorial(a);
	d = factorial(b);
	printf("P(%d, %d) = %d \n", a, b, permutation(a, b));
	printf("C(%d, %d) = %d \n", a, b, permutation(a, b) / d);

	return 0;
}
// ④ factorial 함수 [4점]
int factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
// ⑤ permutation 함수 [3점]
int permutation(int n, int r) {
	int k = n - r;
	return factorial(n) / factorial(k);
}