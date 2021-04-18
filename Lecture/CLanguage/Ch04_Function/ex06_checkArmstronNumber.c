#include<stdio.h>
#include<math.h>

int checkArmstrongNumber(int);
int reversNumber(int);
void printArmstrongNumber(int);

int main() {
	int a, b;

	printf("�Ͻ�Ʈ�� ���� ����(���� ���� �� ��): ");
	scanf("%d %d", &a, &b);

	// a~b ������ �Ͻ�Ʈ�� �ѹ� ����ϱ�
	for (int i = a; i <= b; i++) {
		if (checkArmstrongNumber(i)) {
			printf("%5d = ", i);
			printArmstrongNumber(reversNumber(i));
		}
	}
	return 0;
}

// num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int checkArmstrongNumber(int num) {
	int sum = 0, originalNum, n = 0, remainder;

	// num�� �ڸ��� n ���ϱ�
	for (originalNum = num; originalNum != 0; n++) {
		originalNum /= 10;
	}

	// num�� �ڸ����� n ������ �� sum ���ϱ�
	for (originalNum = num; originalNum != 0; originalNum /= 10) {
		remainder = originalNum % 10;
		sum += pow(remainder % 10, n);
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
void printArmstrongNumber(int num) {
	while (num != 0) {
		printf("%d ", (int)pow(num % 10, 3));
		num /= 10;
		if (num != 0) printf("+ ");
	}
	printf("\n");
}

