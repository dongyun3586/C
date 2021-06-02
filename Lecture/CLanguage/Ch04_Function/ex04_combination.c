#include<stdio.h>

int factorial(int n);
int combination(int n, int r);

int main_ex04_combination() {
	int n, r;

	printf("������ ����� n�� r�� �Է��Ͻÿ�: ");
	scanf("%d %d", &n, &r);

	printf("C(%d, %d) = %d \n", n, r, combination(n, r));

	return 0;
}

int combination(int n, int r) {
	return factorial(n) / (factorial(n - r) * factorial(r));
}

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}