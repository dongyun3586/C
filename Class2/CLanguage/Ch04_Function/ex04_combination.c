#include<stdio.h>

int factorial(int n);
int combination(int n, int r);

int main() {
	int n, r;

	printf("������ ����� n�� r�� �Է��Ͻÿ�: ");
	scanf("%d %d", &n, &r);

	// 1. ��� ���

	return 0;
}

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}

int combination(int n, int r) {
	// 2. C(n, r)�� ��� ����
}