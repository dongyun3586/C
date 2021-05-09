void printLine(int n) {
    for (int i = 0; i < n; i++)
        printf("-");
    printf("\n");
}

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}

// num이 소수인지 아닌지 판별하는 함수
int checkPrimeNumber(int n) {
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

