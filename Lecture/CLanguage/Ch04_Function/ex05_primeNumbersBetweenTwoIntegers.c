#include<stdio.h>

int checkPrimeNumber(int);

int main_ex03_primeNumbersBetweenTwoIntegers() {
	int a, b, count = 0;

	printf("소수를 구할 범위를 입력하시오: ");
	scanf("%d %d", &a, &b);

	// a~b 사이의 소수 모두 출력
	for (int i = a; i <= b; i++) {
		if (checkPrimeNumber(i)) {
			printf("%d ", i);
			count++;
		}
	}

	// a~b 사이의 소수의 개수 출력
	printf("\n\n%d~%d 사이의 소수: %d개\n", a, b, count);

	return 0;
}

// num이 소수인지 아닌지 판별하는 함수
int checkPrimeNumber(int n) {
	for (int i = 2; i <= n/2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}