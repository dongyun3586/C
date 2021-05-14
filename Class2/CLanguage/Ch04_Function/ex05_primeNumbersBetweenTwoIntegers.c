#include<stdio.h>

int checkPrimeNumber(int n);

int main() {
	int a, b, count = 0;

	printf("�Ҽ��� ���� ����(���� ����, a<=b)�� �Է��Ͻÿ�: ");
	scanf("%d %d", &a, &b);

	// a~b ������ �Ҽ� ��� ��� => �ݺ��� ���, �Ҽ��� ���� count++
	for (int i = a; i <= b; i++) {
		if (checkPrimeNumber(i)) {
			printf("%d ", i);
			count++;
		}
	}

	// a~b ������ �Ҽ��� ���� ��� => count ���� ���
	printf("\n%d~%d ������ �Ҽ��� %d ��\n", a, b, count);

	return 0;
}

// num�� �Ҽ����� �ƴ��� �Ǻ��ϴ� �Լ�
int checkPrimeNumber(int n) {
	if (n < 2) return 0;
	for (int i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}