// (��������2) ������ ���밪 ����ϱ� (ex02_if.c)
#include<stdio.h>

int main_ex02_if() {
	int n;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &n);

	// if��
	if (n < 0)
		n = -n;

	printf("���밪�� %d �Դϴ�. \n", n);

	return 0;
}