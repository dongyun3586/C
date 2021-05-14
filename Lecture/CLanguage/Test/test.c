#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)	// scanf ��� ����

int countDigitsOfNumber(int num);
int checkArmstrongNumber(int num, int n);
int reversNumber(int num);
void printArmstrongNumber1(int num, int n);
void printArmstrongNumber2(int num, int n);

int main() {
	int a, b, digits;

	printf("�Ͻ�Ʈ�� ���� ����(���� ���� �� ��): ");
	scanf("%d %d", &a, &b);

	// a ~ b ������ �Ͻ�Ʈ�� �ѹ� ����ϱ�
	for (int i = a; i <= b; i++) {
		digits = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, digits)) {
			printArmstrongNumber1(i, digits);
			printArmstrongNumber2(i, digits);
		}
	}
	return 0;
}

// num�� �ڸ��� n ���ϱ�
int countDigitsOfNumber(int num) {
	int n = 0;
	while (num != 0) {
		num /= 10;
		n++;
	}
	return n;
}

// num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int checkArmstrongNumber(int num, int n) {
	int sum = 0, originalNum, remainder;

	// num�� �ڸ����� n ������ �� sum ���ϱ�
	for (originalNum = num; originalNum != 0; originalNum /= 10) {
		remainder = originalNum % 10;
		sum += (int)pow(remainder % 10, n);
	}

	// �Ͻ�Ʈ�� �ѹ� ���� ����
	return (sum == num) ? 1 : 0;
}

// num�� �� �ڸ� ���� ������
int reversNumber(int num) {
	int rev = 0, remainder;

	while (num != 0) {
		remainder = num % 10;
		rev = rev * 10 + remainder;
		num /= 10;
	}
	return rev;
}

// abc = a*a*a + b*b*b + c*c*c�� ���·� ����ϱ�
void printArmstrongNumber1(int num, int n) {
	printf("%7d = ", num);
	num = reversNumber(num);
	while (num != 0) {
		printf("%d ", (int)pow(num % 10, n));
		num /= 10;
		if (num != 0) printf("+ ");
	}
	printf("\n");
}

void printArmstrongNumber2(int num, int n) {
	printf("%7d = ", num);
	for (int i = n-1; i >= 0; i--) {
		printf("%d ", (int)pow((num % (int)pow(10, i+1) - num % (int)pow(10, i)) / (int)pow(10, i), n));
		if (i != 0) printf("+ ");
	}
	printf("\n");
}

