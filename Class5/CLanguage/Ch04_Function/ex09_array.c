#include<stdio.h>

int main() {
	char ch;
	int num;
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

	printf("%d\n", sizeof(ch));		// 1
	printf("%d\n", sizeof(num));	// 4

	printf("%d\n", sizeof(char));	// 1
	printf("%d\n", sizeof(int));	// 4
	printf("%d\n", sizeof(float));	// 4
	printf("%d\n", sizeof(double));	// 8

	printf("%d\n", sizeof(numArr[0]));              // �迭 ��� �ϳ��� ũ��(byte)
	printf("%d\n", sizeof(numArr));                 // �迭�� ũ��(byte)
	printf("%d\n", sizeof(numArr) / sizeof(int));   // �迭�� ��� ����

	return 0;
}