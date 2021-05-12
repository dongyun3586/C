#include<stdio.h>

int checkPrimeNumber(int);

int main_ex03_primeNumbersBetweenTwoIntegers() {
	int a, b, count = 0;

	printf("�Ҽ��� ���� ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &a, &b);

	// a~b ������ �Ҽ� ��� ���
	for (int i = a; i <= b; i++) {
		if (checkPrimeNumber(i)) {
			printf("%d ", i);
			count++;
		}
	}

	// a~b ������ �Ҽ��� ���� ���
	printf("\n\n%d~%d ������ �Ҽ�: %d��\n", a, b, count);

	return 0;
}

// num�� �Ҽ����� �ƴ��� �Ǻ��ϴ� �Լ�
int checkPrimeNumber(int n) {
	for (int i = 2; i <= n/2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}