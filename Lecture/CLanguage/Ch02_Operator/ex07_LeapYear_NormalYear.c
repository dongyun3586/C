#include<stdio.h>

int main() {
	int year, result;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &year);

	/* ���� ��Ģ(�׷�����)
	  - ������ 4�� ������ ��������.
	  - 100���� ������ �������� ������ �����Ѵ�.
	  - 400���� ������ �������� ������ �����̴�. */
	
	// 1. result�� �����̸� 1(True), ����̸� 0(False)�� �����Ѵ�.
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	printf("result = %d \n", result);

	return 0;
}