// (��������2) ������ ���밪 ����ϱ� (ex02_if.c)

#include<stdio.h>

int main_ex02_if() {
	int n;
	printf("���� �Է�: ");
	scanf("%d", &n);

	// ������ ����� ��ȯ
	if (n < 0)
		n = -n;

	printf("���밪�� %d \n", n);

	return 0;
}