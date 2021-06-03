#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num�� �ڸ��� n ���ϱ�
int checkArmstrongNumber(int num, int n);    // num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int reversNumber(int num);                   // num�� ���� ������ => 153 �� 351
void printArmstrongNumber1(int num, int n);
void printArmstrongNumber2(int num, int n);   // �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�

int main() {
	int a = 1, b = 10000000, n;
	printf("1~1000000 ������ �Ͻ�Ʈ�ռ�\n\n");

	// a ~ b ������ �Ͻ�Ʈ�� �ѹ� ����ϱ�
	for (int i = a; i <= b; i++) {
		n = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber1(i, n);
			printArmstrongNumber2(i, n);
		}
	}
	return 0;
}

// num�� �ڸ��� n ���ϱ�
int countDigitsOfNumber(int num) {
	return (int)log10(num) + 1;
}

// num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int checkArmstrongNumber(int num, int n) {
	int originalNum, sum = 0;
	for (originalNum = num; originalNum != 0; originalNum /= 10)
		sum += pow(originalNum % 10, n);

	return (sum == num) ? 1 : 0;
}

// num�� �� �ڸ� ���� ������
int reversNumber(int num) {
	int reversNum = 0, remainder;
	for (; num != 0; num /= 10) {
		remainder = num % 10;
		reversNum = reversNum * 10 + remainder;
	}
	return reversNum;
}

// abc = a*a*a + b*b*b + c*c*c�� ���·� ����ϱ�
void printArmstrongNumber1(int num, int n) {
	printf("%7d = ", num);
	num = reversNumber(num);

	for (int i = 0; i < n; i++) {
		printf("%d ", (int)pow(num % 10, n));
		num /= 10;
		if (i < n - 1) printf("+ ");
	}
	printf("\n");
}

// �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�
void printArmstrongNumber2(int num, int n) {
	printf("%7d = ", num);
	int d;
	for (int i = n - 1; i >= 0; i--) {
		d = ((num % (int)pow(10, i + 1.0)) - (num % (int)pow(10, i))) / (int)pow(10, i);
		printf("%d", (int)pow(d, n));
		if (i != 0)
			printf(" + ");
	}
	printf("\n");
}