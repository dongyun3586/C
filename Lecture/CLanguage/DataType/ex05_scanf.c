#include <stdio.h>

int main_ex05_scanf()
{
	int x, y, sum;

	printf("���� �� ���� �Է��Ͻÿ�: ");
	scanf_s("%d %d", &x, &y);

	sum = x + y;
	printf("�� ���� ��: %d", sum);

	return 0;
}