#include<stdio.h>

int main() {
	int year;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &year);

	/* ���� ��Ģ(�׷�����)
	  - ������ 4�� ������ ��������.
	  - 100���� ������ �������� ������ �����Ѵ�.
	  - 400���� ������ �������� ������ �����̴�. */
	
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d���� �����Դϴ�. \n", year);
	else
		printf("%d���� ����Դϴ�. \n", year);

	main_ex01_operator();
	main_ex06_operator();

	return 0;
}