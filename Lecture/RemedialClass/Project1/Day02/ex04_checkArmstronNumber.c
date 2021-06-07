#include<stdio.h>
#include<math.h>                             // double pow( double base, double exponent );

int countDigitsOfNumber(int num);            // num�� �ڸ��� n ���ϱ�
int checkArmstrongNumber(int num, int n);    // num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int reversNumber(int num);                   // num�� ���� ������ => 153 �� 351
void printArmstrongNumber(int num, int n);   // �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�

int main() {
	int a = 1, b = 1000000, n;
	printf("1~1000000 ������ �Ͻ�Ʈ�ռ�\n\n");

	// a ~ b ������ �Ͻ�Ʈ�� �ѹ� ����ϱ�
	for (int i = a; i <= b; i++) {
		n = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, n)) {
			printArmstrongNumber(i, n);
		}
	}
	return 0;
}

// num�� �ڸ��� n ���ϱ�
int countDigitsOfNumber(int num) {
	return log10(num) + 1;
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

}

// �� �ڸ��� n������ ���ڵ��� ���� ���·� ����ϱ�
void printArmstrongNumber(int num, int n) {
	printf("%7d = ", num);
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", (int)pow((num % (int)pow(10, i + 1) - num % (int)pow(10, i)) / (int)pow(10, i), n));
		if (i != 0)
			printf(" + ");
	}
	printf("\n");
}