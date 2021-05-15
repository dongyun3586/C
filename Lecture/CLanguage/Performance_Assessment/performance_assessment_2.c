#include<stdio.h>
#include<math.h>	

int countDigitsOfNumber(int num);
int checkArmstrongNumber(int num, int n);
int reversNumber(int num);
void printArmstrongNumber(int num, int n);

int main() {
	int a = 1, b = 1000000, digits, count = 0;
	printf("*** 1�г� 1�� 20�� ȫ�浿 ***\n");
	printf("*** 1~1000000 ������ �Ͻ�Ʈ�ռ� ***\n");

	for (int i = a; i <= b; i++) {
		digits = countDigitsOfNumber(i);
		if (checkArmstrongNumber(i, digits)) {
			printArmstrongNumber(i, digits);
			count++;
		}
	}

	printf("\n%d~%d ������ �Ͻ�Ʈ�ռ��� %d ��\n", a, b, count);
	return 0;
}

// num�� �ڸ��� n ���ϱ�
int countDigitsOfNumber(int num) {
	/*int n = 0;
	while (num != 0) {
		num /= 10;
		n++;
	}
	return n;*/
	return log10(num) + 1;
}

// num�� �Ͻ�Ʈ�� �ѹ����� üũ(������ 1, Ʋ���� 0 ��ȯ)
int checkArmstrongNumber(int num, int n) {
	int sum = 0, originalNum, remainder;

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
void printArmstrongNumber(int num, int n) {
	printf("%6d = ", num);
	num = reversNumber(num);
	while (num != 0) {
		printf("%d ", (int)pow(num % 10, n));
		num /= 10;
		if (num != 0) printf("+ ");
	}
	printf("\n");
}

