#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num�� �ڸ��� n ���ϱ�
int checkArmstrongNumber(int num, int n);    // num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int reversNumber(int num);                   // num�� ���� ������ => 153 �� 351
void printArmstrongNumber(int num, int n);   // �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�
void printArmstrongNumber2(int num, int n);

int main() {
	int a = 1, b = 1000000, n;
	printf("1~1000000 ������ �Ͻ�Ʈ�ռ�\n\n");

	// a ~ b ������ �Ͻ�Ʈ�� �ѹ� ����ϱ�
	for (int i = a; i <= b; i++) {
		n = countDigitsOfNumber(i);		// log10(i) + 1;
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber(i, n);
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
	int temp = num, sum = 0;
	while (temp != 0) {
		sum += pow(temp % 10, n);
		temp /= 10;
	}
	return (sum == num) ? 1 : 0;
}

// num�� �� �ڸ� ���� ������
int reversNumber(int num) {
	int reversNum = 0, r;
	while (num != 0) {
		r = num % 10;
		num /= 10;
		reversNum = reversNum * 10 + r;
	}
	return reversNum;
}

void printArmstrongNumber(int num, int n) {
	printf("%7d = ", num);
	int rev = reversNumber(num);
	for (int i = 0; i < n; i++, rev /= 10) {
		printf("%d", (int)pow(rev % 10, n));
		if (i != n - 1)
			printf(" + ");
	}
	printf("\n");
}

// �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�
void printArmstrongNumber2(int num, int n) {
	printf("%7d = ", num);
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", (int)pow((num % (int)pow(10, i + 1.0) - num % (int)pow(10, i)) / (int)pow(10, i), n));
		if (i != 0)
			printf(" + ");
	}
	printf("\n");
}