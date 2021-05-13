#include<stdio.h>

int checkPrimeNumber(int n);

int main() {
	int a, b, count = 0;

	printf("소수를 구할 범위(양의 정수, a<=b)를 입력하시오: ");
	scanf("%d %d", &a, &b);

	// a~b 사이의 소수 모두 출력 => 반복문 사용, 소수의 개수 count++

  // a~b 사이의 소수의 개수 출력 => count 변수 출력

	return 0;
}

// num이 소수인지 아닌지 판별하는 함수
int checkPrimeNumber(int n) {
	if (n < 2) return 0;
	for (int i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}