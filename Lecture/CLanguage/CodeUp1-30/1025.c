//�ټ� �ڸ��� ���� 1���� �Է¹޾� �� �ڸ����� ������ ����Ѵ�.

#include<stdio.h>

int intPow(int base, int exponent);

int main_1025(void) {
	#pragma region ���1

	/*int a, b, c, d, e;
	scanf("%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e);

	printf("[%d]\n", a * 10000);
	printf("[%d]\n", b * 1000);
	printf("[%d]\n", c * 100);
	printf("[%d]\n", d * 10);
	printf("[%d]\n", e);*/

	#pragma endregion

	#pragma region ���2

	int n;
	scanf("%d", &n);

	// �Է¹��� ������ �ڸ��� �����ϱ�
	int n_clone = n;
	int n_length=0;
	while (n_clone > 10) {
		n_clone /= 10;
		//printf("n_clone = %d\n", n_clone);
		n_length++;
	}
	//printf("n_length = %d\n", n_length);

	// ���
	//printf("n=%d\n", n);
	int digit, p;
	for (int i = n_length; i >= 0; i--) {
		p = intPow(10, i);
		digit = n / p;			
		printf("[%d]\n", digit * p);
		n %= p;
	}

	#pragma endregion

	return 0;
}

int intPow(int base, int exponent) {
	int result = 1;

	for (int i = exponent; i > 0; i--) {
		result *= base;
	}

	return result;
}